module udp(
  input wire clk,
  input wire r_valid,
  output reg r_ready,
  input wire [15:0] r_data,
  input wire r_last,
  input wire r_keep, // not sure how to use this
  output reg t_valid,
  // output reg [15:0] buffer [3:0],
  input wire t_ready,
  output reg [15:0] t_data,
  output reg t_last
  // output reg[1:0] t_offset,
  // output reg[1:0] r_offset
);

    localparam DATA_WIDTH = 2'd3;
    initial t_valid = 0;
    initial t_last = 0;
    initial r_offset = 2'h0;
    reg [15:0] buffer [3:0];
    reg [1:0] r_offset = 0;
    reg [1:0] t_offset = 0;


    always @ (posedge clk) begin
      if (r_offset < DATA_WIDTH + 1) begin
        r_ready <= r_valid;
      end
    end  
    
    always @ (posedge clk) begin
      if (t_offset == DATA_WIDTH - 1 && t_ready) begin
         t_last <= 1'b1;
      end
    end 

    //if tready get r_tdata into t_tdata
    always @ (posedge clk) begin
      if (r_ready) begin
        buffer <= {r_data, buffer[3:1]};
        if (!r_last) begin
          r_offset <= r_offset + 1;
        end
      end
    end

    always @ (posedge clk) begin
      if (t_valid)
      begin
        t_data <= buffer[t_offset];
        if (t_ready && !t_last) begin
          t_offset <= t_offset + 1;
        end
      end
    end 

    //if r_last then t_last
    always @ (posedge clk) begin
      if (t_offset < r_offset && r_last && !r_valid)
      begin
        t_valid <= 1'b1;
      end

      else if ((t_last && t_ready) || (t_valid && t_ready))
      begin
        t_valid <= 1'b0;
      end 
    end 


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