function  [difference_before,difference_after, first_deviation_before,first_deviation_after]  ...
=evalution_NC_code(w_before,w_end)

global U   %           U:the knotes
%global points1
global at_solve
%global tool_radius
global P

n=length(w_before);
m=n/5;
control(:,1)=w_before(1:m);
control(:,2)=w_before(m+1:2*m);
control(:,3)=w_before(2*m+1:3*m);
control(:,4)=w_before(3*m+1:4*m);
control(:,5)=w_before(4*m+1:5*m);

P=control;
[at_solve,dif_distance]=gradient_solve_at(at_solve);
difference_before=dif_distance;

u=(0:1:1000)/1000;
first_deviation_before=zeros(length(u),2);

 C=control(:,4);
 A=control(:,5);
 p=3;
 d=2;
 n=length(C);
 first_deviation_before(:,1)=CurveDerivsAlg3(n-1,p,U,C,u,d,2);
 first_deviation_before(:,2)=CurveDerivsAlg3(n-1,p,U,A,u,d,2);
 

control(:,1)=w_end(1:m);
control(:,2)=w_end(m+1:2*m);
control(:,3)=w_end(2*m+1:3*m);
control(:,4)=w_end(3*m+1:4*m);
control(:,5)=w_end(4*m+1:5*m);
P=control;
[at_solve,dif_distance]=gradient_solve_at(at_solve);
difference_after=dif_distance;

first_deviation_after=zeros(length(u),2);

 C=control(:,4);
 A=control(:,5);

 first_deviation_after(:,1)=CurveDerivsAlg3(n-1,p,U,C,u,d,2);
 first_deviation_after(:,2)=CurveDerivsAlg3(n-1,p,U,A,u,d,2);
    
    
    
