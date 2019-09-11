function y=gemetric_error_cal_with_ga(x)
%this function is used to deal with ga method
%it a minize loss funtion

global NC
global actual

% %three position error:
% syms delta_x delta_y delta_z
% %three angle error
% syms alpha beta gama
delta_x=x(1);delta_y=x(2);delta_z=x(3);
alpha=x(4);beta=x(5);gama=x(6);

% %2. consider the 2 geometric errors of A axis
% syms delta_Ay
% syms beta_Az
delta_Ay=x(7);
beta_Az=x(8);


Rotate_error_C=[1,-gama,beta;gama,1,-alpha;-beta,alpha,1];
Trans_error_C=[delta_x,delta_y,delta_z]';

Rotate_error_A=[1,0,beta_Az;0,1,0;-beta_Az,0,1];
Trans_error_A=[0,delta_Ay,0]';

n=length(NC);
simulate=zeros(n,3);
v=[0,0,1]';
for i=1:n
    A=NC(i,1)*pi/180;
    C=NC(i,2)*pi/180;
    rotate_A=[1,0,0;0,cos(A),-sin(A);0,sin(A),cos(A)];
    rotate_C=[cos(C),-sin(C),0;sin(C),cos(C),0;0,0,1];
   simulate(i,:)=(Rotate_error_C*rotate_C*(Rotate_error_A*rotate_A*v ...
       +Trans_error_A)+Trans_error_C)';
end
y=0;
for i=1:n
    y=y-(norm(simulate(i,:)-actual(i,:)))^2;
end




