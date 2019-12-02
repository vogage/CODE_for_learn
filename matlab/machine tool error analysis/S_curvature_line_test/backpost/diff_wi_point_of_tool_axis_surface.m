function S_wi=diff_wi_point_of_tool_axis_surface(a,t,i,w,U)
%this function was used to calculate the derivate of 
%point in tool axis movement surface by a

% Input a: the unit parameter in tool axis length [0,1]
%            t: the unit parameter in the position of tool tracjectory
%            [0,1]
%           w:the control points of B_spline NC code
%            i: the ith control point
%           U: the corresponding knote vector
n=length(w);
col=floor(i/n)+1;
if(col==6)
    col=5;
 end

row=mod(i,n);
if(row==0)
    row=n;
end

h=1*10^(-5);
if(w(row,col)-h<0)
    S_wi=zeros(1,3);
    return;
end



f1=cal_point_of_tool_axis_surface(a,t,w,U);
w2=w;
w2(row,col)=w2(row,col)-h;
f2=cal_point_of_tool_axis_surface(a,t,w2,U);

S_wi=(f2-f1)/h;

