#include <iostream>
#include <fstream>
#include <vector>

struct Reading 
{
    int hour;
    double temperature;
};

std::ostream& operator<<(std::ostream& os, Reading r)
{
    return os << r.hour << ": " << r.temperature << std::endl;
}

int main()
{
    try
    {
        std::cout << "Please enter file name: ";
        std::string iname;
        std::cin >> iname;

        std::ifstream ist(iname);   // ist - input stream for file iname
        if (!ist)
            std::cout << "Unable to open file " << iname << std::endl;
        else
            std::cout << "File has been opened" << std::endl;
        
        std::vector<Reading> temps;
        int hour;
        double temperature;
        while(ist >> hour >> temperature)
        {
            if (hour < 0 || 23 < hour)
                std::cout << "Incorrect time" << std::endl;
            temps.push_back(Reading{hour, temperature});
        }


        for (int i = 0; i < temps.size(); ++i)
            std::cout << temps[i];

        ist.close();
    }
    catch(...)
    {
        std::cout << "Some general error" << std::endl;
        return 1;
    }
    return 0;
}