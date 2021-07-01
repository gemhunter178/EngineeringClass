#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
//these are in defining order below main()
//sets up board
void boardSetup(vector<vector<char>> &board);
//prints board
void displBoard(vector<vector<char>> &board);
//sets up characters for players
void playerSetup(int player, vector<vector<char>> &board);



//MAIN STARTS HERE
int main(){
	//declare board vector
	vector<vector<char>> board;
	//set up board and display it
	boardSetup(board);
	displBoard(board);
	//set up player chips
	playerSetup(1, board);
	playerSetup(2, board);
	//output board again
	cout<< "\n\n\n";
	displBoard(board);
	//makes note of what characters the players chose
	char P1_char = board[0][0];
	char P2_char = board[7][7];
	//this is the code for a square, perhaps it would make a better board
	//cout<< (char)254u;
	//debug
	//cout<< P1_char << P2_char;
}
//MAIN ENDS HERE



void boardSetup(vector<vector<char>> &board){
	vector<char> temp1;
	vector<char> temp2;
	char pushInTemp = '1';
	while(temp2.size() < 8){
		if(temp1.size() < 8){
			temp1.push_back(pushInTemp) ;
		}
		if(temp1.size() > 1){
			temp2.push_back(pushInTemp);
		}
		if(pushInTemp == '1'){
			pushInTemp = '0';
		} else {
			pushInTemp = '1';
		}
	}
	while(board.size() < 8){
		if(board.size()%2 == 0){
			board.push_back(temp1);
		} else {
			board.push_back(temp2);
		}
	}
	return;
}

void displBoard(vector<vector<char>> &board){
	int colNum = 0;
	int rowNum = 0;
	const int width = 3;
	//makes it neater
	cout<< "This is the current board:\n\n";
	while(rowNum != 8){
		cout<< setw(width) << board[rowNum][colNum];
		if(colNum == 7){
			cout<< '\n';
			rowNum++;
			colNum = 0;
		} else {
			colNum++;
		}
	}
	//bug fixing
	//cout<< board[1].size() << ' ' << board[2].size() << ' ' << board.size();
	return;
}

void playerSetup(int player, vector<vector<char>> &board){
	char playerToken;
	cout<< "\nPlayer" << player <<", please choose a character to use (no numbers): ";
	cin>> playerToken;
	//this takes only the first character.
	cin.clear();
	fflush(stdin);
	//numbwes will be used later for the game... so, the players can't use them
	while(playerToken == '1' ||
	playerToken == '2' ||
	playerToken == '3' ||
	playerToken == '4' ||
	playerToken == '5' ||
	playerToken == '6' ||
	playerToken == '7' ||
	playerToken == '8' ||
	playerToken == '9' ||
	playerToken == '0'){
		cout<< "Sorry, that character is invalid! Please choose another: ";
		cin>> playerToken;
		cin.clear();
		fflush(stdin);
	}
	int colNum = 0;
	if(player == 1){
		for(int rowNum = 0; rowNum <3; colNum++){
			if(board[rowNum][colNum] == '1'){
				board[rowNum][colNum] = playerToken;
			}
			//bug testing
			//cout<< colNum;
			if(colNum == 7){
				rowNum++;
				colNum = -1;
			}
		}
		//it's either player 1 or 2, there really isn't another else.	
	} else {
		for(int rowNum = 5; rowNum <8; colNum++){
			if(board[rowNum][colNum] == '1'){
				board[rowNum][colNum] = playerToken;
			}
			if(colNum == 7){
				rowNum++;
				colNum = -1;
			}
		}
	}
	return;
}
