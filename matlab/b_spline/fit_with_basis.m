function y=fit_with_basis(x,k,knote,control)

n=length(control);%the number of basis funtion
N=length(x);

y=zeros(N,1);
y_b=zeros(N,n);
for i=1:N
    for j=1:n
        y(i)=y(i)+control(j)*Basis(j,k,x(i),knote);
        y_b(i,j)=Basis(j,k,x(i),knote);
    end
end
y=0;


    
