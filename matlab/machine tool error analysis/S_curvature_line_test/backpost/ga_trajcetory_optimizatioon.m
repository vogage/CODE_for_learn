function y=ga_trajcetory_optimizatioon(w)

n=length(w);
m=n/5;
control(:,1)=w(1:m);
control(:,2)=w(m+1:2*m);
control(:,3)=w(2*m+1:3*m);
control(:,4)=w(3*m+1:4*m);
control(:,5)=w(4*m+1:5*m);
smooth_AC=cal_smoothnes_of_AC_axis(control);
diff_distance= cal_tool_surface_between_points(control);
y=smooth_AC+diff_distance;


