as=-60;ae=0;
cs=0;ce=-180;
numA=9;numC=13;
fid = fopen('AC91Points.NC', 'wt');
count=1;
for i=1:numA
    a(i)=as+(i-1)*(ae-as)/(numA-1);
    for j=1:numC
        if mod(i,2) == 0
          c(j)=ce-(j-1)*(ce-cs)/(numC-1);
        else
          c(j)=cs+(j-1)*(ce-cs)/(numC-1);
        end        
        AC_code(count,1)=a(i);
        AC_code(count,2)=c(j);
        fprintf(fid,'N%d A%.1f  C%.1f \n',count,AC_code(count,1), ...
            AC_code(count,2));
        fprintf(fid,'G04 X10\n');
        count=count+1;
        plot(a(i),c(j),'*');
        hold on;
        
end
end
fclose(fid);

%[AC_element,AC_element_error]=find_AC_brick(AC,AC_error,AC_test)
AC=AC_code;
n=length(AC);
AC_error=zeros(100,3);
AC_test=zeros(100,2);
for i=1:100
    AC_test(i,1)=as+(ae-as)*rand(1);
    AC_test(i,2)=cs+(ce-cs)*rand(1);
end
xyz_error=zeros(n,3);
for i=1:length(AC_test)
    [AC_element,AC_element_error]=find_AC_brick(AC,AC_error,AC_test(i,:));
    AC_element;
    AC_element_error;
    xyz_error(i,:)=get_AC_test_error(AC_element,AC_element_error,AC_test(i,:))
end

fid = fopen('AC91Compensation.NC', 'wt');
count=1;
for i=1:length(AC_test)
    fprintf(fid,'N%d X%.3f Y%.3f Z%.3f A%.1f  C%.1f \n',count,-xyz_error(i,1),-xyz_error(i,2),-xyz_error(i,3), ....
    AC_test(count,1),AC_test(count,2));
 fprintf(fid,'G04 X10\n');
        count=count+1;
end
