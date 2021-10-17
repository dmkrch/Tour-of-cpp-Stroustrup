#include <iostream>
#include <fstream>
#include "temperatures.h"

int main()
{
    std::cout << "Enter file name\n";
    std::string f_name;
    std::cin >> f_name;
    std::ifstream ist {f_name};
    if (!ist) throw "asdfasfd";

    std::vector<WeatherStatistics::Year> ys;
    while(true)
    {
        WeatherStatistics::Year y;
        if (!(ist>>y)) break;
        ys.push_back(y);
    }

    std::cout << "Readed: " << ys.size() << " years records\n";

    return 0; 
}