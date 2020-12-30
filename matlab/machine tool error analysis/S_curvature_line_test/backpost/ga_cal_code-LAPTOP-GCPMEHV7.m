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
x0(2*n+1:n*3)=P(:,3);
x0(3*n+1:n*4)=P(:,4);
x0(4*n+1:n*5)=P(:,5);
A=[];
b=[];
Aeq=[];
beq=[];

lb=x0-20;
ub=x0+20;
% NC_code=fminsearch(fun,x0);
nonlcon = [];
optimoptions(@fmincon,'MaxIterations',100);
NC_code = fmincon(fun,x0,A,b,Aeq,beq,lb,ub,nonlcon)

 


 

 
 

