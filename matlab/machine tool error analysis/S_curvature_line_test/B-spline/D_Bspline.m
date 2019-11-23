function y=D_Bspline(j,d,x,knote)

% u=1;
% while(~(x>=knote(u)&&x<knote(u+1)))
%     u=u+1;
% end

if(knote(j+d)-knote(j)==0)
    left=0;
else
    left=Basis2(j,d-1,x,knote)/(knote(j+d)-knote(j));
end

if(knote(j+d+1)-knote(j+1)==0)
    right=0;
else

    right=Basis2(j+1,d-1,x,knote)/(knote(j+d+1)-knote(j+1));
end

y=d*(left-right);
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
    