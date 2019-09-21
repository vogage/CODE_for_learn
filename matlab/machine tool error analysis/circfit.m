function [xc,yc,R,a] = circfit(x,y)
%Բ��Ϻ���%CIRCFIT Fits a circle in x,y plane
% [XC, YC, R, A] = CIRCFIT(X,Y)
% Result is center point (yc,xc) and radius R.A is an
% optional output describing the circle��s equation:%
% x^2+y^2+a(1)*x+a(2)*y+a(3)=0
% by Bucher izhak 25/oct/1991
n=length(x); 
xx=x.*x; 
yy=y.*y; 
xy=x.*y;
A=[sum(x) sum(y) n;sum(xy) sum(yy)...
    sum(y);sum(xx) sum(xy) sum(x)];
    B=[-sum(xx+yy) ; -sum(xx.*y+yy.*y) ; -sum(xx.*x+xy.*y)];
    a=A\B;            %x = A\B ����������Է��� A*x = B.  A �� B ������һ��.
    xc = -.5*a(1);
    yc = -.5*a(2);
    R = sqrt((a(1)^2+a(2)^2)/4-a(3)); 
    theta=0:0.1:2*pi;      
    Circle1=xc+R*cos(theta);      
    Circle2=yc+R*sin(theta);       
    plot(Circle1,Circle2,'g','linewidth',1);      
    axis equal      
end  
% ��������������������������������
% ��Ȩ����������ΪCSDN������Msjiangmei����ԭ�����£���ѭ CC 4.0 BY-SA ��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
% ԭ�����ӣ�https://blog.csdn.net/Msjiangmei/article/details/82970788