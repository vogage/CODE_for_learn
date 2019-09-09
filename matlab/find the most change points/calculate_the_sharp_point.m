function [index,value]=calculate_the_sharp_point(x_section,index_start)
%in this x_section caculate one pruning point which devide the section into
%two parts

%and minimize the sum evaluate function by two parts
n=length(x_section);
min_index=1;
min_value=intmax;
mean_index=n/2;
for i=2:n-1
    left_section=x_section(1:i);
    right_section=x_section(i+1:end);
    left_value=i*var(left_section);
    right_value=(n-i)*var(right_section);
   
    temp_value=left_value+right_value;

    if(temp_value<min_value)
        min_value=temp_value;
        min_index=i;
    end
end
index=index_start+min_index;
value=min_value;
    
     