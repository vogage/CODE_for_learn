function index=FindSpan(n,p,u,U)
%determine the knote span index
%Input:n,p,u,U
%Return: the knot span index
if (abs(u-U(n+1+1))<10^(-10))
%if(u==U(n+1+1))
%-----------------------------------------------------------------
% I don't know why this formula would be logic 0
% when U(n+1+1)=1 and u=1.000
%so I change i t to this format
%--------------------------------------------------------------
    index=n;
    return;
end
% low=p+1;
% high=n+1+1;
% mid=floor((low+high)/2);
% while(u<U(mid+1) | u>=U(mid+2))
%     if(u<U(mid+1))
%         high=mid;
%     else
%         low=mid;
%     end
%     mid=floor((low+high)/2);
% end
index=1;
while(~(u>=U(index)&&u<U(index+1)))
        index=index+1;
%     if(index==472)
%         iiiii=1;
 %    end
    
end
index=index-1;


