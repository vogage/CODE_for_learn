%this m file is used to show the figure after add error
error=AC_R_test_origin_test_error_short_tool_length;
n=length(ideal);
global actual
actual=zeros(n,3);
for i=1:n
    actual(i,:)=ideal(i,:)+error(i,:);
end

hold on
%change to the plot coordinate
n=floor(n/2);
xyz_actual=actual(1:n,:);
xyz_ideal=ideal(1:n,:);
Rotate_x_90=[1,0,0;0,0,-1;0,1,0];
for i=1:n
    xyz_actual(i,:)=(Rotate_x_90*xyz_actual(i,:)')';
    xyz_ideal(i,:)=(Rotate_x_90*xyz_ideal(i,:)')';
end
scatter3(xyz_actual(:,1),xyz_actual(:,2),xyz_actual(:,3),'.','r');
% use the arror 
for i=1:n
    arrow3(xyz_ideal(i,:),xyz_actual(i,:),'r',0.5);
end

xyz_actual1=xyz_actual(1:13,:);
    plot3(xyz_actual1(:,1),xyz_actual1(:,2),xyz_actual1(:,3),'Color','g','LineWidth',1.3)
  xyz_actual2=xyz_actual(14:26,:);
    plot3(xyz_actual2(:,1),xyz_actual2(:,2),xyz_actual2(:,3),'Color','g','LineWidth',1.3)  
  xyz_actual3=xyz_actual(27:39,:);
    plot3(xyz_actual3(:,1),xyz_actual3(:,2),xyz_actual3(:,3),'Color','g','LineWidth',1.3)  



axis equal

Az=-99;EI=40;
view(Az,EI)



