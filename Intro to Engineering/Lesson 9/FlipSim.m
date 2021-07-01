runs = input('How many flips of two coins do you wish to make? ');
%first, ask for how many runs the user wants
result_matrix = zeros(1,3);
%records the results
for runNum = 1:runs
    result = flipcoin();
    if result == 'hh'
        result_matrix(1) = result_matrix(1) + 1;
        %for both heads
    elseif result == 'tt'
        result_matrix(3) = result_matrix(3) + 1;
        %for both tails
    else
        result_matrix(2) = result_matrix(2) + 1;
        %for tails heads
    end %if
end %for for simulations
barLabel = categorical(["Two Heads", "Head and Tail", "Two Tails"]);
%makes the labels
barLabel = reordercats(barLabel, {'Two Heads', 'Head and Tail', 'Two Tails'});
bar(barLabel,result_matrix);
