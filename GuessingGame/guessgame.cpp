/**
 * Guessing Game
 *
 * @author Colby Waters
 *
 * @date 9/16/2022
 *
 * @brief
 *   The computer will pick a random number
 *   between 0 and 100, inclusive. The user
 *   will guess a number, and the computer
 *   will tell you if it is too high, too
 *   low, or correct. If it is correct, it
 *   will display how many guesses it took
 *   you, and ask if you want to play again.
 */
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;


int main() {

   /* Assignment Rules
    *  1. No global variables
    *  2. No strings
    *  3. Include <iostream> not <stdio.h>
    */

    /* variable for checking whether player
    is going to continue playing or not */
    bool play_game = true;

    while (play_game == true) {

        /* Variable being used for the user's guess */
        int input = 0;

        /* Seed random number generator */
        srand(time(NULL));

        int random = 1 + (rand() % 100);

        /* Variable used to store the number or
           guesses the player takes */
        int num_g = 0;

        /* If your input does not match the random num
           then you will be given another guess until you
           guess right */
        while (input != random) {

            cout << "Guess a number between 1 and 100: ";
            cin >> input;

            /* Check if input is less or greater than
               random and provide user hint.*/
            if (input < random) {
                cout << "Your guess was too low." << endl;
            }
            else if (input > random) {
                cout << "Your guess was too high." << endl;
            }
            num_g++;
        }
        cout << "You guessed the right number!" << endl;
        cout << "Your number of guesses was: " << num_g << endl;
        cout << "Do you want to continue playing? y to continue and n to quit: ";
        
        char c;
        cin >> c;
        if (c != 'y') {
            play_game = false;
        }
    }
    cout << "Thank you for playing!" << endl;
}
