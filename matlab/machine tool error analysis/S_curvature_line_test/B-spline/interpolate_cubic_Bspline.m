function control=interpolate_cubic_Bspline(x,y,d)

%��� Basis2 ʳ��
m=length(x);
Ac=zeros(m+2,m+2);

%vector knote  t=(ti) i=1:m+d+1��Ҫ�������� t(i+d+1)>t(i)
%�����Ʋ⣬��Ϊ����ڵ��ѡȡ���ǱȽ����ɣ�����������

%   knote=zeros(length(x)+2*d-2,1);
%   knote(1:d+1)=x(1);
%   knote(d+2:length(x)+d-3)=x(3:end-2);
%   knote(length(x)+d-2:end)=x(end);

%�ڽڵ�ͷβ���������죬�������ʱ���ڶ������ڵ�����
%2019-11-19
knote=zeros(length(x)+2*d,1);
%knote(1:d)=x(1)-0.01*x(1);
knote(1:d)=x(1);
knote(d+1:length(x)+d)=x;
knote(length(x)+d+1:length(x)+2*d+1)=x(end)+x(2)-x(1);

for i=1:m
  
        Ac(i+1,i)=Basis2(i,d,x(i),knote);
         Ac(i+1,i+1)=Basis2(i+1,d,x(i),knote);
          Ac(i+1,i+2)=Basis2(i+2,d,x(i),knote);
end

Ac(1,1)=D_Bspline(1,d,x(1),knote);
Ac(1,2)=D_Bspline(2,d,x(1),knote);
Ac(m+2,m+2)=D_Bspline(m+2,d,x(m),knote);
Ac(m+2,m+1)=D_Bspline(m+1,d,x(m),knote);
%dyx1=(y(2)-y(1))/(x(2)-x(1));
%dyxend=(y(end)-y(end-1))/(x(end)-x(end-1));
y=[1;y;1];


control=Ac\y;





