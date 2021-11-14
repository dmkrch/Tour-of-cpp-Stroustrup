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
    // members
    RoomType roomType;
    int roomNumber;
    std::vector<Room*> neighborRooms;

public:
    // functions
    Room() : roomType(RoomType::EmptyRoom), roomNumber(roomUniqueNumber) {
        ++roomUniqueNumber;
    }

    ~Room() {
        --roomUniqueNumber;
    }

    int GetRoomNumber() const { return roomNumber; }

    // members
    static int roomUniqueNumber;
};

int Room::roomUniqueNumber = 1;


class Player {
private:
    bool isAlive;

public:
    Player() : isAlive(true) {};
    void SetPlayerDeath() { isAlive=false; }
    bool IsAlive() { return isAlive; }
};


class GameField {
private:
    Player player;
    std::vector<Room> rooms;
public:

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

    Player player;

    std::cout << "Welcom to game 'Hunt The Hampus'!\n";

    while (player.IsAlive()) {
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