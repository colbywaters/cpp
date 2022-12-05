/*
 * Music definition
 *
 * Colby Waters
 * 12/3/2022
 */

/*
 * Music - Music is a type of media asset
 */
class Music : public Media
{
public:
    Music() {}

    /*
    * Destructor - Music class destructor.
    */
    virtual ~Music();

    /*
    * SetPublisher - Set publisher from user input
    */
    void SetPublisher();

    /*
    * SetArtist - Set artist from user input
    */
    void SetArtist();

    /*
    * SetDuration - Set duration from user input
    */
    void SetDuration();

    /*
    * Print - Overrides parent implementation for print.
    */
    virtual void Print();

private:
    // Music must have the fields: title, artist, year, duration, publisher.
    char publisher[256];
    char artist[256];
    uint32_t duration;
};
