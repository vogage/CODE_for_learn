%this  m file is used to simulate the contribution of geometric errors in
%mirror mill machine tool movement error

%1.consider the 6 geometric errors of C axis

%three position error:
syms delta_x delta_y delta_z
%three angle error
syms alpha beta gama

%the error transmation matrix
Rotate_error_C=[1,-gama,beta;gama,1,-alpha;-beta,alpha,1];
Trans_error_C=[delta_x,delta_y,delta_z]';

%2. consider the 2 geometric errors of A axis
syms delta_Ay
syms beta_Az
Rotate_error_A=[1,0,beta_Az;0,1,0;-beta_Az,0,1];
Trans_error_A=[0,delta_Ay,0]';

%-------------------------------------------------------------------------------------------
%I can't deal with this problem
%---------------------------------------------------------------------------------------------
% n=length(NC);
% simulate=zeros(n,3);
% v=[0,0,1]';
% for i=1:n
%     A=NC(i,1)*pi/180;
%     C=NC(i,2)*pi/180;
%     rotate_A=[1,0,0;0,cos(A),-sin(A);0,sin(A),cos(A)];
%     rotate_C=[cos(C),-sin(C),0;sin(C),cos(C),0;0,0,1];
%    simulate=(Rotate_error_C*rotate_C*(Rotate_error_A*rotate_A*v ...
%        +Trans_error_A)+Trans_error_C)';
% end

%run 100 times to see the fluctuate
run_counts_ga=100;
ga_all=zeros(run_counts,9);
for i=1:run_counts_ga
fun = @gemetric_error_cal_with_ga;
A = [];
b = [];
Aeq = [];
beq = [];
lb = [-0.5 -0.5 -0.5 -pi*5/180 -pi*5/180 -pi*5/180 -0.1 -pi*5/180];
ub = [0.5 0.5 0.5 pi*5/180 pi*5/180 pi*5/180 0.1 pi*5/180];
nonlcon = [];
options.FunctionTolerance=1e-10;
[x,fval] = ga(fun,8,A,b,Aeq,beq,lb,ub,nonlcon)
ga_all(i,1:8)=x;
ga_all(i,9)=fval;
end



