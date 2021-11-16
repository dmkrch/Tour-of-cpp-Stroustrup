#include <iostream>
#include "Gameplay.h"

using namespace HampusGame;

int main() {
    srand((unsigned) time(0));

    GamePlay gameplay;

    std::cout << "Welcom to game 'Hunt The Hampus'!\n";

    while (gameplay.IsGameContinues()) {
        TurnChoice choice = gameplay.GetPlayerTurnChoice();

        switch (choice) {
        case TurnChoice::Move:
            std::cout << "Your choice is move" << std::endl;
            
            break;

        case TurnChoice::Shoot:
            std::cout << "Your choice is shoot" << std::endl;

            break;
        }
    }

    return 0;
}