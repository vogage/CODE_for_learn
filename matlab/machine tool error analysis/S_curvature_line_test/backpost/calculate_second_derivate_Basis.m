function y=calculate_second_derivate_Basis(i,k,x,knote)

n=length(knote);
% if(x==knote(end))
%     y=0;
%     return;
% end

if(knote(i+k)-knote(i)==0)
    y_left=0;
else

    y_left=calculate_derivate_Basis(i,k-1,x,knote) ...
        /(knote(i+k)-knote(i));
end
if(i+k+1<=n)
    if(knote(i+k+1)-knote(i+1)==0)
         y_right=0;
    else

         y_right=calculate_derivate_Basis(i+1,k-1,x,knote) ...
             /(knote(i+k+1)-knote(i+1));
    end
else
    y_right=0;
end

y=k*(y_left-y_right);
