function [m,U,P]=GlobalCurveInterp(n,Q,r,p)
%Global interpolation through n+1 points
%Input: n,Q,r,p
%Output: m,U,P
m=n+p+1;
d=0;
for k=1:n
    d=d+norm(Q(k+1,:)-Q(k-1+1,:));
end

u0=zeros(n,1);
for k=1:n
    u0(k+1)=u0(k-1+1)+norm(Q(k+1,:)-Q(k-1+1,:))/d;
end

U=zeros(m+1,1);
U(1:p+1)=0;
U(m-p+1:m+1)=1;
for j=1:1:n-p
    for i=j:1:j+p-1
        U(j+p+1)=U(j+p+1)+u0(i+1);
    end
    U(j+p+1)=U(j+p+1)/p;
end
 A=zeros(n+1,n+1);
 for i=0:1:n
    span=FindSpan(n,p,u0(i+1),U);
    i_row=BasisFuns(span,u0(i+1),p,U);
    A(i+1,span-p+1:span+1)=i_row;
 end
P=zeros(size(Q));
 for i=1:r
     P(:,i)=A\Q(:,i);
 end
 