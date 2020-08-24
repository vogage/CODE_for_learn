function d=cal_distance_between_tool_axis_surface_model_surface(x)
global P;
global U;

global points1;
global iat;


 S=cal_point_of_tool_axis_surface(x(1),x(2),P,U);
p=points1(iat,:);
d=norm(S-p);

