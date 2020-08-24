function y=ga_for_optimizatived_at(x)
%this function was designed for the matlab 
%algorthim of fsolve 
% function F = root2d(x)
% 
% F(1) = exp(-exp(-(x(1)+x(2)))) - x(2)*(1+x(1)^2);
% F(2) = x(1)*cos(x(2)) + x(2)*sin(x(1)) - 0.5;

%--------------------------------------------------------
% it is a sub function of 
% at_fsolve=fsolve_at(at,U,P,points1)
%--------------------------------------------------------
global P;
global U;

global points1;
global iat;

%if(~(x(1)>=0&&x(1)<=1&&x(2)>=0&&x(2)<=1))
if(~(x(2)>=0&&x(2)<=1))
    y(1)=0.5;
   
    y(2)=0.5;
    
end
    
   
    
%     Sa=diff_a_point_of_tool_axis_surface(x(1),x(2),P,U);
%     St=diff_t_point_of_tool_axis_surface(x(1),x(2),P,U);
 
  data=zeros((100+1)*(20+1)+1,3);
  N=1;
  distance=100;
  for i=0:0.01:1
      for j=x(2)-0.1:0.01:x(2)+0.1
          x(1)=i;x(2)=max(j,0);
          x(2)=min(x(2),1);
          data(N,1)=i;
          data(N,2)=j;
          data(N,3)= cal_distance_between_tool_axis_surface_model_surface(x);
          N=N+1;
          if(data(N,3)<distance)
              distance=data(N,3);
              y(1)=data(N,1);
              y(2)=data(N,2);
          end
          
      end
  end
  
  

  
  
    
    
    
    
    
    
    