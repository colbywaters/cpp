/*
 * Media definition
 *
 * Colby Waters
 * 12/3/2022
 */

using namespace std;

/*
 * Media - Base class for media assets
 */
class Media
{
public:
    Media() {}

    /*
    * Destructor - Base class destructor.
    */
    virtual ~Media();

    const char* GetTitle() { return title; }
    const uint32_t GetYear() { return year; }

    /*
    * Print - Base class print method. Child classes should call this.
    */
    virtual void Print();

    /*
    * SetTitle - Set title from user input
    */
    void SetTitle();

    /*
    * SetYear - Set year from user input
    */
    void SetYear();

private:
    char title[256];
    uint32_t year;
};
