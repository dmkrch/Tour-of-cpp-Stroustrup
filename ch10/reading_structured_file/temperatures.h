#include <vector>
#include <fstream>

#define HOURS_IN_DAY 24
#define DAYS_IN_MONTH 32
#define MONTHS_IN_YEAR 12


namespace WeatherStatistics
{
    //-------------------CONSTANTS AND VARIABLES----------------------------------
    const int not_a_reading = -7777; // below absolute zero
    const int not_a_month = -1; // skipped month
    constexpr int implausible_min = -200;
    constexpr int implausible_max = 200;


    //-------------------USER-TYPES---------------------------------
    // day including 24 hours, each of them is initialized with const not_a_reading
    struct Day
    {
        std::vector<double> hour{std::vector<double>(HOURS_IN_DAY, not_a_reading)};
    };

    struct Month
    {
        int month{not_a_month}; // jan is 0
        std::vector<Day> day{DAYS_IN_MONTH}; // [1,31] creating 31 days
    };

    struct Year 
    {
        int year;
        std::vector<Month> month{MONTHS_IN_YEAR}; // [0,11] (january is 0)
    };

    struct Reading
    {
        int day;
        int hour;
        double temperature;
    };


    //---------------------USEFUL FUNCTIONS-----------------------
    void end_of_loop(std::istream& ist, char term, const std::string& message);
    bool is_valid(const Reading& r);
    int month_to_int(std::string s);


    //---------------------OPERATORS OVERLOAD----------------

    // reading temperatures from stream is to r
    // format : ( 3 4 9.7)
    // here we check format, not correct data
    std::istream& operator>>(std::istream& is, Reading& r);

    // reading object of Month class from stream is to m
    // format : { month feb ... }
    std::istream& operator>>(std::istream& is, Month& m);

    std::istream& operator>>(std::istream& is, Year& y);
}