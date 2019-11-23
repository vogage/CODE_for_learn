function knote=cal_knote_Bspline(x,d)
%this function was used to calculate the knote of a Bspline
knote=zeros(length(x)+2*d,1);
knote(1:d)=x(1);
knote(d+1:length(x)+d)=x;
knote(length(x)+d+1:length(x)+2*d)=x(end);
