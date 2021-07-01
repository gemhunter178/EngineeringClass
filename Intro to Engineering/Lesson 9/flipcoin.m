function flipResult = flipcoin()
    coin1 = rand(1);
    coin2 = rand(1);
    
    if(coin1 >= .5 && coin2 > 0.5)
        flipResult = "hh";
    elseif(coin1 < 0.5 && coin2 <= 0.5)
        flipResult = "tt";
    else
        flipResult = "ht";
    end; %if
end

