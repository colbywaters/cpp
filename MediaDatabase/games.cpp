/*
 * Game implementation
 *
 * Colby Waters
 * 12/3/2022
 */
#include <iostream>
#include <cstring>

#include "media.h"
#include "games.h"

/*
* Destructor - Game class destructor
*/
Game::~Game()
{
    cout << "Destroying Game" << endl;
}


/*
 * SetPublisher - Set publisher from user input
 */
void Game::SetPublisher()
{
    cout << "Enter publisher: ";
    cin.getline(publisher,sizeof(publisher));
}

/*
 * SetRating - Set rating from user input
 */
void Game::SetRating()
{
    cout << "Enter rating: ";
    cin >> rating;
    cin.ignore(256, '\n');  // Eat the newline that comes after the integer
}

/*
 * Print - Overrides parent implementation for print.
 */
void Game::Print()
{
    Media::Print(); // Call base class to print base class implementation.

    cout << "Publisher: " << publisher << endl;
    cout << "Rating: " << rating << endl;
}
