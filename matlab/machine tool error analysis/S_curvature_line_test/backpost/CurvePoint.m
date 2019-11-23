function C=CurvePoint(n,p,U,P,r,u)
%Compute curve point
%Input: n the total number of interval
%           p the degree of B spline
%           U the knote vector
%           u the input value
%           C the calculated curve point
%           P the control points
%           r   the number of coordinates
span=FindSpan(n,p,u,U);
N=BasisFuns(span,u,p,U);
C=zeros(1,r);
for k=1:r
    for i=0:1:p
    C(1,k)=C(1,k)+N(i+1)*P(span-p+i+1,k);
    end
end
