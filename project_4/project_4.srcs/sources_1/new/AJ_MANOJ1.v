`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04.02.2018 00:22:24
// Design Name: 
// Module Name: bitwise_or
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////
module bitwise_or (output reg [3,0] C, input [3,0] A,B);
or 	O1(C[0], A[0], B[0]),
	O2(C[0], A[0], B[0]),
	O3(C[0], A[0], B[0]),
 	O4(C[0], A[0], B[0]);S
endmodule

module bitwise_and (output reg [3,0] C, input [3,0] A,B);
and N1(C[0], A[0], B[0]),
	N2(C[0], A[0], B[0]),
	N3(C[0], A[0], B[0]),
 	N4(C[0], A[0], B[0]);
endmodule

module half_adder (output S, C, input x, y);
xor (S, x, y);
and (C, x, y);
endmodule

module full_adder (output S, C, input x, y, z);
wire S1, C1, C2;
half_adder HA1 (S1, C1, x, y);
half_adder HA2 (S, C2, S1, z);
or G1 (C, C2, C1);
endmodule

module carry_bit(output C, input P,G,D);
wire k1;
and(k1,P,D);
or(C,G,k1);
endmodule

module carry_look_ahead_adder (output [3:0]S, output S4, input [3:0]A,B);
wire Ci;
assign Ci=0;
wire C0,C1,C2;
wire [7:0]P,G;

half_adder HA1(P[0],G[0],A[0],B[0]),
           HA2(P[1],G[1],A[1],B[1]),
           HA3(P[2],G[2],A[2],B[2]),
           HA4(P[3],G[3],A[3],B[3]);
           
carry_bit CB0(C0,P[0],G[0],Ci),
          CB1(C1,P[1],G[1],C0),
          CB2(C2,P[2],G[2],C1),
          CB3(S4,P[3],G[3],C2);

xor(S[0],P[0],Ci);
xor(S[1],P[1],C0);
xor(S[2],P[2],C1);
xor(S[3],P[3],C2);

endmodule

module carry_look_ahead_subtractor (output [3:0]S, output S4, input [3:0]A,B);
wire Ci;
assign Ci=0;
wire C0,C1,C2;
wire [7:0]P,G;

wire [3:0]d ;
wire [3:0]R;

full_adder  FA1(d[0], R[0], 1, ~B[0], Ci),
            FA2(d[1], R[1], 0, ~B[1], R[0]),
            FA3(d[2], R[2], 0, ~B[2], R[1]),
            FA4(d[3], R[3], 0, ~B[3], R[2]);
            
half_adder HA1(P[0],G[0],A[0],d[0]),
           HA2(P[1],G[1],A[1],d[1]),
           HA3(P[2],G[2],A[2],d[2]),
           HA4(P[3],G[3],A[3],d[3]);
           
carry_bit CB0(C0,P[0],G[0],Ci),
          CB1(C1,P[1],G[1],C0),
          CB2(C2,P[2],G[2],C1),
          CB3(S4,P[3],G[3],C2);

xor(S[0],P[0],Ci);
xor(S[1],P[1],C0);
xor(S[2],P[2],C1);
xor(S[3],P[3],C2);

endmodule

module arithmetic_logic_unit (output [3:0]S, output S4, input [3:0]A,B, input F1,F2);

always @(posedge clk)
begin
	if(F2 == 0 && F1 == 0)
	begin
		bitwise_or BO1(output reg [3,0] S, input [3,0] A,B);
		assign S4 = 0;
	end

	if(F2 == 0 && F1 == 1)
	begin
		bitwise_and BN1(output reg [3,0] S, input [3,0] A,B);
		assign S4 = 0;
	end

	if(F2 == 1 && F1 == 0)
	begin
		carry_look_ahead_adder CA1(output [3:0]S, output S4, input [3:0]A,B);
	end

	if(F2 == 1 && F1 == 1)
	begin
		carry_look_ahead_subtractor CS1(output [3:0]S, output S4, input [3:0]A,B);
	end
end
endmodule