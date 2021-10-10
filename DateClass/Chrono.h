#include <iostream>
#include <vector>

namespace Chrono
{
    enum class Month
    {
        Jan=1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
    };

    enum class Day
    {
        monday, tuesday, wednesday, 
        thursday, friday, saturday, sunday
    };

    class Date
    {
    public:
        class InvalidDate {};
        Date(int y, Month m, int d);
        Date();
        
        // non-modification functions
        void ShowDate() const;
        Month get_month() const { return month; }
        int get_year() const { return year; }
        int get_day() const { return day; }

        // modification functions
        void add_day(int n);
        void add_month(int n);
        void add_year(int n);

    private:
        int year;
        Month month;
        int day;
        bool is_valid();
    };

    std::ostream& operator<<(std::ostream& os, Month m);
    std::ostream& operator<<(std::ostream& os, const Date& d);

    bool is_leapyear(int n);
    bool operator==(const Date& a, const Date& b);
    bool operator!=(const Date& a, const Date& b);   
}