clc;clear;
%this file was use to test the funciton and some small
%algorthim of B_spline
%2019-11-17





% t=knote;
% x=(1:1000)/1000;
% s=zeros(length(x),1);
% for i=1:length(x)
%     s(i)=-Basis2(1,3,x(i),t)+5*Basis2(2,3,x(i),t) ...
%         -5*Basis2(3,3,x(i),t)+Basis2(4,3,x(i),t);
% end
% 
% knote=[0,0,0,1,1,2,3,3,3];
% c=[1,0,2,1/2,0,1];
% 
% x=(1:3000)/1000;
% s=zeros(length(x),1);
% for i=1:length(x)
%     for j=1:length(c)
%         s(i)=s(i)+c(j)*Basis2(j,2,x(i),knote);
%     end
% end

% knote=[0,0,0,0,1,1,2,2,2,4,5,5,5,5];
% c=[0,3,1,4,6,1,5,3,0,4];
% x=(1:5000)/1000;
%  s=zeros(length(x),1);
%  for i=1:length(x)
%     for j=1:length(c)
%          s(i)=s(i)+c(j)*Basis2(j,3,x(i),knote);
%      end
%  end
%  
 
%  knote=[0,0,0,0,1,1,2,2,2,4,5,5,5,5];
%  c=[0,3,1,4,6,1,5,3,0,4];
%  x=(1:5000)/1000;
%   s=zeros(length(x),1);
%   for i=1:length(x)
%     s(i)=value_Bspline(x(i),3,knote,c);
%     
%   end

clc;clear;
x=((1:11)-1)*pi*2/10;x=x';
y=sin(x);

d=3;
c=interpolate_cubic_Bspline(x,y,3);
c2=interpolate_Bspline(x,y,3);
knote=cal_knote_Bspline(x,d);
% 
x1=(1:1000-1)*pi*2/1000;
x1=x1';
y1=sin(x1);
y2=zeros(length(x1),1);


for i=1:length(x1)
     y2(i)=value_Bspline(x1(i),3,knote,c);
end

% clc;clear;
% x=((1:11)-1)*pi*2/10;x=x';
% y=sin(x);
% x1=(1:1000-1)*pi*2/1000;
% x1=x1';
% y1=sin(x1);
% y2=zeros(length(x1),1);
% for i=1:length(x1)
%     y2(i)=linear_B_spline_interpolate(x1(i),x,y);
% end


 