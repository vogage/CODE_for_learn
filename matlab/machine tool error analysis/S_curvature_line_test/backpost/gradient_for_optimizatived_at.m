function y=gradient_for_optimizatived_at(x,Niter)
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
Niter=Niter+1;
%if(~(x(1)>=0&&x(1)<=1&&x(2)>=0&&x(2)<=1))
if(~(x(2)>=0&&x(2)<=1))
    y(1)=10^10;
   
    y(2)=10^10;
    return;
end
    y=x;
    S=cal_point_of_tool_axis_surface(x(1),x(2),P,U);
    Sa=diff_a_point_of_tool_axis_surface(x(1),x(2),P,U);
    St=diff_t_point_of_tool_axis_surface(x(1),x(2),P,U);
    p=points1(iat,:);p=p';
    delta_a=-mean(p-S')/mean(Sa);
    delta_t=-mean(p-S')/mean(St);
    if(abs(delta_a)<0.1)
        y(1)=y(1)-delta_a;
    else
        y(1)=y(1)-sign(delta_a)*0.01;
    end
    
    if(abs(delta_t)<0.1)
        y(2)=y(2)-delta_t;
    else
          y(2)=y(2)-sign(delta_t)*0.02;
    end
    
    if(y(1)>1||y(1)<0) 
        y(1)=rand(1);
    end
        
    if(y(2)>1||y(2)<0)
        y(2)=rand(1);
    end
    
    
    
    
    
    
    if(norm(p-S')<10^(-3)||(norm(Sa)<10^(-3)&&norm(St)<10^(-3))||Niter>1000)
        return;
    else
        y=gradient_for_optimizatived_at(y,Niter);
    end
    
    
    
    
    
    
    