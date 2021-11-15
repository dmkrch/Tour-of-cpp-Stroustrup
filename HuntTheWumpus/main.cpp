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
    PitRoom
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
    Room() : roomType(RoomType::EmptyRoom), roomNumber(0) { }

    void SetRoomNumber(int n) { roomNumber = n; }
    void SetRoomType(RoomType t) { roomType = t; }
    void AddNeighbor(Room* room) { neighborRooms.push_back(room); }
    int GetRoomNumber() const { return roomNumber; }
};

class Player {
private:
    bool isAlive;

public:
    Player() : isAlive(true) {};
    void SetPlayerDeath() { isAlive=false; }
    bool IsAlive() { return isAlive; }
};


class GamePlay {
private:
    Player player;
    std::vector<Room> rooms;
public:
    GamePlay() {
        // here we need to set up rooms and other stuff.

        // creating player instance
        player = Player();

        // creating 20 rooms with unique number 1..20
        rooms = std::vector<Room>(20);

        // here we set relations 
        rooms[0].AddNeighbor(&rooms[1]);
        rooms[0].AddNeighbor(&rooms[4]);
        rooms[0].AddNeighbor(&rooms[19]);

        rooms[1].AddNeighbor(&rooms[0]);
        rooms[1].AddNeighbor(&rooms[2]);
        rooms[1].AddNeighbor(&rooms[17]);

        rooms[2].AddNeighbor(&rooms[1]);
        rooms[2].AddNeighbor(&rooms[3]);
        rooms[2].AddNeighbor(&rooms[15]);

        rooms[3].AddNeighbor(&rooms[2]);
        rooms[3].AddNeighbor(&rooms[4]);
        rooms[3].AddNeighbor(&rooms[13]);

        rooms[4].AddNeighbor(&rooms[0]);
        rooms[4].AddNeighbor(&rooms[3]);
        rooms[4].AddNeighbor(&rooms[5]);

        rooms[5].AddNeighbor(&rooms[4]);
        rooms[5].AddNeighbor(&rooms[6]);
        rooms[5].AddNeighbor(&rooms[12]);

        rooms[6].AddNeighbor(&rooms[5]);
        rooms[6].AddNeighbor(&rooms[7]);
        rooms[6].AddNeighbor(&rooms[19]);

        rooms[7].AddNeighbor(&rooms[6]);
        rooms[7].AddNeighbor(&rooms[8]);
        rooms[7].AddNeighbor(&rooms[11]);

        rooms[8].AddNeighbor(&rooms[7]);
        rooms[8].AddNeighbor(&rooms[9]);
        rooms[8].AddNeighbor(&rooms[18]);

        rooms[9].AddNeighbor(&rooms[8]);
        rooms[9].AddNeighbor(&rooms[10]);
        rooms[9].AddNeighbor(&rooms[16]);

        rooms[10].AddNeighbor(&rooms[9]);
        rooms[10].AddNeighbor(&rooms[11]);
        rooms[10].AddNeighbor(&rooms[14]);

        rooms[11].AddNeighbor(&rooms[7]);
        rooms[11].AddNeighbor(&rooms[10]);
        rooms[11].AddNeighbor(&rooms[12]);

        rooms[12].AddNeighbor(&rooms[5]);
        rooms[12].AddNeighbor(&rooms[11]);
        rooms[12].AddNeighbor(&rooms[13]);

        rooms[13].AddNeighbor(&rooms[3]);
        rooms[13].AddNeighbor(&rooms[12]);
        rooms[13].AddNeighbor(&rooms[14]);

        rooms[14].AddNeighbor(&rooms[10]);
        rooms[14].AddNeighbor(&rooms[13]);
        rooms[14].AddNeighbor(&rooms[15]);

        rooms[15].AddNeighbor(&rooms[2]);
        rooms[15].AddNeighbor(&rooms[14]);
        rooms[15].AddNeighbor(&rooms[16]);

        rooms[16].AddNeighbor(&rooms[9]);
        rooms[16].AddNeighbor(&rooms[15]);
        rooms[16].AddNeighbor(&rooms[17]);

        rooms[17].AddNeighbor(&rooms[1]);
        rooms[17].AddNeighbor(&rooms[16]);
        rooms[17].AddNeighbor(&rooms[18]);

        rooms[18].AddNeighbor(&rooms[8]);
        rooms[18].AddNeighbor(&rooms[17]);
        rooms[18].AddNeighbor(&rooms[19]);

        rooms[19].AddNeighbor(&rooms[0]);
        rooms[19].AddNeighbor(&rooms[6]);
        rooms[19].AddNeighbor(&rooms[18]);


        // vector for storing room numbers
        std::vector<int> roomNumbers;

        for (int i = 1; i <= 20; ++i)
            roomNumbers.push_back(i);


        for (int i = 0; i < 20; ++i) {
            // randoming ids
            int randomId = rand() % roomNumbers.size(); // random number from [0, arr.size]
            int randomRoomNumber = roomNumbers[randomId];

            rooms[i].SetRoomNumber(randomRoomNumber);

            // deleting this roomNumber from roomNumbers, because it is already used
            roomNumbers.erase(roomNumbers.begin() + randomId);
        }

        roomNumbers.clear();

        // now when we set relations, we need to set hampus, 2 holes, 2 bats
        // in random different rooms
        std::vector<int> roomIds;
        for (int i = 0; i < 20; ++i)
            roomIds.push_back(i);

        int randomRoomId = rand() % roomIds.size();
        int roomId = roomIds[randomRoomId];

        rooms[roomId].SetRoomType(RoomType::BatRoom);
        std::cout << "Bat #1 in " << rooms[roomId].GetRoomNumber() << std::endl;
        // deleting this roomId from roomIds, because it is already used
        roomIds.erase(roomIds.begin() + randomRoomId);


        randomRoomId = rand() % roomIds.size();
        roomId = roomIds[randomRoomId];
        rooms[roomId].SetRoomType(RoomType::BatRoom);
        std::cout << "Bat #1 in " << rooms[roomId].GetRoomNumber() << std::endl;
        // deleting this roomId from roomIds, because it is already used
        roomIds.erase(roomIds.begin() + randomRoomId);

        randomRoomId = rand() % roomIds.size();
        roomId = roomIds[randomRoomId];
        rooms[roomId].SetRoomType(RoomType::PitRoom);
        std::cout << "Pit #1 in " << rooms[roomId].GetRoomNumber() << std::endl;
        // deleting this roomId from roomIds, because it is already used
        roomIds.erase(roomIds.begin() + randomRoomId);

        randomRoomId = rand() % roomIds.size();
        roomId = roomIds[randomRoomId];
        rooms[roomId].SetRoomType(RoomType::PitRoom);
        std::cout << "Pit #2 in " << rooms[roomId].GetRoomNumber() << std::endl;
        // deleting this roomId from roomIds, because it is already used
        roomIds.erase(roomIds.begin() + randomRoomId);

        randomRoomId = rand() % roomIds.size();
        roomId = roomIds[randomRoomId];
        rooms[roomId].SetRoomType(RoomType::PitRoom);
        std::cout << "Hampus in " << rooms[roomId].GetRoomNumber() << std::endl;
        // deleting this roomId from roomIds, because it is already used
        roomIds.erase(roomIds.begin() + randomRoomId);
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

    GamePlay g;    

    std::cout << "Welcom to game 'Hunt The Hampus'!\n";

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