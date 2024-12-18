module udp (
  input  logic        clk,
  output  logic        reset,
  input  logic        r_valid,
  output logic        r_ready,
  input  logic [15:0] r_data,
  input  logic        r_last,
  input  logic        r_keep, // not used currently
  output logic        t_valid,
  input  logic        t_ready,
  output logic [15:0] t_data,
  output logic        t_last,
  output logic [15:0] buffer [3:0],
  output logic [1:0]  r_offset,
  output logic [1:0]  t_offset,
  output logic        t_ready_stall
);

    localparam [1:0] DATA_WIDTH = 2'd3;

    // Using logic types
    // logic [15:0] buffer [3:0];
    // logic [1:0]  r_offset;
    // logic [1:0]  t_offset;

    initial begin
        t_valid  = 1'b0;
        t_last   = 1'b0;
        r_offset = 2'h0;
        t_offset = 2'h0;
        t_ready_stall = 1'b0;
    end

    always_ff @(posedge clk) begin
      if (reset) begin
        t_valid <= 1'b0;
        t_last   <= 1'b0;
        r_offset <= 2'h0;
        t_offset <= 2'h0;
        reset <= 1'b0;
        buffer <= {16'h0, 16'h0, 16'h0, 16'h0};
      end
    end

    always_ff @(posedge clk) begin
      t_ready_stall <= t_ready;
    end

    // Control r_ready
    always_ff @(posedge clk) begin
      if (r_offset < DATA_WIDTH + 1 && r_valid) begin
        r_ready <= 1'b1;
      end
      else begin
        r_ready <= 1'b0;
      end
    end

    // Control t_last
    // always_ff @(posedge clk) begin
    //   if ((t_offset == DATA_WIDTH - 1) && t_ready) begin
    //      t_last <= 1'b1;
    //   end
    // end

    // Capture incoming data into buffer
    // Shift the buffer and insert new data at buffer[0]
    always_ff @(posedge clk) begin
       if (r_ready && r_valid) begin
        buffer <= {r_data, buffer[3:1]};
        if (!r_last) begin
          r_offset <= r_offset + 1;
        end
      end
    end

    always_ff @(posedge clk) begin
      if (t_valid && t_ready) begin
        t_data <= buffer[t_offset];
        if (!t_last) begin
          t_offset <= t_offset + 1;
        end
      end
    end

    // Transfer data from buffer to output
    always_ff @(posedge clk) begin
      if (t_valid && t_ready_stall) begin
        t_valid <= 1'b0;
      end
    end

    // Control t_valid and transition after last data
    always_ff @(posedge clk) begin
      if ((t_offset <= r_offset) && r_last && !r_valid && !t_ready_stall && !t_last && !t_valid && (r_offset > 0)) begin
        t_valid <= 1'b1;
        if (t_offset == r_offset) begin
          t_last <= 1'b1;
        end
      end
    end

/********************  Assertion Defininition  ********************/
`ifdef ABV_ON

property my_property;
  @(posedge clk) r_valid |-> ##1 r_ready; // If 'a' is true at one clock, then 'b' must be true one cycle later
endproperty

assert property(my_property) else $fatal("Assertion failed: Condition not met.");

// always @* begin
//   // ASSUMPTIONS
//   data_bus_valid: assume(r_valid = 1);
  
//   // ASSERTIONS
//   output_never_error: assert(out_d == out + 1);

//   // COVERS
//   data_bus_nonzero: cover(data_bus != '0); 
// end


`endif // ABV_ON


endmodule


/* 
Process Description (After each step formally verify):
1. Create a AXI-stream components
  a. Receive a set of data
  b. Forward this data back to the host using output wires
2. Parse a UDP packet by 1 bit at a time to construct its array for src, dst, len, and checksum
3. Parse an array of protocol being either TCP or UDP
4. Parse an IPv4 packet and set a bool to true or false dependent on TCP or UDP
5. Parse an IPv4 and UDP packet conditionally
6. Parse an ethernet packet 
7. Parse full pipeline



Protocol Designs:
Ethernet: 14 Bytes
 - Destination MAC address (6 bytes)
 - Source MAC address (6 bytes)
 - EtherType/Length field (2 bytes)

IPv4: 20 Bytes
 - Version (4 bits)
 - Header Length (4 bits)
 - DSCP (8 bits)
 - Total Packet Length (16 bits)
 - Id (16 bits)
 - Flags (3 bits)
 - Don't fragment (1 bit)
 - More fragments (1 bit)
 - Fragment offest (13 bit)
 - TTL (8 bits)
 - Protocol (8 bits) 
   - 6 for TCP and 17 for UDP
 - Header Checksum (16 bits)
 - Source Address (32 bits)
 - Destination Address (32 bits)


UDP: 8 Bytes
 - Source port (2 bytes / 16 bits)
 - Destination port (2 bytes / 16 bits)
 - Length (2 bytes / 16 bits)
 - Checksum (2 bytes / 16 bits)
*/