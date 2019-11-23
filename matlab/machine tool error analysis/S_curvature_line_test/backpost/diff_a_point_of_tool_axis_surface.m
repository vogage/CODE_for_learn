function d_a=diff_a_point_of_tool_axis_surface(a,t,w,U)
%this function was used to calculate the derivate of 
%point in tool axis movement surface by a

% Input a: the unit parameter in tool axis length [0,1]
%            t: the unit parameter in the position of tool tracjectory
%            [0,1]
%           w:the control points of B_spline NC code
%           U: the corresponding knote vector

h=1*10^(-5);
if(a-h<0)
    d_a=0;
    return;
end
a2=a;
a1=a-h;
f1=cal_point_of_tool_axis_surface(a1,t,w,U);
f2=cal_point_of_tool_axis_surface(a2,t,w,U);

d_a=(f2-f1)/h;

