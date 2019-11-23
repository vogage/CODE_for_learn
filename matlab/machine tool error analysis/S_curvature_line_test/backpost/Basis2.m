function y=Basis2(j,d,x,knote)



if(d==0) 
      
         if(knote(j)<=x&&x<knote(j+1))
             y=1;
         
         else
             y=0;
         end
      
else
   
       if(knote(j)==knote(j+1+d))
           
            y=0;
      
       elseif((knote(j)<knote(j+d)) ...
              &&(knote(j+1)==knote(j+1+d)))
          s1=(x-knote(j))/(knote(j+d)-knote(j));
          s1=s1*Basis2(j,d-1,x,knote);
          y=s1;
          
          elseif((knote(j)==knote(j+d))&& ...
             ( knote(j+1)<knote(j+1+d)))
         s2=(knote(j+1+d)-x)/(knote(j+1+d)-knote(j+1));
         s2=s2*Basis2(j+1,d-1,x,knote);
         y=s2;
         
       else
            s1=(x-knote(j))/(knote(j+d)-knote(j));
            s1=s1*Basis2(j,d-1,x,knote);
            
            s2=(knote(j+1+d)-x)/(knote(j+1+d)-knote(j+1));
            s2=s2*Basis2(j+1,d-1,x,knote);
             y=s1+s2;
        
       end
end
 
% if(x==knote(end)&&j+1+d==length(knote))

% 这里还有有问题的

%  if(x==knote(end)&&j+2*d==length(knote))
%      y=1;
%  end

end