function at_ga=at_ga(at,U,P,points1)


global i_at
at_ga=zeros(length(points1),2);
% lb1=at(i_at,1);
% lb1=lb1-0.1;

t1=at(i_at,2)-0.1;
t2=at(i_at,2)+0.1;
if(t1<0)
    t1=0;
end
if(t2>1)
    t2=1;
end


for i_at=1:length(points1)

lb=[0 t1];
ub=[1 t2];
fun=@cal_distance_for_at_ga;
%ga(fun,nvars,A,b,Aeq,beq,lb,ub) 
at_ga(i_at,:)=ga(fun,2,[],[],[],[],lb,ub);
end

