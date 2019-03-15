/*
TIC-TAC-TOE
Mark Sayong
E-mail: Mbenneth7@yahoo.com
*/


#include <iostream>
#include <string>
#define SIZE 9 // defined size of grid
using namespace std;

//PROTOTYPE FUNCTIONS

void initializeGrid(char grid[]);
void displayGrid(char grid[]);
int switchGetTurn(char grid[], bool pTurn);
void Go(char grid[], bool p2Turn, int choice);
bool isFree(char input);
bool isFull(char grid[]);
bool isWinner(char grid[]);
bool winRow(char grid[]);
bool winDiag(char grid[]);
bool winCol(char grid[]);
void possWin(char player);
bool boardReset(char grid[]);
char grid[SIZE];

int main()
{
	do{

		int turn = 0;

		cout << " TIC-TAC-TOE \n\n";
		cout << "PLAYER 1 IS 'x'  PLAYER 2 IS 'o'\n";

		initializeGrid(grid);
		displayGrid(grid);
		cout << endl;

		while (!isFull(grid))
		{
			int choice;
			turn += 1;
			bool pTurn(turn % 2 == 0);

			choice = switchGetTurn(grid, pTurn);
			Go(grid, pTurn, choice);
			displayGrid(grid);
			cout << endl;

			if (isWinner(grid))
			{
				if (pTurn)
					cout << "PLAYER 2 WINS!!" << endl;
				else
					cout << "PLAYER 1 WINS!!" << endl;
				break;
			}
		}
		if (!isWinner(grid))
			cout << "It's a draw" << endl;

	} while (boardReset(grid) != false);
}


void initializeGrid(char grid[])
{
	for (int i = 0; i < SIZE; i++)
		grid[i] = ' ';
}

void displayGrid(char grid[])
{
	cout << "+---+---+---+\n";
	for (int i = 0; i < SIZE; ++i)
	{
		cout << "| " << grid[i] << " ";
		if ((i + 1) % 3 == 0 && i != 0)
		{
			cout << "|" << endl;
			cout << "+---+---+---+" << endl;
		}
	}
}
int switchGetTurn(char grid[], bool pTurn)
{
	int choice;
	char player1 = 'x';
	char player2 = 'o';

	if (pTurn){
		possWin(player1);
		cout << "Player 2 Move 'o'\nchoose slot (#0-8): ";
	}
	else{
		possWin(player2);
		cout << "Player 1 Move 'x'\nchoose slot (#0-8): ";
	}
	cin >> choice;

	while (!isFree(grid[choice]))
	{
		cout << "Slot taken. Select another: ";
		cin >> choice;
	}
	return choice;
}

//FUNCTIONS SPECIFICATIONS

void Go(char grid[], bool pTurn, int choice){

	if (pTurn) // PLAYER 2
		grid[choice] = 'o';
	else // PLAYER 1
		grid[choice] = 'x';
}

bool isFree(char input)
{
	if (input == ' ')
		return true;
	else
		return false;
}

bool isFull(char grid[]){

	for (int i = 0; i < SIZE; i++)
	{
		if (grid[i] == ' ')
			return false;
	}

	return true;
}

bool winRow(char grid[])
{

	for (int i = 0; i < SIZE; i++)
	{
		char first = grid[i];
		char second = grid[i + 1];
		char third = grid[i + 2];

		if (!isFree(first) && !isFree(second) && !isFree(third))
		{
			if (first == second && first == third)
				return true;
		}
	}
	return false;
}

bool winCol(char grid[])
{

	for (int i = 0; i<3; ++i)
	{
		char first = grid[i];
		char second = grid[i + 3];
		char third = grid[i + 6];

		if (!isFree(first) && !isFree(second) && !isFree(third))
		{
			if (first == second && first == third)
				return true;
		}
	}
	return false;
}

bool winDiag(char grid[])
{
	char center = grid[4];
	if (!isFree(center) && !isFree(grid[0]) && !isFree(grid[8]))
	{
		if (center == grid[0] && center == grid[8])
			return true;
	}
	else if (!isFree(center) && !isFree(grid[2]) && !isFree(grid[6]))
	{
		if (center == grid[2] && center == grid[6])
			return true;
	}

	return false;
}


bool isWinner(char grid[]){

	if (winRow(grid))
		return true;
	else if (winCol(grid))
		return true;
	else if (winDiag(grid))
		return true;

	return false;
}


bool boardReset(char grid[]){// resets the game.

	char answer;

	cout << "would you like to play again?  Y/N" << endl;
	cin >> answer;

	if (tolower(answer) == 'y'){
		for (int i = 0; i < SIZE; i++)
			grid[i] = ' ';
      return true;
   }
	else return false;
}


void possWin(char player){// checks when a player is about to win and lets opponent know.


	int player_c;

	/////////////////////////////////////////
	//////////horizontal check///////////////
	/////////////////////////////////////////


	if (grid[0] == player && grid[0] == grid[1] && grid[2] == ' '){
		if (grid[0] == 'x'){
			player_c = 1;
		}
		if (grid[0] == 'o'){
			player_c = 2;
		}
		cout << "Player " << player_c << " is one move from winning." << endl;
	}
	else if (grid[0] == player && grid[0] == grid[2] && grid[1] == ' '){
		if (grid[0] == 'x'){
			player_c = 1;
		}
		if (grid[0] == 'o'){
			player_c = 2;
		}
		cout << "Player " << player_c << " is one move from winning." << endl;
	}
	else if (grid[2] == player && grid[2] == grid[1] && grid[0] == ' '){
		if (grid[2] == 'x'){
			player_c = 1;
		}
		if (grid[2] == 'o'){
			player_c = 2;
		}
		cout << "Player " << player_c << " is one move from winning." << endl;
	}
	else if (grid[3] == player && grid[3] == grid[4] && grid[5] == ' '){
		if (grid[3] == 'x'){
			player_c = 1;
		}
		if (grid[3] == 'o'){
			player_c = 2;
		}
		cout << "Player " << player_c << " is one move from winning." << endl;
	}
	else if (grid[3] == player && grid[3] == grid[5] && grid[4] == ' '){
		if (grid[3] == 'x'){
			player_c = 1;
		}
		if (grid[3] == 'o'){
			player_c = 2;
		}
		cout << "Player " << player_c << " is one move from winning." << endl;
	}
	else if (grid[5] == player && grid[5] == grid[4] && grid[3] == ' '){
		if (grid[5] == 'x'){
			player_c = 1;
		}
		if (grid[5] == 'o'){
			player_c = 2;
		}
		cout << "Player " << player_c << " is one move from winning." << endl;
	}
	else if (grid[6] == player && grid[6] == grid[7] && grid[8] == ' '){
		if (grid[6] == 'x'){
			player_c = 1;
		}
		if (grid[6] == 'o'){
			player_c = 2;
		}
		cout << "Player " << player_c << " is one move from winning." << endl;
	}
	else if (grid[6] == player && grid[6] == grid[8] && grid[7] == ' '){
		if (grid[6] == 'x'){
			player_c = 1;
		}
		if (grid[6] == 'o'){
			player_c = 2;
		}
		cout << "Player " << player_c << " is one move from winning." << endl;
	}
	else if (grid[8] == player && grid[8] == grid[7] && grid[6] == ' '){
		if (grid[8] == 'x'){
			player_c = 1;
		}
		if (grid[8] == 'o'){
			player_c = 2;
		}
		cout << "Player " << player_c << " is one move from winning." << endl;
	}
	/////////////////////////////////////////
	///////////vertical check////////////////
	/////////////////////////////////////////
	else if (grid[0] == player && grid[0] == grid[3] && grid[6] == ' '){
		if (grid[0] == 'x'){
			player_c = 1;
		}
		if (grid[0] == 'o'){
			player_c = 2;
		}
		cout << "Player " << player_c << " is one move from winning." << endl;
	}
	else if (grid[0] == player && grid[0] == grid[6] && grid[3] == ' '){
		if (grid[0] == 'x'){
			player_c = 1;
		}
		if (grid[0] == 'o'){
			player_c = 2;
		}
		cout << "Player " << player_c << " is one move from winning." << endl;
	}
	else if (grid[6] == player && grid[6] == grid[3] && grid[0] == ' '){
		if (grid[6] == 'x'){
			player_c = 1;
		}
		if (grid[6] == 'o'){
			player_c = 2;
		}
		cout << "Player " << player_c << " is one move from winning." << endl;
	}
	else if (grid[1] == player && grid[1] == grid[4] && grid[7] == ' '){
		if (grid[1] == 'x'){
			player_c = 1;
		}
		if (grid[1] == 'o'){
			player_c = 2;
		}
		cout << "Player " << player_c << " is one move from winning." << endl;
	}
	else if (grid[1] == player && grid[1] == grid[7] && grid[4] == ' '){
		if (grid[1] == 'x'){
			player_c = 1;
		}
		if (grid[1] == 'o'){
			player_c = 2;
		}
		cout << "Player " << player_c << " is one move from winning." << endl;
	}
	else if (grid[7] == player && grid[7] == grid[4] && grid[1] == ' '){
		if (grid[7] == 'x'){
			player_c = 1;
		}
		if (grid[7] == 'o'){
			player_c = 2;
		}
		cout << "Player " << player_c << " is one move from winning." << endl;
	}
	else if (grid[2] == player && grid[2] == grid[5] && grid[8] == ' '){
		if (grid[2] == 'x'){
			player_c = 1;
		}
		if (grid[2] == 'o'){
			player_c = 2;
		}
		cout << "Player " << player_c << " is one move from winning." << endl;
	}
	else if (grid[2] == player && grid[2] == grid[8] && grid[5] == ' '){
		if (grid[2] == 'x'){
			player_c = 1;
		}
		if (grid[2] == 'o'){
			player_c = 2;
		}
		cout << "Player " << player_c << " is one move from winning." << endl;
	}
	else if (grid[8] == player && grid[8] == grid[5] && grid[2] == ' '){
		if (grid[8] == 'x'){
			player_c = 1;
		}
		if (grid[8] == 'o'){
			player_c = 2;
		}
		cout << "Player " << player_c << " is one move from winning." << endl;
	}


	/////////////////////////////////////////
	///////////diagonal check////////////////
	/////////////////////////////////////////


	else if (grid[0] == player && grid[0] == grid[4] && grid[8] == ' '){
		if (grid[0] == 'x'){
			player_c = 1;
		}
		if (grid[0] == 'o'){
			player_c = 2;
		}
		cout << "Player " << player_c << " is one move from winning." << endl;
	}
	else if (grid[0] == player && grid[0] == grid[8] && grid[4] == ' '){
		if (grid[0] == 'x'){
			player_c = 1;
		}
		if (grid[0] == 'o'){
			player_c = 2;
		}
		cout << "Player " << player_c << " is one move from winning." << endl;
	}
	else if (grid[8] == player && grid[8] == grid[4] && grid[0] == ' '){
		if (grid[8] == 'x'){
			player_c = 1;
		}
		if (grid[8] == 'o'){
			player_c = 2;
		}
		cout << "Player " << player_c << " is one move from winning." << endl;
	}
	else if (grid[2] == player && grid[2] == grid[4] && grid[6] == ' '){
		if (grid[2] == 'x'){
			player_c = 1;
		}
		if (grid[2] == 'o'){
			player_c = 2;
		}
		cout << "Player " << player_c << " is one move from winning." << endl;
	}
	else if (grid[2] == player && grid[2] == grid[6] && grid[4] == ' '){
		if (grid[2] == 'x'){
			player_c = 1;
		}
		if (grid[2] == 'o'){
			player_c = 2;
		}
		cout << "Player " << player_c << " is one move from winning." << endl;
	}
	else if (grid[6] == player && grid[6] == grid[4] && grid[2] == ' '){
		if (grid[6] == 'x'){
			player_c = 1;
		}
		if (grid[6] == 'o'){
			player_c = 2;
		}
		cout << "Player " << player_c << " is one move from winning." << endl;
	}


}//end of function
