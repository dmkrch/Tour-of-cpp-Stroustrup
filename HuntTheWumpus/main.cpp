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

        switch (choice) {
        case TurnChoice::Move:
            std::cout << "WHERE TO?   ";
            int tunnelTo;
            std::cin >> tunnelTo;
            
            if (!gameplay.MovePlayerLogic(tunnelTo))
                std::cout << "WRONG TUNNEL!" << std::endl;

            break;
        case TurnChoice::Shoot:
            break;
        }
    }
    
    std::cout << "YOU LOST\n";

    return 0;
}