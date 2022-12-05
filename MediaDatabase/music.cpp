/*
 * Music implementation
 *
 * Colby Waters
 * 12/3/2022
 */
#include <iostream>
#include <cstring>

#include "media.h"
#include "music.h"

using namespace std;

/*
* Destructor - Music class destructor
*/
Music::~Music()
{
    cout << "Destroying Music" << endl;
}

/*
* SetPublisher - Set publisher from user input
*/
void Music::SetPublisher()
{
    cout << "Enter publisher: ";
    cin.getline(publisher,sizeof(publisher));
}

/*
* SetArtist - Set artist from user input
*/
void Music::SetArtist()
{
    cout << "Enter artist: ";
    cin.getline(artist,sizeof(artist));
}

/*
* SetDuration - Set duration from user input
*/
void Music::SetDuration()
{
    cout << "Enter duration: ";
    cin >> duration;
    cin.ignore(256, '\n');  // Eat the newline that comes after the integer
}

/*
* Print - Overrides parent implementation for print.
*/
void Music::Print()
{
    Media::Print();
    cout << "Publisher: " << publisher << endl;
    cout << "Artist: " << artist << endl;
    cout << "Duration: " << duration << endl;
}

