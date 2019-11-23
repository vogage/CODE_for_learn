clc;clear;
data=load("S_curvature.mat");
data=data.S_curvature;
angle=data(:,4:6);
n=length(data);
ti=angle(:,1);tj=angle(:,2);tk=angle(:,3);
C=zeros(n,1);
A=zeros(n,1);
for k=1:n
C(k)=cal_Caxis_base(ti(k),tj(k));
end


r=6;
p=3;
[m,U,P]=GlobalCurveInterp(n-1,data,r,p);
x=(1:1000)/1000;x=x';
y=zeros(length(x),r);
for i=1:length(x)
    y(i,:)=CurvePoint(n-1,p,U,P,r,x(i));
end
yd=zeros(length(x),4);
for i=1:length(x)
yd(i,:)=(CurveDerivsAlg1(n-1,p,U,P(:,1),x(i),4))';
end

K=zeros(n,n);
% syms u
% y=interp_basisFun(i,j,u,n,U);


fun=@(i,j,t,n,U)interp_basisFun(i,j,t,n,U);

for i=1:n
    for j=1:n
        
      K(i,j)=integral(@(t)fun(i,j,t,n,U),0,1);
      
    end
end

inty=P(:,1)'*K*P(:,1);










