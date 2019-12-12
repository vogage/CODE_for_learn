function [AC_element,AC_element_error]=find_AC_brick(AC,AC_error,AC_test)
AC_element=zeros(4,2);

AC_element_error=zeros(4,3);
n=length(AC);

%初始化AC_element
for i=1:4
AC_element(i,:)=[1000,1000];

end
at=AC_test(1,1);
ct=AC_test(1,2);
 
for i=1:n
    
    a=AC(i,1);
    c=AC(i,2);
    er=AC_error(i,:);
     r_temp=(a-at)^2+(c-ct)^2;
    if(a<=at)
        if(c<=ct)
        %左上
  
        r_origin=(AC_element(1,1)-at)^2+(AC_element(1,2)-ct)^2;
            if(r_temp<r_origin)
            AC_element(1,1)=a;
            AC_element(1,2)=c;
            AC_element_error(1,:)=er;
            end
          else
            %左下
            
                     r_origin=(AC_element(2,1)-at)^2+(AC_element(2,2)-ct)^2;
                if(r_temp<r_origin)
                    AC_element(2,1)=a;
                     AC_element(2,2)=c;
                    AC_element_error(2,:)=er;
                end
         end
    
    else
            if(c>=ct)
                    %右上
                r_origin=(AC_element(3,1)-at)^2+(AC_element(3,2)-ct)^2;
                     if(r_temp<r_origin)
                        AC_element(3,1)=a;
                        AC_element(3,2)=c;
                        AC_element_error(3,:)=er;
                     end
                else
            %右下
                     r_origin=(AC_element(4,1)-at)^2+(AC_element(4,2)-ct)^2;
                         if(r_temp<r_origin)
                             AC_element(4,1)=a;
                             AC_element(4,2)=c;
                              AC_element_error(4,:)=er;
                         end
            end
    end
end   
    
    
