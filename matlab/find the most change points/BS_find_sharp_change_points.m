function y=BS_find_sharp_change_points(x,N,even_distribution)
n=length(x);
%1. :the data deal with
%2. N:the num of sharp change points to caculate
%3. even_distribution: consider the distance between of two sharp change
%points or not


%estalish the final section of change points

%y=zeros(N+2,1);%N pruning points + the start and end point

% initial y
y(1)=1;
y(2)=n;

%search for the 1th,2nd,3rd......Nth pruning points
for i=1:N
    %traversing each interval
    %initial the add pruning point and according the judgement value
    
     min_index=1;
     min_f=0;
     index_y=1;

  


    for j=1:i
        index_start=y(j);
        index_end=y(j+1);
        %find the subset sharp change(prune) points
        x_section=x(index_start:index_end);
        [index,value]=calculate_the_sharp_point(x_section,index_start);
        %value=sqrt(value/(index_end-index_start));
        value=value/length(x_section);
 
        
        if(min_f<value)
            min_f=value;
            min_index=index;
            index_y=j;
        end
    end
    %renew the interval array
    y_change=y(index_y+1:end);
    y(index_y+1)=min_index;
    for j=1:length(y_change)
        y(index_y+1+j)=y_change(j);
    end
    
    
    
end



if(even_distribution==true)
    distance_of_sharp_point=(n/(N+1))*0.4;
    new_point_distance=(n/(N+1))*1.4;
    count=1;
    %clear the y array of indexs
    y_clean=y(1);
    count_clean=1;
    for i=2:length(y)-1
        if(y(i)-y_clean(count_clean)>distance_of_sharp_point)
            count_clean=count_clean+1;
            y_clean(count_clean)=y(i);
        end
    end
    if(y(end)-y_clean(count_clean)>distance_of_sharp_point)
        y_clean(count_clean+1)=y(end);
    else
        y_clean(count_clean)=y(end);
    end
    y=y_clean;
    y_new(count)=y(1);
%     count=count+1;
%     y_new(count)=y(2);
    
    
    for i=2:length(y)
        if(y(i)-y(count)>distance_of_sharp_point)
            count=count+1;
            y_new(count)=y(i);
            
        end
    end
    iteration=50;%invalid circle times
    
    it=1;
    origin_count=count;
    while(count<N+2)
     
     if(it>iteration) 
         break
     end
    
        for i=3:count
           if(y_new(i)-y_new(i-1)>new_point_distance)
               x_section=x(y_new(i-1):y_new(i));
               [index,value]=calculate_the_sharp_point(x_section,y_new(i-1));
           
           if(index-y_new(i-1)>distance_of_sharp_point && y_new(i)-index>distance_of_sharp_point)
               count=count+1;
               origin_count=count;
               y_new(count)=index;
               y_new=sort(y_new);
           else
               if(y_new(i)-index<index-y_new(i-1))
                   y_new(i)=index;
               else
                   y_new(i-1)=index;
               end
               
           end
           end
        end
        if(count==origin_count)
            it=it+1;
        end
    end
    y=y_new;
end

   
        
           
           
               
        
        
    

    