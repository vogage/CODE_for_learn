% p=2;
% U=[0,0,0,1,2,3,4,4,5,5,5];
% u=5/2;
% N=zeros(10,0);
% span=FindSpan(3,p,u,U)
% BasisFuns(span,3,p,U,N)

% Q=[0,0;3,4;-1,4;-4,0;-4,-3];
% n=4;
% p=3;
% r=2;% the number of coordinates
% [m,U,P]=GlobalCurveInterp(n,Q,r,p);
% %ders=DersBasisFuns(4,5/2,p,n,U);
% 
% x1=(1:11)/10;x1=x1'-1;
% y1=sin(x1*pi*2);
% n=length(x1)-1;
% r=1;
% p=3;
% [m,U,P]=GlobalCurveInterp(n,y1,r,p);
% x2=(1:1000)/1000;x2=x2';
% y2=sin(x2*pi*2);
% y3=zeros(length(y2),1);
% for i=1:length(x2)
%     y3(i)=CurvePoint(n,p,U,P,x2(i));
% end


n=length(data)-1;
r=2;
p=3;
[m,U,P]=GlobalCurveInterp(n,data,r,p);
x=(1:1000)/1000;x=x';
y=zeros(length(x),2);
for i=1:length(x)
    y(i,:)=CurvePoint(n,p,U,P,2,x(i));
end
yd=zeros(length(x),4);
for i=1:length(x)
yd(i,:)=(CurveDerivsAlg1(n,p,U,P(:,1),x(i),4))';
end














