S=load("S_curvature.mat");
figure(1);%这是第一张图，用来画S型曲线
hold on
S=S.S_curvature;
n=length(S);
for i=1:n
    plot3([S(i,1) S(i,4)],[S(i,2) S(i,5)],[S(i,3) S(i,6)],'LineWidth',2,'Color','k')
end
for i=1:n-1
    plot3([S(i,1) S(i+1,1)],[S(i,2) S(i+1,2)],[S(i,3) S(i+1,3)],'LineWidth',2,'Color','r')
end
for i=1:n-1
    plot3([S(i,4) S(i+1,4)],[S(i,5) S(i+1,5)],[S(i,6) S(i+1,6)],'LineWidth',2,'Color','r')
end

figure(2) %这是第二张图，用来将刀尖点统一为一个点
hold on

S2=S(:,4:6)-S(:,1:3);
for i=1:n
    plot3([S2(i,1) 0],[S2(i,2) 0],[S2(i,3) 0],'LineWidth',2,'Color','k')
end
for i=1:n-1
    plot3([S2(i,1) S2(i+1,1)],[S2(i,2) S2(i+1,2)],[S2(i,3) S2(i+1,3)],'LineWidth',2,'Color','r')
end


figure(3) %这是第三张图，用来刻画刀轴角度的变化
S_axis_angle=zeros(50,1);
for i=1:n
  S_axis_angle(i)=( 180* atan(sqrt(S2(i,1)^2+S2(i,2)^2)/S2(i,3)))/pi;
  if(S2(i,2)<0)
      S_axis_angle(i)=-S_axis_angle(i);
  end
end
plot(S_axis_angle,'LineWidth',2,'Color','k')


figure(4) %这是第四张图，用来反映两个标准球相距分别为20mm，30mm，40mm，50mm的移动距离情况
hold on
S_axis_move20=zeros(50,1);
S_axis_move30=zeros(50,1);
S_axis_move40=zeros(50,1);
S_axis_move50=zeros(50,1);

for i=1:50
    S_axis_move20(i)=tan(S_axis_angle(i)*pi/180)*20;
    S_axis_move30(i)=tan(S_axis_angle(i)*pi/180)*30;
    S_axis_move40(i)=tan(S_axis_angle(i)*pi/180)*40;
    S_axis_move50(i)=tan(S_axis_angle(i)*pi/180)*50;
end
plot(S_axis_move20,'LineWidth',2);
plot(S_axis_move30,'LineWidth',2);
plot(S_axis_move40,'LineWidth',2);
plot(S_axis_move50,'LineWidth',2);
