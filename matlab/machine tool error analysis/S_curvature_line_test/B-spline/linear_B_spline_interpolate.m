function g=linear_B_spline_interpolate(t,x,y)
%piecewise linear interpolation
%very well
m=length(x);
knote=[x(1);x;x(end)];
g=0;
for i=1:m
    g=g+y(i)*Basis2(i,1,t,knote);
end
