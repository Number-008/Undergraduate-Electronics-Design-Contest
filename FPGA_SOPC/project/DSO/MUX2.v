module MUX2(s1,s2,y,select);
input  s1,s2;
input  select;
output y;

assign y=(select) ? s1:s2;
endmodule