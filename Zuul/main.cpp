/*
 * Zuul Birthday Party implementation
 *
 * Colby Waters
 * 12/18/2022
 */
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

/**
 * This is the main class for the game "Zuul Birthday" game.
 * 
 * The objective of the game is to find the birthday party but don't
 * forget to bring the cake and a present. You have to find the
 * rooms with the present and cake and add those to your inventory
 * and then bring these to the birthday party. You will not be allowed
 * to enter birthday party without these. If you have them then
 * you win!
 * 
 *  To play this game, create an instance of this class and call the "play"
 *  method.
 * 
 *  This main class creates and initializes all the others: it creates all
 *  rooms, creates the parser and starts the game.  It also evaluates and
 *  executes the commands that the parser returns.
 */
class Game 
{
public:
    /**
     *  Game constructor
     */
    Game() {}

    /**
     *  Game destructor
     */
    ~Game() {}

    /**
     *  Main play routine.  Loops until end of play.
     */
    void play()
    {
        printWelcome();

        bool finished = false;
        while (! finished) {
            finished = true;
        }
        cout << "Thank you for playing.  Good bye." << endl;
    }

    /**
     * Print out some helpful information.
     */
    void printHelp() 
    {
        cout << "You are lost. You are alone. You wander" << endl;
        cout << "around at Sunset Highschool." << endl;
        cout << endl;
        cout << "Your command words are:" << endl;
        // @todo Show commands here!
    }

    /**
     * Print out welcome information.
     */
    void printWelcome()
    {
        cout << endl;
        cout << "Welcome to Sunset Highschool!" << endl;
        cout << "There is a party here and you have to find it!" << endl;
        cout << "Before you can enter the party room you'll need" << endl;
        cout << "to find the cake and present in the other rooms" << endl;
        cout << "to bring to the party. Here is a ticket and be sure" << endl;
        cout << "not to lose your ticket! Have fun!" << endl;
        cout << "" << endl;
        cout << "Type 'help' if you need help." << endl;
        cout << endl;
    }
};

/*
 * main - This is main function for Zuul game.
 */
int main()
{
    cout << "------------------------------------------------" << endl;
    cout << " Zuul Birthday Party - Colby Waters - Dec 2022"   << endl;
    cout << "------------------------------------------------" << endl << endl;

    Game* game = new Game();

    game->play();

    return 0;
}