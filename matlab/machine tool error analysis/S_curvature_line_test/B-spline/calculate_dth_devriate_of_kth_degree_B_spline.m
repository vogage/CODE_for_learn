function y=calculate_dth_devriate_of_kth_degree_B_spline(k,x,knote,control,d)
N=length(x);
n=length(control);
y=zeros(N,1);
y_b=zeros(N,n-d+1);
y_p=zeros(N,n-d+1);
for i=1:N
    for j=1:n-d+1
        y(i)=y(i)+Basis(j,k-d,x(i),knote)*calculate_P(j,d,k,knote,control);
        y_b(i,j)=Basis(j,k-d,x(i),knote);
        y_p(i,j)=calculate_P(j,d,k,knote,control);
    end
end
y=0;