// Напишите программу, которая для данного имени файла и слова вы­
// водит все строки файла,  содержащие это слово, вместе с  номерами 
// строк. Указание: getline (). 

#include <iostream>
#include <fstream>
#include <sstream>

int main()
{
    try
    {
        std::cout << "Enter file name: ";
        std::string fileName;
        std::cin >> fileName;
        std::ifstream ist{fileName};

        if (!ist.good())
            throw "Can't open file!\n";

        std::cout << "Enter word: ";
        std::string word;
        std::cin >> word;
        
        std::string text;
        getline(ist, text);

        // now we have all the information in var 'text'
        // and word in var 'word'

        char ch;

        std::vector<std::string> rows;

        std::string row = "";
        for (int i = j = 0; i = text[i]; ++i)
        {
            row[i] = (char)i;

            if ()
        }


    }
    catch(...)
    {
        std::cerr << "General error\n";
    }
}