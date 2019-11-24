function at_ga=at_ga(at,U,P,points1)


global i_at
at_ga=zeros(length(points1),2);
for i_at=1:length(points1)

lb=[0 0];
ub=[1 1];
fun=@cal_distance_for_at_ga;
%ga(fun,nvars,A,b,Aeq,beq,lb,ub) 
at_ga(i_at,:)=ga(fun,2,[],[],[],[],lb,ub);
end

