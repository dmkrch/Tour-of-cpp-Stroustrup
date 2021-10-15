#include <iostream>
#include <vector>
#include <sstream>

int main()
{
    std::string command;
    std::getline(std::cin, command);
    std::stringstream ss(command);

    std::vector<std::string> words;
    for (std::string s; ss >> s; )
        words.push_back(s);

    for (int i = 0; i < words.size(); ++i)
        std::cout << i + 1 << ": " << words[i] << std::endl;

    return 0;
}