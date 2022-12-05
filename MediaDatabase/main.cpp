/*
 * Media database implementation
 *
 * Colby Waters
 * 12/3/2022
 */
#include <iostream>
#include <cstring>
#include <vector>

#include "media.h"
#include "music.h"
#include "games.h"
#include "movies.h"

using namespace std;

/*
 * MediaDatabase - Implements media database that can contain records for games, music, and movies.
 */
class MediaDatabase
{
public:
    /*
     * Constructor - Nothing to do
     */
    MediaDatabase() {}

    /*
     * Destructor - Deletes each record and clears vector
     */
    ~MediaDatabase()
    {
        for(uint32_t i = 0; i < m_records.size(); i++)
        {
            delete m_records[i];
        }
        m_records.clear();
    }

    /*
    * GetMediaTypeFromUser - Retrieves media type from user input
    */
    uint32_t GetMediaTypeFromUser()
    {
        // The user should be able to add each kind of media, including the information in each field.
        uint32_t mediaType = 0;

        // Prompt user for type of media they want to add.
        cout << "What is media type?" << endl;
        cout << "   1. Game" << endl;
        cout << "   2. Music" << endl;
        cout << "   3. Movie" << endl;
        cout << "Choose number: ";
        cin >> mediaType;
        cin.ignore(256, '\n');  // Eat the newline that comes after the integer

        return mediaType;        
    }

    /*
     * Add - Allows user to specify media type and then add media record for that type.
     */
    void Add()
    {
        // The user should be able to add each kind of media, including the information in each field.
        uint32_t mediaType = GetMediaTypeFromUser();

        switch(mediaType)
        {
        case 1:
            AddGame();
            break;
        case 2:
            AddMusic();
            break;
        case 3:
            AddMovie();
            break;
        default:
            cout << "Invalid media type!" << endl;
            break;
        };  
    }

    /*
    * GetSearchTypeFromUser - Retrieves search type from user input
    */
    uint32_t GetSearchTypeFromUser()
    {
        uint32_t searchType = 0;

        cout << "What do you want to search media by?" << endl;
        cout << "   1. Title" << endl;
        cout << "   2. Year" << endl;
        cout << "Choose number: ";
        cin >> searchType;
        cin.ignore(256, '\n');  // Eat the newline that comes after the integer

        return searchType;
    }

    /*
    * Search - The user should be able to search for and print objects currently in the media database
    *          by searching for the title or the year.  If multiple objects match, list them all. (20 points)
    */
    void Search()
    {
        if (m_records.size() == 0)
        {
            cout << "There are no media records to search!" << endl;
            return;
        }

        uint32_t searchType = GetSearchTypeFromUser();

        if (searchType == 1)
        {
            // Search by Title
            char title[256];

            cout << "Enter title: ";
            cin.getline(title,sizeof(title));

            for(uint32_t i = 0; i < m_records.size(); i++ )
            {
                Media* media = m_records[i];

                if (strcmp(media->GetTitle(), title) == 0)
                {
                    media->Print();
                }
            }
        }
        else if (searchType == 2)
        {
            // Search by Year
            uint32_t year = 0;

            cout << "Enter year: ";
            cin >> year;
            cin.ignore(256, '\n');  // Eat the newline that comes after the integer

            for(uint32_t i = 0; i < m_records.size(); i++ )
            {
                Media* media = m_records[i];

                if (media->GetYear() == year)
                {
                    media->Print();
                }
            }
        }
    }

    /*
    * Delete - The user should be able to delete an item. Use the same functionality
    *          as the search method, then have the user confirm whether they want to
    *          delete those objects. USE A DESTRUCTOR. (10 points)
    */
    void Delete()
    {
        if (m_records.size() == 0)
        {
            cout << "There are no media records to delete!" << endl;
            return;
        }

        uint32_t searchType = GetSearchTypeFromUser();

        if (searchType == 1)
        {
            // Search by Title
            char title[256];

            cout << "Enter title: ";
            cin.getline(title,sizeof(title));

            for(uint32_t i = 0; i < m_records.size(); i++ )
            {
                Media* media = m_records[i];

                if (strcmp(media->GetTitle(), title) == 0)
                {
                    char answer[256];
                    cout << "Found media match to delete... " << endl;
                    media->Print();
                    cout << endl;
                    cout << "Do you want to delete it? [y/n]:";
                    cin.getline(answer,sizeof(answer));
                    if (strcmp(answer, "y") == 0)
                    {
                        cout << "Deleting media..." << endl;
                        m_records.erase(m_records.begin()+i);
                        if (i > 0) i--;
                        delete media;
                    }
                }
            }
        }
        else if (searchType == 2)
        {
            // Search by Year
            uint32_t year = 0;

            cout << "Enter year: ";
            cin >> year;
            cin.ignore(256, '\n');  // Eat the newline that comes after the integer

            for(uint32_t i = 0; i < m_records.size(); i++ )
            {
                Media* media = m_records[i];

                if (media->GetYear() == year)
                {
                    char answer[256];
                    cout << "Found media match to delete... " << endl;
                    media->Print();
                    cout << "Do you want to delete it? [y/n]:";
                    cin.getline(answer,sizeof(answer));
                    if (strcmp(answer, "y") == 0)
                    {
                        cout << "Deleting media..." << endl;
                        m_records.erase(m_records.begin()+i);
                        if (i > 0) i--;
                        delete media;
                    }
                }
            }
        }        
    }

private:
    /*
     * AddGame - Allows user to add media record for a Game.
     */
    void AddGame()
    {
        // Video games must have the fields: title, year, publisher, rating.
        Game* game = new Game();
        game->SetTitle();
        game->SetPublisher();
        game->SetYear();
        game->SetRating();

        m_records.push_back(game);
    }

    /*
     * AddMusic - Allows user to add media record for a Music song.
     */
    void AddMusic()
    {
        // Music must have the fields: title, artist, year, duration, publisher.
        Music* music = new Music();
        music->SetTitle();
        music->SetArtist();
        music->SetYear();
        music->SetDuration();
        music->SetPublisher();

        m_records.push_back(music);
    }

    /*
     * AddMovie - Allows user to add media record for a Movie song.
     */
    void AddMovie()
    {
        // Movies must have the fields: title, director, year, duration, rating.
        Movie* movie = new Movie();
        movie->SetTitle();
        movie->SetDirector();
        movie->SetYear();
        movie->SetDuration();
        movie->SetRating();

        m_records.push_back(movie);
    }

private:
    std::vector<Media*> m_records;
};

/*
 * main - This is main function for media database. Implements main parser.
 */
int main()
{
    bool hasQuit = false;

    cout << "------------------------------------------------" << endl;
    cout << " Media Database - Colby Waters" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Enter commands to manage media database." << endl;
    cout << "   ADD - Creates new media database entry." << endl;
    cout << "   SEARCH - Prints all entries in media database that match title or year." << endl;
    cout << "   DELETE - Deletes entries that match title or year." << endl;
    cout << "   QUIT - Exits media database program." << endl;
    cout << "------------------------------------------------" << endl;
    
    MediaDatabase db;

    // Main command parser loop
    while(hasQuit == false)
    {
        char command[256];
        cout << "cmd>: ";
        cin.getline(command,sizeof(command));

        if (strcmp(command, "ADD") == 0)
        {
            // Add media entry
            db.Add();
        }
        else if (strcmp(command, "SEARCH") == 0)
        {
            // Search for media entry
            db.Search();
        }
        else if (strcmp(command, "DELETE") == 0)
        {
            // Delete media entry
            db.Delete();
        }
        else if (strcmp(command, "QUIT") == 0)
        {
          cout << "QUIT command received" << endl;
          hasQuit = true;
          cout << "Thank you! Exiting Media Database." << endl;
        }
        else
        {
            cout << "Unknown command received." << endl;

            cout << "Enter commands to manage media database." << endl;
            cout << "   ADD - Creates new media database entry." << endl;
            cout << "   SEARCH - Prints all entries in media database that match title or year." << endl;
            cout << "   DELETE - Deletes entries that match title or year." << endl;
            cout << "   QUIT - Exits media database program." << endl;
            cout << "------------------------------------------------" << endl;
        }
    }
}

