function A=cal_derive_distance(points,W,at_fsolve,U)
%this function was used to calculate the derive matrix of 
%distance between tool axis surface and the selected points
n=length(points1);
m=length(W);
A=zeros(n,1);

