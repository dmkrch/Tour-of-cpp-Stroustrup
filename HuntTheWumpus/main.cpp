#include <iostream>
#include <vector>

enum class RoomType {
    EmptyRoom,
    BatRoom,
    HampusRoom,
    HoleRoom
};

enum class TurnChoice {
    Move = 1,
    Shoot
};

class Room {
private:
    RoomType roomType;
    int roomNumber;
    int neighborRooms[3];

public:
    Room() : roomType(RoomType::EmptyRoom), roomNumber(0) {}
    int GetRoomNumber() const { return roomNumber; }
};


TurnChoice GetPlayerTurnChoice() {
    int choice = 0;

    while(std::cin) {
        std::cout << "Move or Shoot?" << std::endl;
        std::cout << "1. Move" << std::endl;
        std::cout << "2. Shoot" << std::endl;

        std::cin >> choice;

        if (choice==1||choice==2)
            break;

        std::cout << "Wrong number! Try again:\n";
    }

    return static_cast<TurnChoice>(choice);
}


int main() {
    // first we need to set up rooms
    std::vector<Room> rooms{20};

    std::cout << "Welcom to game 'Hunt The Hampus'!\n";

    while (true) {
        TurnChoice choice = GetPlayerTurnChoice();

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