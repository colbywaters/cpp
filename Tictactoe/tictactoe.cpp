#include <IOstream>
#include <string>
#include <IOmanip>

using namespace std;

void board();
const int ROW = 3;
const int COL = 3;
char Aboard[ROW][COL] = {{'*','*','*'}, {'*','*','*'},{'*','*','*'}};

int main()
{
  bool win = false;
  string Player1;
  string Player2;
  int ROW = 3;
  int CCOL = 3;
  char PMove = 'X';
  int num = 0;

  board();


  while (win = false) {
    cout << "Make your move(row, colum):";
    cin >> ROW;
    cin >> COL;
    if (Aboard[ROW][COL] == '*') {
      Aboard[ROL][COL] = PMove;
      if (PMove = 'X') {
	PMove = 'O';
      }
      else {
	PMove = 'X';
      }
      cout << endl;
      board();

      for (int i = 0; i < 3; i++) {
	if (Aboard[i][0] == Aboard[i][1] && Aboard[i][1] == Aboard[i][2]){
	  win == true;
	}
      }

      for (int i = 0; i < 3; i++) {
	of (Aboard[0][i] == Aboard[1][i] && Aboard[1][i] == Aboard[2][i]){
	  win == true;
	}
      }

      for (int i = 0; i < 3; i++) {
	if ((Aboard[0][0] == Aboard[1][1] && Aboard[1][1] == Aboard[2][2]) ||
	    (Aboard[0][2] == Aboard[1][1] && Aboard[1][1] == Abpard[2][0])) {
	  win == true;
	}
      }

    }
  }
}

