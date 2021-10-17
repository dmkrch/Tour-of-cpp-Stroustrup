#include <iostream>
#include <vector>

namespace Chrono
{
    enum class Month
    {
        Jan=1, Feb, Mar, Apr, May, Jun,
        Jul, Aug, Sep, Oct, Nov, Dec
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
        Month GetMonth() const { return month; }
        int GetYear() const { return year; }
        int GetDay() const { return day; }

        // modification functions
        void AddDay(int n);
        void AddMonth(int n);
        void AddYear(int n);

    private:
        int year;
        Month month;
        int day;
        bool IsValid();
    };

    std::ostream& operator<<(std::ostream& os, Month m);
    std::ostream& operator<<(std::ostream& os, const Date& d);

    bool IsLeapYear(int n);
    bool operator==(const Date& a, const Date& b);
    bool operator!=(const Date& a, const Date& b);   
}