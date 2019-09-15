function y=calculate_derivate_B_spline(x,k,knote,control)

N=length(x);
n=length(control);
y=zeros(N,1);
y_b=zeros(N,n);
for i=1:N
    for j=1:n
       % calculate_derivate_Basis(j,k,x(i),knote)
        y(i)=y(i)+control(j)*calculate_derivate_Basis(j,k,x(i),knote);
        y_b(i,j)=calculate_derivate_Basis(j,k,x(i),knote);
    end
end
y=0;
