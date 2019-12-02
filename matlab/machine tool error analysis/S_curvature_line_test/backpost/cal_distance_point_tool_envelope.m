function d=cal_distance_point_tool_envelope(points1,P,i,at_fsolve,U)
%calculate the initial distance between tool formate envelope
%surface and the selected point from S workpiece 
%Input: points : the points selected from the S workpiece surface
%          P:   the control points 
%           i: the index of the point to calculate
%          fsolve: the point coresponding parameter in tool axis
%           U: the knote vector
P_tool_envelope=cal_point_of_tool_axis_surface(at_fsolve(i,1), ...
    at_fsolve(i,2),P,U);
d=norm(P_tool_envelope-points1(i,:));
