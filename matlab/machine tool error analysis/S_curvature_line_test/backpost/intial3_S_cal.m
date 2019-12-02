%clc;clear;
%this m.file was used to produce the NC code and
%crosponding information of S workpiece

NC1=load("NC1.mat");
 NC1=NC1.NC1;
points1=load("POINTS1.mat");
points1=points1.points1;

C=NC1(:,4);C=C*pi/180;
A=NC1(:,5);A=A*pi/180;
tool_vector=[0;0;1];
n=length(NC1);
ijk=zeros(n,3);
for i=1:n
    rotate_A=[1,0,0;0,cos(A(i)),-sin(A(i));0,sin(A(i)),cos(A(i))];
    rotate_C=[cos(C(i)),-sin(C(i)),0;sin(C(i)),cos(C(i)),0;0,0,1];
    ijk(i,:)=(rotate_C*rotate_A*tool_vector)';
end
xyz=NC1(:,1:3);
n_points=length(points1);
at=zeros(n_points,2);


%----------------------------------------------------------------------
% the follow is to calculate the approprivate initial value of 
% the parameter a and t
%------------------------------------------------------------------------
total_points_distance=norm(points1(1,1:2)-xyz(1,1:2));

for i=2:length(points1)
    total_points_distance=total_points_distance+ ...
        norm(points1(i,1:2)-points1(i-1,1:2));
end
total_points_distance=total_points_distance+ ...
    norm(xyz(end,1:2)-points1(end,1:2));

% if(abs(points1(1,3))<abs(points1(1,3)-20))
%     at(1,1)=20/25;
% else
%     at(1,1)=10/25;
% end
at(1,1)=(points1(1,3)/ijk(1,3))/25;
total_temp_points_distance=norm(points1(1,1:2)-xyz(1,1:2));
at(1,2)=total_temp_points_distance/total_points_distance;
for i=2:length(points1)
%     if(abs(points1(i,3))<abs(points1(i,3)-20))
%         at(i,1)=20/25;
%     else
%           at(i,1)=10/25;
%     end
    at(i,1)=(points1(i,3)/ijk(i,3))/25;

    total_temp_points_distance=total_temp_points_distance+  ...
        norm(points1(i,1:2)-points1(i-1,1:2));
    at(i,2)=total_temp_points_distance/total_points_distance;
end

% this part of m file was used to initial the parameters of
% B_spline in NC code 

r=5;
p=3;
n=length(NC1);
[m,U,P]=GlobalCurveInterp(n-1,NC1,r,p);
%---------------------------------------------------------------------
% solve the the system of equantions with the above initial value
%-------------------------------------------------------------------------
at_fsolve=fsolve_at(at,U,P,points1);

at_fsolve=fsolve_at(at_fsolve,U,P,points1);
%---------------------------------------------------------------------
%second method use the ga method to calculate the 
%a,t parameter when the point to the envelop surface
%distance acoording 
%---------------------------------------------------
% 
% global P
% global U
% global points1
% global i_at
% 
% at0=at_ga(at,U,P,points1);


A=cal_derive_distance(points1,P,at_fsolve,U);

%----------------------------------------------------------------
%calculate the K (stiffness) matrix for the smoothness
%here only consider the AC influence
%------------------------------------------------------------------
n=length(P);
K=zeros(n,n);
% syms u
% y=interp_basisFun(i,j,u,n,U);


% fun=@(i,j,t,n,U)interp_basisFun(i,j,t,n,U);
% 
% for i=1:n
%     for j=1:n
%         
%       K(i,j)=integral(@(t)fun(i,j,t,n,U),0,1);
%       
%     end
% end
% 
% K_AC=zeros(5*n,5*n);
% K_AC(3*n+1:4*n,3*n+1:4*n)=K;
% K_AC(4*n+1:5*n,4*n+1:5*n)=K;

%---------------------------------------------------------------------
%calculate the initial distance between tool formate envelope
%surface and the selected point from S workpiece 
n=length(points1);
d_points=zeros(n,1);
for i=1:n
    d_points(i)=cal_distance_point_tool_envelope(points1,P,i,at_fsolve,U);
end





