function d_t=diff_t_point_of_tool_axis_surface(a,t,w,U)
%this function was used to calculate the derivate of 
%point in tool axis movement surface by a

% Input a: the unit parameter in tool axis length [0,1]
%            t: the unit parameter in the position of tool tracjectory
%            [0,1]
%           w:the control points of B_spline NC code
%           U: the corresponding knote vector

h=1*10^(-5);
if(t-h<0)
    d_t=0;
    return;
end
t2=t;
t1=t-h;
f1=cal_point_of_tool_axis_surface(a,t1,w,U);
f2=cal_point_of_tool_axis_surface(a,t2,w,U);

d_t=(f2-f1)/h;

