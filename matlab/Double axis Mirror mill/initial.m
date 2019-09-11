%this m.file is used to research the error compensation method in mirror
%mill mechine

% load the data
load("data/AC_R_test_origin_test_error.mat");

% produce the data of according machine tool NC code
global NC
NC=NC_code_produce();

% assume the tool length is 1, produce the ideal position of the tool point
ideal=tool_point_ideal_position_produce(NC);

adderror;
% use the number of 8 geometric errors of two swift head to simulate the 
%error measurement data
simulate_with_eight_geometric_errors;
