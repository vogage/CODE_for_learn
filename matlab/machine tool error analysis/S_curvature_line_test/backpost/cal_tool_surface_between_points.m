function diff_distance= cal_tool_surface_between_points(control)
global U
global tool_radius
global at_solve
global points1
n=length(at_solve);
dif_array=zeros(n,1);
for i=1:n
    at(1)=at_solve(i,1);
    at(2)=at_solve(i,2);
    S=cal_point_of_tool_axis_surface(at(1),at(2),control,U);
    dif_array(i)=norm(S-points1(i,:))-tool_radius;
end
diff_distance=0;
for i=1:n
    diff_distance=diff_distance+dif_array(i)^2;
end
