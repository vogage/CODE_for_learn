function y=calculate_P(i,k,p,knote,control)
n=length(control);
if(i>n)
    y=0;
else

    if(k==0)
        y=control(i);
    
    elseif(i+p+1>n) 
        y=0;
      else
        below=knote(i+p+1)-knote(i+k);
         up=p-k+1;
    y=(up/below)*(calculate_P(i+1,k-1,p,knote,control)+  ....
        calculate_P(i,k-1,p,knote,control));
    end
 end


