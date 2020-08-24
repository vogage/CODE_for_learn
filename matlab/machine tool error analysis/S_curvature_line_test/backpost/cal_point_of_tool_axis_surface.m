function S=cal_point_of_tool_axis_surface(a,t,w,U)
% this function was used to calculate the surface of 
% tool axis movement in S workpiece machine

% Input a: the unit parameter in tool axis length [0,1]
%            t: the unit parameter in the position of tool tracjectory
%            [0,1]
%           w:the control points of B_spline NC code
%           U: the corresponding knote vector


tool_length=25;
p=3;
n=length(w);
r=5;
v_t=CurvePoint(n-1,p,U,w,r,t);
A=v_t(5)*pi/180;
C=v_t(4)*pi/180;
tool_vector=[0,0,1];tool_vector=tool_vector';

 rotate_A=[1,0,0;0,cos(A),-sin(A);0,sin(A),cos(A)];
    rotate_C=[cos(C),-sin(C),0;sin(C),cos(C),0;0,0,1];
    ijk=(rotate_C*rotate_A*tool_vector)';
% the point is calculate by the tool point plus 
% the vector in tool axis direction
S=v_t(1:3)+a*tool_length*ijk;

