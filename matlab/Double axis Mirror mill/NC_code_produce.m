function NC=NC_code_produce()
as=-90;ae=90;
cs=0;ce=360;
numA=7;numC=13;
count=1;

a=zeros(numA,1);
c=zeros(numC,1);
NC=zeros(numA*numC,2);

for i=1:numA
    a(i)=as+(i-1)*(ae-as)/(numA-1);
    for j=1:numC
        if mod(i,2) == 0
          c(j)=ce-(j-1)*(ce-cs)/(numC-1);
        else
          c(j)=cs+(j-1)*(ce-cs)/(numC-1);
        end
        NC(count,1)=a(i);
        NC(count,2)=c(j);
       
         count=count+1;       
    end
end
