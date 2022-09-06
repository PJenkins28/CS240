 

//Tic-Tac-Toe Implementation file

#include <iostream>
#include <iomanip> 
#include <random>
#include "ticTacToe.h"

using namespace std;

void ticTacToe::play()
{
	bool done = false;
    char player = 'X';
       
    displayBoard();
       
    while(!done) {
       	done = getXOMove(player);
       	if (player == 'X')
       		player = 'O';
       	else
       		player = 'X';
}
}
void ticTacToe::displayBoard() const
{
	cout << "   0      1     2 " << endl;
	cout << "       |     |     " << endl;
	cout << "0    " << board[0][0] << " |" <<  "  " << board[0][1] << "  |" <<  "  " << board[0][2] << endl;
	cout << "--------------------" <<endl;
	cout << "       |     |      " << endl;
	cout << "1 " << board[1][0] << "    |" <<  "   " << board[1][1] << " |" <<  "  " << board[1][2] << endl;
	cout << "--------------------" <<endl;
	cout << "       |     |      " << endl;
	cout << "2 " << board[2][0] << "    |" <<  "   " << board[2][1] << " |" <<  "  " << board[2][2] << endl;
}

bool ticTacToe::isValidMove(int row, int col) const
{
  if((row >= 0 && row <= 2)&&(col >= 0 && col <= 2)) {
	  if(board[row][col] == ' ')
		  return true;
  }
  else
	  cout << "Invalid move" << endl;
	  return false;
}

bool ticTacToe::getXOMove(char playerSymbol)
{
    int x, o;
    while(true) {
    	cout << "\nPlayer " << playerSymbol <<  " enter move: " << endl;
    	cin >> x >> o;

    	if(isValidMove(x,o)) {
    		noOfMoves++;
    		break;
    	}
    	else;
    	cout << "Invalid move\n" << endl;
    }
    board[x][o] = playerSymbol;

    displayBoard();

    if(gameStatus() == WIN) {
    	cout << playerSymbol << " wins!";
    	return true;
    }
    else if(gameStatus() == DRAW) {
    	cout << "Tie!";
    	return true;
    }
    return false;
}

status ticTacToe::gameStatus()
{
	for(int i=0;i<3;i++) {
		if(board[i][0]==board[i][1] && board[i][1]==board[i][2]&& board[i][0]!=' '&& board[i][1]!=' ' && board[i][1])
			return WIN;
		}
		for(int i=0;i<3;i++) {
			if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]!=' '&& board[1][i]!=' ' && board[1][i])
				return WIN;
		}
		if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!=' '&& board[2][2]!=' ' && board[1][1]!=' ')
			return WIN;

		if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[0][2]!=' '&& board[1][1]!=' ' && board[2][0])
			return WIN;

		if(noOfMoves==9)
			return DRAW;

		return CONTINUE;

}

void ticTacToe::reStart()
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            board[row][col] = ' ';

    noOfMoves = 0;
}

ticTacToe::ticTacToe()
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            board[row][col] = ' ';

    noOfMoves = 0;
}
