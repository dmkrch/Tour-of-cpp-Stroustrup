#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <list>
#include <bits/stdc++.h>

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

    void AddNeighbor(Room* room) { neighborRooms.push_back(room); }
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
    GameField() {
        // here we need to set up rooms and other stuff.

        // creating player instance
        player = Player();

        // creating 20 rooms with unique number 1..20
        rooms = std::vector<Room>(20);


        for (int i = 0; i < rooms.size(); ++i) {
            // here we need to set neighbors for rooms[i]
            // so actions below will be done 3 times. As each room must
            // have 3 neighbors

            // vector for storing neighbors amount that room
            // already has. id of vector 'relationsCount' == id of room
            // so, relationsCount[2] = 2 means that rooms[2] has 2 neighbors
            // relationsCount[5] = 0 means that rooms[5] has no neighbors yet
            std::vector<int> relationsCount(20, 0);

            // list for storing id of vacant Rooms. List - because we will need to delete a lot
            // vacant - means that room doesn't have all 3 neighbors(relationsCount< 3)
            // it is used for generating random vacantRoomsId, so that every game will
            // have new relations
            std::list<int> vacantRoomsId;
            
            // pushing all rooms to vacantRooms cause they dont have neighbors yet
            for (int i = 0; i < 20; ++i)
                vacantRoomsId.push_back(i);

            
            // now we need to find 3 neighbors for rooms[i]
            for (int j = 0; j < 3; ++j) {
                // get random vector id (rand from [0,size-1])
                int randomListId = 0;
                randomListId = rand() % vacantRoomsId.size();

                std::list<int>::iterator it = randomListId.begin();
                std::advance(it, 5);
                int neighborId = *it;

                // main action - adding neighbor to Room[i]
                rooms[i].AddNeighbor(&rooms[i]);
                relationsCount[neighborId]++;

                // checking whether we need to remove room from vacant rooms vector
                if (relationsCount[neighborId]==3)
                    vacantRoomsId.remove(neighborId);
            }
        }
    }
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

        std::cout << "There is no such choice! Try again...\n";
    }

    return static_cast<TurnChoice>(choice);
}


int main() {
    srand((unsigned) time(0));

    // GameField g;
    // // first we need to set up rooms
    // std::vector<Room> rooms{20};

    // Player player;

    // std::cout << "Welcom to game 'Hunt The Hampus'!\n";

    // while (player.IsAlive()) {
    //     TurnChoice choice = GetPlayerTurnChoice();

    //     switch (choice) {
    //     case TurnChoice::Move:
    //         std::cout << "Your choice is move" << std::endl;
            
    //         break;

    //     case TurnChoice::Shoot:
    //         std::cout << "Your choice is shoot" << std::endl;

    //         break;
    //     }
    // }

    return 0;
}