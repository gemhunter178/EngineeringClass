%This script is made to find the number of evens found in 10 roulette spins
runs = input('How many 10 spins of a roulette wheel do you wish to simulate? ');
%to get how many runs
even_mat = zeros(1,11);
%matrix for the number of evens found
for runNum = 1:runs %runs "runs" many simulations
    result = spinsim(10);
    %gets the number of evens from 10 spins
    even_mat(result + 1) = even_mat(result + 1) + 1;
    %this increments the appropriate index as spinsim is from 0-10, but the
    %matrix is from 1-11
end %for for simulations
x_labels = 0:10;
%gives appropriate labels (starts at 0 vs 1)
bar(x_labels,even_mat);
xlabel("Number of Evens in 10 spins");
ylabel("Occurance");
title("Number of Evens in Roulette Spins");