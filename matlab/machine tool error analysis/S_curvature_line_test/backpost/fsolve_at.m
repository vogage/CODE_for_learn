function at_fsolve=fsolve_at(at,U,P,points1)
%this function was used to solve the equation
%about the value of a parameter and t parameter

global P;
global U;
global points1;
global iat
 for iat=1:length(at)
    
     fun=@fslove_for_optimizatived_at;
     x0=at(iat,:);
     at(iat,:)=fsolve(fun,x0);
    
 end
 at_fsolve=at;
%  for iat=1:length(at)
%     
%      
%      x0=at(iat,:);
%      at(iat,:)=fslove_for_optimizatived_at(x0);
%     
%  end
