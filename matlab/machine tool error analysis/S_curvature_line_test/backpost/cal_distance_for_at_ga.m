function distance=cal_distance_for_at_ga(at)
global P
global U
global points1
global i_at

a=at(1);
t=at(2);

PS=cal_point_of_tool_axis_surface(a,t,P,U);
distance=norm(PS-points1(i_at))