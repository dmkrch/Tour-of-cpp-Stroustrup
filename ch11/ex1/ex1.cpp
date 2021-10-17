#include <iostream>
#include <fstream>
#include <sstream>

bool isUpper(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
        return true;
    
    return false;
}

char upperToLower(char ch)
{
    return ch - ('A' - 'a');
}

int main()
{
    std::string inpFile; 
    std::cout << "enter file name to open: ";
    std::cin >> inpFile;
    std::ifstream ist(inpFile);

    std::string outFile;
    std::cout << "enter file name to write: ";
    std::cin >> outFile;
    std::ofstream ost(outFile);

    std::string allText;
    std::getline(ist, allText);

    char ch;

    for (int i = 0; ch = allText[i]; ++i)
    {
        std::cout << ch;

        if (isUpper(ch))
            ost << upperToLower(ch);
        else
            ost << ch;
    }

    return 0;
}