#include <IOstream>
#include <string.h>

using namespace std;

int main()
{
  char str[81];
  cin.get(str, 81);
  int len = strlen(str);
  bool palindrome = true;
  
  for (int i = len -1; i > 0; i--)
    {
      char a = str[len - 1 - i];
      char b = str[i];

      if (a != b) {
	palindrome = false;
	  }
    }
  if (palindrome == true) {
    cout << "Your input was a palindrome";
  }
  else {
    cout << "Your input was not a palindrome";
  }
}
