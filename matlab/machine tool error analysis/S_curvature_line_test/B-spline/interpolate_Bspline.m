function control=interpolate_Bspline(x,y,d)

n=length(x);

%假设节点均匀分布
knote=zeros(length(x)+2*d,1);
knote(1:d)=x(1);
knote(d+1:length(x)+d)=x;
knote(length(x)+d+1:length(x)+2*d+1)=x(end)+x(2)-x(1);

Ac=zeros(n,n);

for i=1:n
  for j=1:n
        Ac(i,j)=Basis2(j,d,x(i),knote);
         
  end
  
end

control=Ac\y;





