%this m file is a inital file
%it was a try example of interplating the S_curve trajectory
%by B_spline method
%2019-11-20

clc;clear;
load("S_curvature.mat");
Sx=S_curvature(:,1);
Sy=S_curvature(:,2);
t=1:length(Sx);t=t';

d=3;
cx=interpolate_cubic_Bspline(t,Sx,3);
cy=interpolate_cubic_Bspline(t,Sy,3);

knote=cal_knote_Bspline(t,d);

t2=((1:1000-1)/1000)*(length(t)-1);t2=t2';t2=t2+1;
Sx1=zeros(length(t2),1);
Sy1=zeros(length(t2),1);
for i=1:length(t2)
    Sx1(i)=value_Bspline(t2(i),3,knote,cx);
    Sy1(i)=value_Bspline(t2(i),3,knote,cy);
end
