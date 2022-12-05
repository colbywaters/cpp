/*
 * Movies definition
 *
 * Colby Waters
 * 12/3/2022
 */

/*
 * Movie - Movie is a type of media asset
 */
class Movie : public Media
{
public:
    Movie() {}

    /*
    * Destructor - Movie class destructor.
    */
    virtual ~Movie();

    /*
     * SetDirector - Set director from user input
     */
    void SetDirector();

    /*
     * SetRating - Set rating from user input
     */
    void SetRating();

    /*
     * SetDuration - Set duration from user input
     */
    void SetDuration();

    /*
    * Print - Overrides parent implementation for print.
    */
    virtual void Print();

private:
    // Movies must have the fields: title, director, year, duration, rating.
    char director[256];
    uint32_t duration;
    uint32_t rating;
};
