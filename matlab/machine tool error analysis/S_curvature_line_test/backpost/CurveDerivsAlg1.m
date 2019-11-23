function CK=CurveDerivsAlg1(n,p,U,P,u,d)
%Compute curve derivatives
%Input: n: the number of control points is n+1
%           U:the knotes
%           P:the control points
%           p: the degree of the curve
%Output: array CK[], where CK[k] is the kth derivative
% the most d order of derivative

du=min(d,p);
CK=zeros(d,1);

    span=FindSpan(n,p,u,U);
    nders=DersBasisFuns(span,u,p,du,U);
    for k=0:1:du
        CK(k+1)=0;
        for j=0:1:p
            CK(k+1)=CK(k+1)+nders(k+1,j+1)*P(span-p+j+1);
        end
    end
    