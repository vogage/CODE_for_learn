n=length(XY_CW);
Er=XY_CW;
angle=((1:n)/n)*2*pi;
r=1;
R=10;
for i=1:n
    y(i)=r*cos(angle(i));
    d=r*sin(angle(i));
    half=asin((d/2)/R);
    fi=half*2;
    z(i)=R*cos(fi)-R;
    x(i)=R*sin(fi);
    error_vector=[x(i),y(i),z(i)]-[0,r,0];
    new_xyz=[x(i),y(i),z(i)]+Er(i)*error_vector;
    x_error(i)=new_xyz(1);
    y_error(i)=new_xyz(2);
    z_error(i)=new_xyz(3);
    
end
plot3(x,y,z)
hold on
plot3(x_error,y_error,z_error)
view(114,31)







% 
% for i=1:n
%     x(i)=0.5*cos(angle(i));
%     y(i)=0.5*sin(angle(i));
%     %初始的时候球杆仪是下方竖着的状态
%     x_error(i)=(0.5+XY(i))*cos(-pi/2+angle(i));
%     y_error(i)=(0.5+XY(i))*sin(-pi/2+angle(i));
% end
% 
% plot(x,y)
% hold on
% plot(x_error,y_error)