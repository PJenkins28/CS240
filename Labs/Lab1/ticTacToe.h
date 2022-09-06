//Paige Jenkins
//Fall 2022
//9/5/22
//This is the header file for the ticTacToe game
#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <string>

using namespace std;
 
enum status {WIN, DRAW, CONTINUE};

class ticTacToe
{
public:
	void play();
       //Function to start the play.

    void displayBoard() const;
       
    bool isValidMove(int x, int y) const;
       //Function to determine if a move is valid.

	bool getXOMove(char moveSymbol);
       //Function to get a move for a player

    status gameStatus();
       //Function to determine the current status of the game.

    void reStart();
       //Function to restart the game.

    ticTacToe();


private:
   char board[3][3];
    int noOfMoves; 
};

#endif
