/*
 * Tic-tac-toe implementation for a text-based tic-tac-toe game.
 *
 * Colby Waters
 * 11/16/2022
 */
#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>

using namespace std;

void displayBoard();

// Constants for tic-tac-toe board dimensions
static const int ROW = 3;
static const int COL = 3;

/*
 * displayBoard - Displays the game board to the screen.
 */
void displayBoard(char Aboard[ROW][COL])
{
    cout << "     0   1   2";
    cout << endl << endl;
    cout << " 0  " << Aboard[0][0] << " | " << Aboard[0][1] << " | " << Aboard[0][2] << endl;
    cout << "   ___|___|___\n";
    cout << " 1  " << Aboard[1][0] << " | " << Aboard[1][1] << " | " << Aboard[1][2] << endl;
    cout << "   ___|___|___\n";
    cout << " 2  " << Aboard[2][0] << " | " << Aboard[2][1] << " | " << Aboard[2][2] << endl;
    cout << "      |" << "   |" << endl;
}

/*
 * isBlank - This function checks whether a character is not X or O.
 */
bool isBlank(char c)
{
    if (c == 'x' || c == 'X') {
      return false;
    }

    if (c == 'o' || c == 'O') {
      return false;
    }

    return true;
}

/*
 * continuePlaying - Ask the user if they want to continue playing.
 */
bool continuePlaying()
{
    bool result = true;

    char answer[255];
    cout << "Would you like to play again (y/n):" << endl;
    cin >> answer;

    if (strcmp(answer, "y") != 0) {
      result = false;
    }  
  return result;
}

/*
 * main - This is main function for tic-tac-toe game!
 */
int main()
{
    cout << "----------------------------------------------------------" << endl;
    cout << "           Tic-Tac-Toe" << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "Play tic-tac-toe! For each player, you'll be prompted" << endl;
    cout << "to make a move. You'll enter the coordinates for the move." << endl;
    cout << "Player 1 is always \'X\' and Player 2 is always \'O\'" << endl;
    cout << "----------------------------------------------------------" << endl << endl;

    // Do we continue playing? User will be asked this question. For right now we do!
    bool doContinue = true;

    while(doContinue) {

        char Aboard[ROW][COL] = {{'*','*','*'}, {'*','*','*'},{'*','*','*'}};
        string Player1;
        string Player2;
        int row = 3;
        int col = 3;

        bool win = false;
        char PMove = 'X';

        displayBoard(Aboard);

        while (win == false) {
            // Display question to player.
            if (PMove == 'X') {
              cout << "Player 1 - Make your move (row column):" << endl;
            } else {
              cout << "Player 2 - Make your move (row column):" << endl;
            }
          
            // Read players coordinates
            cin >> row >> col;

            // Check if position is already taken on the board.
            if (Aboard[row][col] == '*') {
                Aboard[row][col] = PMove;

                cout << endl;
                displayBoard(Aboard);

                // Check for 3 in row across
                for (int i = 0; i < 3; i++) {
                    // Check if first position in column is blank. If it is then
                    // it can't be 3 in a row.
                    if (isBlank(Aboard[i][0]) == false) {
                        if (Aboard[i][0] == Aboard[i][1] && Aboard[i][1] == Aboard[i][2]){
                            win = true;
                            if (PMove == 'X') {
                                cout << "\'X\' wins with three in a row across!" << endl;
                            } else {
                                cout << "\'O\' wins with three in a row across!" << endl;
                            }
                        }
                    }
                }

                // Checks for 3 in a row vertically
                for (int i = 0; i < 3; i++) {
                    if (isBlank(Aboard[0][i]) == false) {
                        if (Aboard[0][i] == Aboard[1][i] && Aboard[1][i] == Aboard[2][i]){
                            win = true;
                            if (PMove == 'X') {
                                cout << "\'X\' wins with three in a row vertically!" << endl;
                            } else {
                                cout << "\'O\' wins with three in a row vertically!" << endl;
                            }
                        }
                    }
                }

                // Check for 3 in a row across the diagonals
                if (isBlank(Aboard[1][1]) == false) {
                    if ((Aboard[0][0] == Aboard[1][1] && Aboard[1][1] == Aboard[2][2]) ||
                        (Aboard[0][2] == Aboard[1][1] && Aboard[1][1] == Aboard[2][0])) {
                        win = true;
                        if (PMove == 'X') {
                            cout << "\'X\' wins with three in a row diagonally!" << endl;
                        } else {
                            cout << "\'O\' wins with three in a row diagonally!" << endl;
                        }
                    }
                }

              // Switch player turn.
              if (PMove == 'X') {
                  PMove = 'O';
              } else {
                  PMove = 'X';
              }      
            } else {
                cout << "Invalid move! Position already taken. Enter another." << endl;
            }
        }

        // Ask player if they want to continue playing.
        doContinue = continuePlaying();
    }

    cout << "Thank you for playing!" << endl;
}

