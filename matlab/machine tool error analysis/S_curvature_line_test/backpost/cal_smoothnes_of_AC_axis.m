function Smooth_AC=cal_smoothnes_of_AC_axis(P)

global U
%XYZCA

A=P(:,5);
n=length(P);
p=3;
d=2;
fun=@(u) CurveDerivsAlg2(n-1,p,U,A,u,d,2);
%Compute curve derivatives
%Input: n: the number of control points is n+1
%           U:the knotes
%           P:the control points
%           p: the degree of the curve
%Output: array CK[], where CK[k] is the kth derivative
% the most d order of derivative
% A_2=integral(fun,0,1)
%fun=@(u) CurveDerivsAlg2(n-1,p,U,A,u,d,1);
A_1=integral(fun,0,1);
fun=@(u) CurveDerivsAlg2(n-1,p,U,A,u,d,3);
A_2=integral(fun,0,1);
A_2=sqrt(A_2);


C=P(:,4);
% fun=@(u) CurveDerivsAlg2(n+1,p,U,C,u,d,3);
% C_2=integral(fun,0,1)
%感觉2阶的量也太大了，好像不太合适啊


fun=@(u) CurveDerivsAlg2(n+1,p,U,C,u,d,2);
C_1=integral(fun,0,1);
fun=@(u) CurveDerivsAlg2(n+1,p,U,C,u,d,3);
C_2=integral(fun,0,1);
C_2=sqrt(C_2);


Smooth_AC=A_1+A_2+C_1+C_2;


