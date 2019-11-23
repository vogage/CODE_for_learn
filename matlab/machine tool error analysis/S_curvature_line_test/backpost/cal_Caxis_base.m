function C=cal_Caxis_base(i,j)
%this function was used to calculate the C axis 
%by the APT file(the coordinate of tool)
if(j>0&&i>0)
    C=atan(i/j);
elseif(i>0&&j<0)
    C=2*pi-abs(atan(i/j));
elseif(i<0&&j>0)
    C=pi-abs(atan(i/j));
else
    C=pi+atan(i/j);
end
C=C*180/pi;
