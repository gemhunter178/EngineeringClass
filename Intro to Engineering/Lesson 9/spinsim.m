function evens = spinsim(spins)
%simulates "spins" amounts of spins of a roulette wheel, outputs the number
%of spins that are even
evens = 0;
%starts evens at 0 if it was already used
for spinNum = 1:spins
    s_result = randi([0,36]); %simulates the actual roll
    if mod(s_result,2) == 0 %finds evens
        evens = evens + 1;
    end %if to find evens
end %for loop for spins
end %function