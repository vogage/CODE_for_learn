n=length(S1);
n2=(n+1)/4;
x=zeros(n2,1);
y=zeros(n2,1);
z=zeros(n2,1);
for i=1:n2
   x(i)=S1((i-1)*4+1);
   y(i)=S1((i-1)*4+2);
   z(i)=S1((i-1)*4+3);
end
plot3(x,y,z)
axis equal
% p1=566;
% p2=567;
% p3=806;
% p4=807;
% p5=1048;
% p6=1049;
% p7=1212;
% 
% x1=x(p6:p7);
% y1=y(p6:p7);
% z1=z(p6:p7);
% p21=80;
% p22=160;
% p23=240;
% x11=x1(1:p21);
% x22=x1(p21+1:p22);
% x33=x1(p22+1:p23);
% eorror_x=x22-x11;
% eorror_x1=x33-x22;
% y11=y1(1:p21);
% y22=y1(p21+1:p22);
% y33=y1(p22+1:p23);
% eorror_y=y22-y11;
% eorror_y1=y33-y22;
% z11=z1(1:p21);
% z22=z1(p21+1:p22);
% z33=z1(p22+1:p23);
% eorror_z=z22-z11;
% eorror_z1=z33-z22;

[xc,yc,R,a] = circfit(x,y)
n=length(x);
angle=zeros(n,1);
for i=1:n
    angle(i)=atan((y(i)-yc)/(x(i)-xc));
    
end
figure(2)
plot(angle,z)
% P1=210;
% P2=417;
% P3=418;
% P4=627;
% % x1=x(1:P1);
% % y1=y(1:P1);
% % z1=z(1:P1);
% x1=x(P4:end);
% y1=y(P4:end);
% z1=z(P4:end);
% 
% % P11=12;
% % P22=33;
% P11=180;
% P22=201;
% x11=x1(P11:P22);
% y11=y1(P11:P22);
% z11=z1(P11:P22);
% 
% 
% 
% 
% z11(2:11)=z11(2:11)+5;
% n=length(x11);
% x_sqr=zeros(n,1);
% x_sqr(2)=sqrt((x11(2)-x11(1))^2+(y11(2)-y11(1))^2);
% for i=2:n
%     x_sqr(i)=sqrt((x11(i)-x11(i-1))^2+(y11(i)-y11(i-1))^2)+x_sqr(i-1);
%     
% end
% x_sqr2=x_sqr(12:end)-x_sqr(12);
% x_sqr2=x_sqr2(1:end);
% z11_2=z11(12:end);
% z11_2=flip(z11_2);
% 
% plot(x_sqr(1:11),z11(1:11),'o') 
% hold on
% plot(x_sqr2,z11_2)
% yend=z11(11)-z11(1);
% xend=x_sqr(11)-x_sqr(1);
% t=yend/xend;
% y_end=zeros(11,1);
% for i=1:11
%     y_end(i)=x_sqr(i)*t+z11(1);
% end
% figure(2)
% plot(x_sqr(1:11),y_end(1:11)-z11(1:11))
% hold on
% plot(x_sqr2,y_end(1:11)-z11_2)
P1=233;
P2=253;
x1=x(P1:P2);
y1=x(P1:P2);
z1=z(P1:P2);
angle1=angle(P1:P2);
plot(angle1,z1)

P3=506;
P4=526;
x2=x(P3:P4);
y2=y(P3:P4);
z2=z(P3:P4);
angle2=angle(P3:P4);
plot(angle2,z2)

P5=758;
P6=778;
x3=x(P5:P6);
y3=y(P5:P6);
z3=z(P5:P6);
angle3=angle(P5:P6);
plot(angle3,z3)

P7=1218;
P8=1238;
%往复运动开始的方向不同，取点的方式也不同
x4=x(P7:P8);
y4=y(P7:P8);
z4=z(P7:P8);
angle4=angle(P7:P8);
plot(angle4,z4)









n1=length(angle1);
n1=floor(n1/2)+1;
t1=(z1(n1)-z1(1))/(angle1(n1)-angle1(1));
angle2z2=zeros(n1,1);
for i=1:n1
    angle2z2(i)=z1(1)+t1*(angle1(n1)-angle1(1))*(i-1)/(n1-1);
end
plot(angle1(1:n1),angle2z2)


n2=length(angle2);
n2=floor(n2/2)+1;
t2=(z2(n2)-z2(1))/(angle2(n2)-angle2(1));
angle2z2=zeros(n1,1);
for i=1:n1
    angle2z2(i)=z2(1)+t2*(angle2(n1)-angle2(1))*(i-1)/(n1-1);
end
plot(angle2(1:n2),angle2z2)

n3=length(angle3);
n3=floor(n3/2)+1;
t3=(z3(n3)-z3(1))/(angle3(n3)-angle3(1));
angle3z3=zeros(n3,1);
for i=1:n3
    angle3z3(i)=z3(1)+t3*(angle3(n3)-angle3(1))*(i-1)/(n3-1);
end
plot(angle3(1:n3),angle3z3)

n4=length(angle4);
n4=floor(n4/2)+1;
t4=(z4(n4)-z4(1))/(angle4(n4)-angle4(1));
angle4z4=zeros(n4,1);
for i=1:n4
    angle4z4(i)=z4(1)+t4*(angle4(n4)-angle4(1))*(i-1)/(n4-1);
end
plot(angle4(1:n4),angle4z4)

