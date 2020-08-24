function [at_gradient,dif_distance]=gradient_solve_at(at)
%this function was used to solve the equation
%about the value of a parameter and t parameter

global P;
global U;
global points1;
global iat;
global tool_radius;

iat=1;
at_gradient=zeros(size(at));
dif_distance=zeros(size(at));
 for i=1:length(at)
    x0=at(i,:);
 
    
   y =ga_for_optimizatived_at(x0);
    at_gradient(i,:)=y;
    S=cal_point_of_tool_axis_surface(y(1),y(2),P,U);
    iat=iat+1;
    points1(i,:);
    dif_distance(i)=norm(S-points1(i,:))-tool_radius;
 end
 
%  for iat=1:length(at)
%     
%      
%      x0=at(iat,:);
%      at(iat,:)=fslove_for_optimizatived_at(x0);
%     
%  end
