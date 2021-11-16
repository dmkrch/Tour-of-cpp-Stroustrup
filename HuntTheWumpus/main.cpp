#include <iostream>
#include "Gameplay.h"

using namespace HampusGame;

int main() {
    srand((unsigned) time(0));

    GamePlay gameplay;

    std::cout << "WELCOME TO GAME HUNT THE HAMPUS!" << std::endl;

    while (gameplay.IsGameContinues()) {
        std::cout << gameplay.GetStartRoundInfo();
        
        TurnChoice choice = gameplay.GetPlayerTurnChoice();

        switch (choice) {
        case TurnChoice::Move:
            std::cout << "WHERE TO?   ";
            int tunnelTo;
            std::cin >> tunnelTo;
            
            if (!gameplay.MovePlayer(tunnelTo))
                std::cout << "WRONG TUNNEL!" << std::endl;

            break;
        case TurnChoice::Shoot:

            break;
        }
    }

    return 0;
}