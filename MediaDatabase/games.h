/*
 * Games definition
 *
 * Colby Waters
 * 12/3/2022
 */

/*
 * Game - Game is a type of media asset
 */
class Game : public Media
{
public:
    Game() {}

    /*
    * Destructor - Game class destructor.
    */
    virtual ~Game();

    /*
    * SetPublisher - Set publisher from user input
    */
    void SetPublisher();

    /*
    * SetRating - Set rating from user input
    */
    void SetRating();

    /*
    * Print - Overrides parent implementation for print.
    */
    virtual void Print();

private:
    // Video games must have the fields: title, year, publisher, rating.
    char publisher[256];
    uint32_t rating;
};
