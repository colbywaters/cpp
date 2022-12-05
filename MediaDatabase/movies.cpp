/*
 * Media definition
 *
 * Colby Waters
 * 12/3/2022
 */
#include <iostream>
#include <cstring>

#include "media.h"
#include "movies.h"

/*
* Destructor - Movie class destructor
*/
Movie::~Movie()
{
    cout << "Destroying Movie" << endl;
}

/*
 * SetDirector - Set director from user input
 */
void Movie::SetDirector()
{
    cout << "Enter director: ";
    cin.getline(director,sizeof(director));
}

/*
 * SetRating - Set rating from user input
 */
void Movie::SetRating()
{
    cout << "Enter rating: ";
    cin >> rating;
    cin.ignore(256, '\n');  // Eat the newline that comes after the integer
}

/*
 * SetDuration - Set duration from user input
 */
void Movie::SetDuration()
{
    cout << "Enter duration: ";
    cin >> duration;
    cin.ignore(256, '\n');  // Eat the newline that comes after the integer
}

/*
 * Print - Overrides parent implementation for print.
 */
void Movie::Print()
{
    Media::Print();
    cout << "Director: " << director << endl;
    cout << "Duration: " << duration << endl;
    cout << "Rating: " << rating << endl;
}
