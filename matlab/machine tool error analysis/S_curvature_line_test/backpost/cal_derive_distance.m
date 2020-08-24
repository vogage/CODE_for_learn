function A=cal_derive_distance(points,control,at_fsolve,U)
%this function was used to calculate the derive matrix of 
%distance between tool axis surface and the selected points
n=length(points);
W=control(:,1);
W=[W;control(:,2)];
W=[W;control(:,3)];
W=[W;control(:,4)];
W=[W;control(:,5)];

m=length(W);
A=zeros(n,m);

for i=1:n
    P=points(1,:);
    S=cal_point_of_tool_axis_surface(at_fsolve(i,1),at_fsolve(i,2),control,U);
    for j=1:length(W)
        a=at_fsolve(i,1)
        t=at_fsolve(i,2)
        
        S_wj=diff_wi_point_of_tool_axis_surface(a,t,j,control,U)
        A(i,j)=S_wj*(S-P)';
    end
end
