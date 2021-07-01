/* PSEUDOCODE:
use srand(time(NULL) to make the seed more random
simulate roll of 2 dice
take sum of two dice
if sum ==7 or 11, return w, else if 2,3 or 12 return l, else retun r
if return r, run function again
if w or l, state that the player has won or lost
*/

#include <ctime>
#include <iostream>
#include <cstdlib>
#include <iomanip>

char craps();

int main(){
	std::srand(std::time(NULL));
	char gamestate;
	
	//next lines for testing the chance of winning, losing or roll agains
	int rolls;
	std::cout<< "How many rolls do you want to run?: ";
	std::cin>> rolls;
	int wins = 0;
	int lose = 0;
	int reroll = 0;
	for(int loop = 0; loop <= rolls; loop++){
		gamestate = craps();
		if(gamestate == 'w'){
			wins++;
		} else if(gamestate == 'l'){
			lose++;
		} else if(gamestate == 'r'){
			reroll++;
		} else {
			std::cout<< "Something's wrong!";
			return 1;
		}
	}
	float wins_p = ((wins + 0.0)/rolls) * 100;
	float lose_p = ((lose + 0.0)/rolls) * 100;
	float reroll_p = ((reroll + 0.0)/rolls) *100;
	const int width = 12;
	std::cout<< "\nIn " << rolls << " rolls, we have: \n" 
	<< std::left << std::setw(width) << "Won: " << wins_p << "%\n"
	<< std::left << std::setw(width) << "Lost: " << lose_p << "%\n"
	<< std::left << std::setw(width) << "Rerolled: " << reroll_p << "%";
	
	//next lines for an actual game
	/* do {
	gamestate = craps();
	} while(gamestate == 'r'); 
	if(gamestate == 'w'){
		std::cout<< "You won!";
	} else {
		std::cout<< "You lost...";
	}*/
}

char craps() {
	int roll1 = std::rand()%6 + 1;
	int roll2 = std::rand()%6 + 1;
	//comment out next line if you don't want to see your rolls
	//std::cout<< "You rolled " << roll1 << " and " << roll2 << std::endl;
	int sum = roll1 + roll2;
	if(sum == 7 || sum == 11){
		return 'w';
	} else if(sum == 2 || sum == 3 || sum ==12){
		return 'l';
	} else {
		return 'r';
	}
}
