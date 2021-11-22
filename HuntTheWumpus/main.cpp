#include <iostream>
#include "Gameplay.h"

using namespace WumpusGame;

int main() {
    srand((unsigned) time(0));

    GamePlay gameplay;
    
    std::cout << gameplay.GetStartGameInfo();

    while (gameplay.IsGameContinues()) {
        std::cout << std::endl;
        std::cout << gameplay.GetStartRoundInfo();

        TurnChoice choice = gameplay.GetPlayerTurnChoice();

        std::string shootPath;

        switch (choice) {
        case TurnChoice::Move:
            std::cout << "WHERE TO?   ";
            int tunnelTo;
            std::cin >> tunnelTo;
            
            if (!gameplay.MovePlayerLogic(tunnelTo))
                std::cout << "WRONG TUNNEL!" << std::endl;

            break;
        case TurnChoice::Shoot:
            std::cout << "SPECIFY TUNNELS (ex. 2 5 ...)   ";
            std::cin.get(); // consume the \n
            std::getline(std::cin, shootPath);
            gameplay.ShootLogic(shootPath);
        
            break;

        case TurnChoice::Quit:
            gameplay.QuitTheGame();
            break;
        }
    }

    std::cout << gameplay.GetEndGameInfo();
    
    return 0;
}