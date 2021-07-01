%This was made for homework set 10

TradeVal = [3,1,3;2,2,4;4,1,3];
NETraded = [10,12,11]';
%first, set up the two matrices, the second is made vertical for the
%equation to work. These are based off of the equations given

EquVal = TradeVal\NETraded;
%Then, using these matricies, solve for how much a NEBit is worth in
%different currencies. The \ operator in this case is equivalent to the
%inverse of the first times the second.

format = "The value of 1 NEBit is equal to %3.2f USD\n";
fprintf(format,EquVal(3));
%prints output for USD

ammtowned = 100;
USDEq = ammtowned * EquVal(3);
format = "My %3.0i NEBits are worth %5.2f USD\n";
fprintf(format,ammtowned,USDEq);
%Outputs the ammount I have

%This neglects trade values between real currency (though which type of
%Yuan is not specified) and would probably violate some legal stuff if done
%right now (We cannot, in most cases, get cash from our HuskyCard account)