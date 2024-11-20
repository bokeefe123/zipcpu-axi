module counter(
  input wire clk,
  input wire reset_n,
  output reg [7:0] count
);
  always @ (posedge clk or negedge reset_n) begin
    if (!reset_n)
      count <= 8'd0;
    else
      count <= count + 1;
  end
endmodule
