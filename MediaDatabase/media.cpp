/*
 * Media implementation
 *
 * Colby Waters
 * 12/3/2022
 */
#include <iostream>
#include <cstring>

#include "media.h"

/*
* Destructor - Base class destructor
*/
Media::~Media()
{
    cout << "Destroying Media record..." << endl;
}

/*
* Print - Base class print method. Child classes should call this.
*/
void Media::Print()
{
    cout << "----------------------------" << endl;
    cout << "Title: " << title << endl;
    cout << "Year: " << year << endl;
}

/*
* SetTitle - Set title from user input
*/
void Media::SetTitle()
{
    cout << "Enter title: ";
    cin.getline(title,sizeof(title));
}

/*
* SetYear - Set year from user input
*/
void Media::SetYear()
{
    cout << "Enter year: ";
    cin >> year;
}
