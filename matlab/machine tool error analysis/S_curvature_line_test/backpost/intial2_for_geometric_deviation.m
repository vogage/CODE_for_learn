clc;clear;
data=load("S_curvature.mat");
data=data.S_curvature;
angle=data(:,4:6);
n=length(data);

r=6;
p=3;
[m,U,P]=GlobalCurveInterp(n-1,data,r,p);
t=(1:1000)/1000;
a=0.01;
S=zeros(length(t),3);
S_dif_a=zeros(length(t),3);
S_dif_t=zeros(length(t),3);
for i=1:length(t)
    S(i,:)=cal_point_of_tool_axis_surface(a,t(i),P,U);
    S_dif_a(i,:)=diff_a_point_of_tool_axis_surface(a,t(i),P,U);
    S_dif_t(i,:)=diff_t_point_of_tool_axis_surface(a,t(i),P,U);
end