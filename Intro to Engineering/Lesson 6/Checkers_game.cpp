#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
//these are in defining order below main()
//sets up board
void boardSetup(vector<vector<char>> &board, char white, char black);
//prints board
void displBoard(vector<vector<char>> board);
//sets up characters for players
void playerSetup(int player, vector<vector<char>> &board, char P1_char);
//sets up movestate stuff
int checkMoves(bool P1turn, char P1_char, char P2_char, char white, vector<vector<char>> board, vector<vector<int>> &turnstate);
//displays all relevant variables not easily seen
void debug(int TurnStateReturn, bool P1turn, vector<vector<int>> &turnstate);
//debug is being funny, so right now I need the turnstate to output, that's all
void displturnstate(vector<vector<int>> turnstate);
//finally, lets start moving things
void moveTurn(bool &P1turn, char P1_char, char P2_char, char white, int TurnState, vector<vector<char>> &board, vector<vector<int>> &turnstate);
//checks how many tokens a player has
int totalP1tokens(char P1_char, char P1_crown, vector<vector<char>> board);
int totalP2tokens(char P2_char, char P2_crown, vector<vector<char>> board);
//checks if a crown is made this turn
void checkCrown(char P1_char, char P2_char, char &P1_crown, char &P2_crown, vector<vector<char>> board);



//MAIN STARTS HERE
int main(){
	//Welcome message
	cout<< "Welcome to [my] checkers v1.0! \nPlease refer to https://www.itsyourturn.com/t_helptopic2030.html for rules\n\n";
	//declare "colors"
	char white = '1'; //(char)176u
	char black = '0'; //(char)254u is a filled square
	//declare board vector
	vector<vector<char>> board;
	//set up board and display it
	boardSetup(board, white, black);
	cout<< "This is the current board:\n\n";
	displBoard(board);
	//set up player chips
	playerSetup(1, board, '0');
	//makes note of what characters the players chose
	char P1_char = board[0][0];
	playerSetup(2, board, P1_char);
	char P2_char = board[7][7];
	//output board again
	cout<< "\n\n\n";
	displBoard(board);
	cout<< "\n\n";	
	//Actual game stuff starts here
	vector<vector<int>> turnstate;
	vector<int> zeroes = {0,0,0,0,0,0,0,0};
	while(turnstate.size() < 8){
		turnstate.push_back(zeroes);
		//cout<< turnstate[0].size();
	}
	int TurnStateReturn;
	bool P1turn = 1;
	//future crowns (crown is what I'm calling king/queens)
	//this is a character that is not recognized in cin, so it should not be accidentally entered
	char P1_crown = ' ';
	char P2_crown = ' ';
	//total tokens left
	int P1count;
	int P2count;
	short loseCondition = 0;
	while(loseCondition == 0){
		if(P1turn == 1){
			cout<< "It's your turn, Player 1!\n";
		} else {
			cout<< "It's your turn, Player 2!\n";
		}
		//checks for valid moves
		TurnStateReturn = checkMoves(P1turn, P1_char, P2_char, white, board, turnstate);
		//simple solution for stalemate for now
		if(TurnStateReturn == 0){
			cout<< "\nSeems you have no moves left! Stalemate!";
			return 1;
		}
		moveTurn(P1turn, P1_char, P2_char, white, TurnStateReturn, board, turnstate);
		checkCrown(P1_char, P2_char, P1_crown, P2_crown, board);
		P1count = totalP1tokens(P1_char, P1_crown, board);
		P2count = totalP2tokens(P2_char, P2_crown, board);
		//output current standing in terms of pieces, also part debug
		cout<< "Here's the current standing: \nPlayer 1, you have " << P1count << " checkers left" << endl;
		cout<< "Player 2, you have " << P2count << " checkers left" << "\n\n";
		if(P1count == 0){
			loseCondition = 1;
		}
		if(P2count == 0){
			loseCondition = 2;
		}
		//displturnstate(turnstate);
		//loseCondition = 1; //for now, until I make the win condition
		//displturnstate(turnstate);
	}
	
	//this is the code for a square, perhaps it would make a better board
	//cout<< (char)254u;
	//debug
	//cout<< P1_char << P2_char;
	return 0;
}
//MAIN ENDS HERE



void boardSetup(vector<vector<char>> &board, char white, char black){
	vector<char> temp1;
	vector<char> temp2;
	char pushInTemp = white;
	while(temp2.size() < 8){
		if(temp1.size() < 8){
			temp1.push_back(pushInTemp) ;
		}
		if(temp1.size() > 1){
			temp2.push_back(pushInTemp);
		}
		if(pushInTemp == white){
			pushInTemp = black;
		} else {
			pushInTemp = white;
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

void displBoard(vector<vector<char>> board){
	int colNum = 0;
	int rowNum = 0;
	const int width = 3;
	//makes it neater
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

void playerSetup(int player, vector<vector<char>> &board, char P1_char){
	char playerToken;
	cout<< "\nPlayer" << player <<", please choose a character to use (no numbers): ";
	cin>> playerToken;
	//this takes only the first character.
	cin.clear();
	fflush(stdin);
	//numbers will be used later for the game... so, the players can't use them
	while(playerToken == '1' ||
	playerToken == '2' ||
	playerToken == '3' ||
	playerToken == '4' ||
	playerToken == '5' ||
	playerToken == '6' ||
	playerToken == '7' ||
	playerToken == '8' ||
	playerToken == '9' ||
	playerToken == '0' ||
	playerToken == P1_char){
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

int checkMoves(bool P1turn, char P1_char, char P2_char, char white, vector<vector<char>> board, vector<vector<int>> &turnstate){
	//these vaiables basically make a switch statement
	char checkchar;
	char oppchar;
	short P1_dir;
	if(P1turn == 1){
		checkchar = P1_char;
		oppchar = P2_char;
		P1_dir = 1;
	} else {
		checkchar = P2_char;
		oppchar = P1_char;
		P1_dir = -1;
	}
	//yes, if there are no moves, it WILL return 0
	int turnstatereturn = 0;
	//checks for available moves and what type (it won't check if a more dominant move type has been detected)
	int colNum = 0;
	for(int rowNum = 0; rowNum < 8; colNum++){
		if(board[rowNum][colNum] == checkchar){
			if((board[rowNum + P1_dir][colNum + 1] == oppchar && board[rowNum + 2 * P1_dir][colNum + 2] == white) || (board[rowNum + P1_dir][colNum - 1] == oppchar && board[rowNum + 2 * P1_dir][colNum - 2] == white)){
				turnstate[rowNum][colNum] = 2;
				turnstatereturn = 2;
			} else if((board[rowNum + P1_dir][colNum + 1] == white || board[rowNum + P1_dir][colNum - 1] == white ) && turnstatereturn != 2){
				turnstate[rowNum][colNum] = 1;
				turnstatereturn = 1;
				//cout<< "1";
			}
		}
		if(colNum ==7){
			colNum = -1;
			rowNum++;
		}
	}
	//returns highest dominance
	return turnstatereturn;
}

void debug(int TurnStateReturn, bool P1turn, vector<vector<int>> turnstate){
	cout<< "\n\n\n\nDEBUG\n\nTurnStateReturn: " << TurnStateReturn << endl;
	cout<< "P1turn: " << P1turn << endl;
	int colNum = 0;
	int rowNum = 0;
	const int width = 3;
	cout<< "This is the current turnstate:\n\n";
	while(rowNum != 8){
		cout<< setw(width) << turnstate[rowNum][colNum];
		if(colNum == 7){
			cout<< '\n';
			rowNum++;
			colNum = 0;
		} else {
			colNum++;
		}
	}
	return;
} 

void displturnstate(vector<vector<int>> turnstate){
	//same as the earlier display, but for a 2D int vector
	int colNum = 0;
	int rowNum = 0;
	const int width = 3;
	cout<< "\n\nThis is the current turnstate:\n\n";
	while(rowNum != 8){
		cout<< setw(width) << turnstate[rowNum][colNum];
		if(colNum == 7){
			cout<< '\n';
			rowNum++;
			colNum = 0;
		} else {
			colNum++;
		}
	}
	return;
}
//this next one is absurdly long and probably deserves to be split up...
void moveTurn(bool &P1turn, char P1_char, char P2_char, char white, int TurnState, vector<vector<char>> &board, vector<vector<int>> &turnstate){
	int colNum = 0;
	int rowNum = 0;
	cout<< "These are the pieces with valid moves\n";
	while(rowNum != 8){
		if(turnstate[rowNum][colNum] == TurnState) {
			cout<< rowNum + 1 << ", " << colNum + 1 << endl;
		}
		if(colNum == 7){
			rowNum++;
			colNum = 0;
		} else {
			colNum++;
		}
	}
	cout<< "Which row, column (in that form) piece do you wish to move? ";
	int selectRow;
	int selectCol;
	//gets the right variables in the right place
	cin>> selectRow;
	//ignores the comma I told players to enter
	cin.ignore(10, ',');
	cin>> selectCol;
	cin.clear();
	fflush(stdin);
	//these pluses and minuses adjust how the code and how people interpret rows and columns
	selectRow--;
	selectCol--;
	//debug
	//cout<< "  " << selectRow << "  " << selectCol;
	while(turnstate[selectRow][selectCol] != TurnState){
		cout<< "\nThat coordinate is invalid! please choose another in the form row, column ";
		//repeats lines I used for input above
		cin>> selectRow;
		cin.ignore(10, ',');
		cin>> selectCol;
		cin.clear();
		fflush(stdin);
		selectRow--;
		selectCol--;
	}
	//maybe I should've made this into main or a function
	char checkchar;
	char oppchar;
	short P1_dir;
	if(P1turn == 1){
		checkchar = P1_char;
		oppchar = P2_char;
		P1_dir = 1;
	} else {
		checkchar = P2_char;
		oppchar = P1_char;
		P1_dir = -1;
	}
	//UI for choosing a move
	if(TurnState == 1){
		if(board[selectRow + P1_dir][selectCol + 1] == white){
			//this is why I reserved characters
			board[selectRow + P1_dir][selectCol + 1] = '2';
		}
		if(board[selectRow + P1_dir][selectCol - 1] == white){
			board[selectRow + P1_dir][selectCol - 1] = '3';
		}
	}
	if(TurnState == 2){
		if(board[selectRow + P1_dir][selectCol + 1] == oppchar && board[selectRow + 2 * P1_dir][selectCol + 2] == white){
			board[selectRow + 2 * P1_dir][selectCol + 2] = '2';
		}
		if(board[selectRow + P1_dir][selectCol - 1] == oppchar && board[selectRow + 2 * P1_dir][selectCol - 2] == white){
			board[selectRow + 2 * P1_dir][selectCol - 2] = '3';
		}
	}
	//display board again
	cout<< "\n\n";
	displBoard(board);
	char moveChoice;
	//only changes if move is valid
	bool moveSuccess = 0;
	//input the move choice!
	cout<< "\n\nPlease choose a number to move to: ";
	while(moveSuccess == 0){
		cin>> moveChoice;
		cin.clear();
		fflush(stdin);
		//defines what happens if a move is taken, written on board vector
		if(board[selectRow + P1_dir][selectCol + 1] == moveChoice){
			board[selectRow + P1_dir][selectCol + 1] = checkchar;
			board[selectRow][selectCol] = white;
			moveSuccess = 1;
		} else if(board[selectRow + P1_dir][selectCol - 1] == moveChoice){
			board[selectRow + P1_dir][selectCol - 1] = checkchar;
			board[selectRow][selectCol] = white;
			moveSuccess = 1;
		} else if(board[selectRow + 2 * P1_dir][selectCol + 2] == moveChoice){
			board[selectRow + 2 * P1_dir][selectCol + 2] = checkchar;
			board[selectRow + P1_dir][selectCol + 1] = white;
			board[selectRow][selectCol] = white;
			moveSuccess = 1;
		} else if(board[selectRow + 2 * P1_dir][selectCol - 2] == moveChoice){
			board[selectRow + 2 * P1_dir][selectCol - 2] = checkchar;
			board[selectRow + P1_dir][selectCol - 1] = white;
			board[selectRow][selectCol] = white;
			moveSuccess = 1;
		} else {
			cout<< "\nThat move is invalid, please choose another ";
		}
	}
	//clears leftover UI
	if(TurnState == 1){
		if(board[selectRow + P1_dir][selectCol + 1] == '2'){
			board[selectRow + P1_dir][selectCol + 1] = white;
		}
		if(board[selectRow + P1_dir][selectCol - 1] == '3'){
			board[selectRow + P1_dir][selectCol - 1] = white;
		}
	}
	if(TurnState == 2){
		if(board[selectRow + 2 * P1_dir][selectCol + 2] == '2'){
			board[selectRow + P1_dir][selectCol + 1] = white;
		}
		if(board[selectRow + 2 * P1_dir][selectCol - 2] == '3'){
			board[selectRow + P1_dir][selectCol - 1] = white;
		}
	}
	//If there are additional jumps from that piece that just jumped.....
	bool extramoves = 1;
	if(TurnState == 2){
		while(extramoves == 1){
			//resetting "select coordinate"
			if(moveChoice == '2'){
				selectRow = selectRow + 2 * P1_dir;
				selectCol = selectCol + 2;
			}
			if(moveChoice == '3'){
				selectRow = selectRow + 2 * P1_dir;
				selectCol = selectCol - 2;
			}//already accounting for crowns
			if(moveChoice == '4'){
				selectRow = selectRow - 2 * P1_dir;
				selectCol = selectCol + 2;
			}
			if(moveChoice == '5'){
				selectRow = selectRow - 2 * P1_dir;
				selectCol = selectCol - 2;
			}
			//I'm going to do the checking and moving in this loop, and it WILL be a pain.
			//placing UI
			//check if there IS a valid move
			if(/*selectRow + 1 < 8 && selectCol + 1 < 8 && selectRow - 1 >= 0 && selectCol - 1 >= 0 &&*/
			((board[selectRow + P1_dir][selectCol + 1] == oppchar && board[selectRow + 2 * P1_dir][selectCol + 2] == white) ||
			(board[selectRow + P1_dir][selectCol - 1] == oppchar && board[selectRow + 2 * P1_dir][selectCol - 2] == white))
			/*there needs to be an exception so it doesn't check parts not in the vector....*/){
				//actually executes UI placement
				if(board[selectRow + P1_dir][selectCol + 1] == oppchar && board[selectRow + 2 * P1_dir][selectCol + 2] == white){
					//jump to the right
					board[selectRow + 2 * P1_dir][selectCol + 2] = '2';
				}
				if(board[selectRow + P1_dir][selectCol - 1] == oppchar && board[selectRow + 2 * P1_dir][selectCol - 2] == white){
					//jump to the left
					board[selectRow + 2 * P1_dir][selectCol - 2] = '3';
				}
			} else {
				extramoves = 0;
			}
			//let's hope I copied all that correctly.... (from my own code earlier)
			if(extramoves == 1){
				moveSuccess = 0;
				cout<< "\n\n";
				displBoard(board);
				cout<< "\n\nPlease choose another number to move to, you have extra jumps: ";
				while(moveSuccess == 0){
					cin>> moveChoice;
					cin.clear();
					fflush(stdin);
					//defines what happens if a move is taken, written on board vector
					if(board[selectRow + 2 * P1_dir][selectCol + 2] == moveChoice){
						board[selectRow + 2 * P1_dir][selectCol + 2] = checkchar;
						board[selectRow + P1_dir][selectCol + 1] = white;
						board[selectRow][selectCol] = white;
						moveSuccess = 1;
					} else if(board[selectRow + 2 * P1_dir][selectCol - 2] == moveChoice){
						board[selectRow + 2 * P1_dir][selectCol - 2] = checkchar;
						board[selectRow + P1_dir][selectCol - 1] = white;
						board[selectRow][selectCol] = white;
						moveSuccess = 1;
					} else {
						cout<< "\nThat move is invalid, please choose another ";
					}
				}
			}
			//eliminates leftover UI
			if(board[selectRow + 2 * P1_dir][selectCol + 2] == '2'){
				board[selectRow + 2 * P1_dir][selectCol + 2] = white;
			}
			if(board[selectRow + 2 * P1_dir][selectCol - 2] == '3'){
				board[selectRow + 2 * P1_dir][selectCol - 2] = white;
			}
		}
	}
	//display board
	cout<< "\n\n\n\n\n\n\nThe board is now...\n\n";
	displBoard(board);
	cout<< "\n\n";
	//clears the turnstate vector
	for(int loop = 0; loop < 8; loop++){
		turnstate[loop] = {0,0,0,0,0,0,0,0};
	}
	//changes turn to other player
	if(P1turn == 1){
		P1turn = 0;
	} else {
		P1turn = 1;
	}

/*Reset everything in turnstate to 0
Change P1_turn to its opposite
Return;*/
	return;
}

int totalP1tokens(char P1_char, char P1_crown, vector<vector<char>> board){
	int count = 0;
	int colNum = 0;
	int rowNum = 0;
	while(rowNum != 8){
		if(board[rowNum][colNum] == P1_char || board[rowNum][colNum] == P1_crown){
			//finds number of pieces
			count++;
		}
		if(colNum == 7){
			rowNum++;
			colNum = 0;
		} else {
			colNum++;
		}
	}
	return count;
}

int totalP2tokens(char P2_char, char P2_crown, vector<vector<char>> board){
	//same as the other one, for P2
	int count = 0;
	int colNum = 0;
	int rowNum = 0;
	while(rowNum != 8){
		if(board[rowNum][colNum] == P2_char || board[rowNum][colNum] == P2_crown){
			count++;
		}
		if(colNum == 7){
			rowNum++;
			colNum = 0;
		} else {
			colNum++;
		}
	}
	return count;
}

void checkCrown(char P1_char, char P2_char, char &P1_crown, char &P2_crown, vector<vector<char>> board){
	for(int colNum = 0; colNum < 8; colNum++) {
		//check for crownable pieces
		if(board[0][colNum] == P2_char){
			//allow input for first-time crowner
			if(P2_crown == ' '){
				//basically copied from playerSetup
				char playerToken;
				cout<< "Congrats, Player 2! You have crowned a piece! \nPlease enter the symbol you'd like your crowns to show as: ";
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
				playerToken == '0' ||
				playerToken == P1_char ||
				playerToken == P2_char ||
				playerToken == P1_crown){
					cout<< "Sorry, that character is invalid! Please choose another: ";
					cin>> playerToken;
					cin.clear();
					fflush(stdin);
				}
				P2_crown = playerToken;
			}
			board[0][colNum] = P2_crown;
		}
		if(board[7][colNum] == P1_char){
			//allow input for first-time crowner
			if(P1_crown == ' '){
				//basically copied from playerSetup
				char playerToken;
				cout<< "Congrats, Player 1! You have crowned a piece! \nPlease enter the symbol you'd like your crowns to show as: ";
				cin>> playerToken;
				//this takes only the first character.
				cin.clear();
				fflush(stdin);
				while(playerToken == '1' ||
				playerToken == '2' ||
				playerToken == '3' ||
				playerToken == '4' ||
				playerToken == '5' ||
				playerToken == '6' ||
				playerToken == '7' ||
				playerToken == '8' ||
				playerToken == '9' ||
				playerToken == '0' ||
				playerToken == P1_char ||
				playerToken == P2_char ||
				playerToken == P2_crown){
					cout<< "Sorry, that character is invalid! Please choose another: ";
					cin>> playerToken;
					cin.clear();
					fflush(stdin);
				}
				P2_crown = playerToken;
			}
			board[0][colNum] = P2_crown;
		}
	}
	return;
}


