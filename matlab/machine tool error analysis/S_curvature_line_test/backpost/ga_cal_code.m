function NC_code=ga_cal_code()
global P    %           P:the control points
%  global U   %           U:the knotes
% 
% 
%  global points1
%  global tool_radius

fun=@(w)ga_trajcetory_optimizatioon(w);
n=length(P);
x0=zeros(n*5,1);
x0(1:n)=P(:,1);
x0(n+1:n*2)=P(:,2);
x0(2*n+1:n*3)=P(:,2);
x0(3*n+1:n*4)=P(:,2);
x0(4*n+1:n*5)=P(:,2);

lb=x0-0.06;
ub=x0+0.06;
NC_code=fminsearch(fun,x0);
 


 

 
 

