/*
 * Palindrome implementation that takes a string as input and determines.
 * if the string is a palindrome or not. Whitespace and capitalization
 * is ignored.
 *
 * Colby Waters
 * 9/30/2022
 */
#include <iostream>
#include <string.h>

using namespace std;

/*
 * @brief return true if character is a uppercase letter.
 */
bool isupper(char c)
{
  if (c >= 'A' && c <= 'Z') {
    return true;
  }
  return false;
}

/*
 * @brief return true if character is a letter.
 */
bool isalpha(char c)
{
  if ((c >= 'a' && c <= 'z') ||
      (c >= 'A' && c <= 'Z')) {
        return true;
      }
      return false;
}

/*
 * @brief Returns lowercase letter for input character when
 *        it's an upper case letter. Otherwise, it returns
 *        the original character back.
 */
char lower(char c)
{
    if (isupper(c)) {
        char tmp = c - 'A';
        return 'a' + tmp;
    }
    return c;
}

/*
 * @brief changes characters in string to lower-case
*         only for characters that are letters.
 */
void tolower(char* str, int len)
{
  for(int i = 0; i < len; i++) {
    str[i] = lower(str[i]);
  }
}

/*
 * @brief removes whitespace from str.
 */
int removewhitespace(char* str, int len)
{
  // Track position that we're moving characters into in the string.
  // Typically, the position and i will match until there is a non
  // alpha character found.
  int pos = 0;
  for(int i = 0; i < len; i++)
  {
    if (isalpha(str[i]))
    {
        str[pos] = str[i];
        pos++;
    }
  }

  // Need to null-terminate our string.
  str[pos] = '\0';

  return pos;
}

/*
 * @brief Implements the main function to request input string from user
 *        and then test whether it's a palindrome or not.
 */
int main()
{
    // Ask for input from user
    char str[81];
    cout << "Enter string: ";
    cin.get(str, 81);
    int len = strlen(str);

    // Modify string to lower case all letters.
    tolower(str, len);

    // Modify string to remove all whitespace.
    len = removewhitespace(str, len);

    // Assume all input is a palindrome until proven otherwise.
    bool palindrome = true;
  
    // Loop through string characters starting from the end.
    for (int i = len -1; i > 0; i--)
    {
        // Read characters from both start and end and compare.
        char a = str[len - 1 - i];
        char b = str[i];

        // If character is not the same then it's not a palindrome.
        if (a != b) {
            palindrome = false;
        }
    }

    if (palindrome == true) {
        cout << "Your input was a palindrome";
    }
    else {
        cout << "Your input was NOT a palindrome";
    }
}
