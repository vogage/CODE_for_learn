function y=Basis(i,k,x,knote)
if(k==0) 
      
         if(knote(i)<=x&&x<knote(i+1))
             y=1;
         else
             y=0;
         end
      
else
   
   %k=k-1;
    up=x-knote(i);
    below=knote(i+k)-knote(i);
    
    if(below==0)
        y_left=0;
    else
        y_left=up/below;
    end
    
    y_left=y_left*Basis(i,k-1,x,knote);
    
    up=knote(i+k+1)-x;
    below=knote(i+k+1)-knote(i+1);
    
    if(below==0)
        y_right=0;
    else
        y_right=up/below;
    end
    
%     if(y_left==0||y_right==0)
%         y=0;
%     else
    y_right=y_right*Basis(i+1,k-1,x,knote);
    
    y=y_left+y_right;
 %  end
  
end