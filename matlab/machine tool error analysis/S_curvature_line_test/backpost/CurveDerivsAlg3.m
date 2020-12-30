function C=CurveDerivsAlg3(n,p,U,P,u,d,order)
%compute the curve square see CurveDerisAlg3
%----------------------------------------------------
%Input: n: the number of control points is n+1
%           U:the knotes
%           P:the control points
%           p: the degree of the curve
%Output: array CK[], where CK[k] is the kth derivative
% the most d order of derivative


%the origin formula is CK, include the all order of Derivs
%here the C only defined order, the flag is order
du=min(d,p);

%the u is a array
n_u=length(u);
CK=zeros(d,n_u);
if(order>p)
    C=zeros(size(u));return;
end


for i=1:n_u
    span=FindSpan(n,p,u(i),U);
    nders=DersBasisFuns(span,u(i),p,du,U);
    for k=0:1:du
        CK(k+1,i)=0;
        for j=0:1:p
            CK(k+1,i)=CK(k+1,i)+nders(k+1,j+1)*P(span-p+j+1);
           
        end
    end
end   

C=CK(order,:);