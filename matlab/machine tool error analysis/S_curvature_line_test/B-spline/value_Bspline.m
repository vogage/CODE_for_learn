function y=value_Bspline(x,d,knote,control)
%注意最后一点的knote值取不到，解在[u1,u2)


u=1;
while(~(x>=knote(u)&&x<knote(u+1)))
    u=u+1;
end

c=control(u-d+1:u);
for r=d-1:-1:1
    t1=knote(u-r+1:u);
    t2=knote(u+1:u+r);
    w=(x-t1)./(t2-t1);
    cl=c(1:end-1);
    cf=c(2:end);
    c=(1-w).*cl+w.*cf;
end
y=c;
