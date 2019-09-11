function position=tool_point_ideal_position_produce(NC)
%this function was used to produce the ideal machine tool move position 
%and under this consideration :
%we suppose the linear axis fo xyz is ideal without any movement error
%and only rotary axis participate in the movement not RTCP

n=length(NC);
xyz=zeros(n,3);
v=[0,0,1]';

%get the all change value of A axis which used to plot the reference circle in figure
count_A=1;
A_plot(1)=NC(1,1);
for i=1:n-1
    if(NC(i,1)==NC(i+1,1))
        if(A_plot(count_A)~=NC(i,1))
            count_A=count_A+1;
            A_plot(count_A)=NC(i,1);
        end
    end
end
for i=1:length(A_plot)
    A_plot(i)=A_plot(i)*pi/180;
end


%get the idael measure points position of xyz
for i=1:n
    A=NC(i,1)*pi/180;
    C=NC(i,2)*pi/180;
    rotate_A=[1,0,0;0,cos(A),-sin(A);0,sin(A),cos(A)];
    rotate_C=[cos(C),-sin(C),0;sin(C),cos(C),0;0,0,1];
    xyz(i,:)=(rotate_C*rotate_A*v)';
end
position=xyz;

%change to the plot view
Rotate_x_90=[1,0,0;0,0,-1;0,1,0];
for i=1:n
    xyz(i,:)=(Rotate_x_90*xyz(i,:)')';
end



hold on
% plot the reference sphere surface
funx=@(u,v) 0.96*cos(u).*sin(v);
funz=@(u,v) 0.96*sin(u).*sin(v);
funy=@(u,v) -0.96*cos(v);
fs=fsurf(funx,funy,funz,[0 2*pi -pi/2 pi/2]);
set(fs,'FaceColor',[0 0 1], 'FaceAlpha',0.1,'EdgeColor','none')

%plot the ideal measure points
scatter3(xyz(:,1),xyz(:,2),xyz(:,3),'.','MarkerEdgeColor','k','LineWidth',1.75)

%plot the reference circle of the measure points
circle_C=linspace(0,2*pi,360);
for i=1:length(A_plot)
     
     x1=cos(circle_C)*sin(A_plot(i));
     y1=-ones(length(circle_C),1)*cos(A_plot(i));
     z1=sin(circle_C)*sin(A_plot(i));
     plot3(x1,y1,z1,'k','LineStyle','--');
end


axis equal

Az=-68;EI=14;
view(Az,EI)

% %---------------------------------------------------------------------------------------
% %if you want to make the surf only one color,you can refer to this article
% thanks to https://stackoverflow.com/questions/492232/how-do-i-set-a-surf
%   -to-one-color-no-gradient-in-my-matlab-plot
% x = rand(1,20);
% y = rand(1,20);
% z = rand(1,20);
% 
% [X,Y] = meshgrid(linspace(0,1,10),linspace(0,1,10));
% Z = rand(10)*0.1;
% 
% clf
% plot3(x,y,z,'.');
% hold on
% h = surf(X,Y,Z)
% hold off
% 
% %% This will change the color
% colormap(copper)
% %% This will remove colordata
% set(h, 'cdata',zeros(10))
% %% This will make transparent
% alpha(0.5)
