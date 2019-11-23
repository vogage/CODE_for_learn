function y=BasisFuns(i,u,p,U)
%Compute the nonvanishing basis functions
%intput: i,u,p,U
%Output: N
N(1)=1.0;
for j=1:1:p
    left(j+1)=u-U(i+1-j+1);
    right(j+1)=U(i+j+1)-u;
    saved=0;
    for r=0:1:j-1
        temp=N(r+1)/(right(r+1+1)+left(j-r+1));
        N(r+1)=saved+right(r+1+1)*temp;
        saved=left(j-r+1)*temp;
    end
    N(j+1)=saved;
end
y=N;

        