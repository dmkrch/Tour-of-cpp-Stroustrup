#include "Gameplay.h"

namespace HampusGame {

    // ------------------------------class 'Room' definitions--------------------------
    std::string Room::GetRoomTypeString() {
        switch(roomType) {
        case RoomType::BatRoom:
            return std::string("Bat room");
        case RoomType::EmptyRoom:
            return std::string("Empty room");
        case RoomType::PitRoom:
            return std::string("Pit room");
        case RoomType::HampusRoom:
            return std::string("Hampus room");
        default:
            return "";
        }
    }

    std::string Room::GetRoomNeighborsString() {
        std::string neighbors = "";

        for (int i = 0; i < neighborRooms.size(); ++i) {
            int n = neighborRooms[i]->GetRoomNumber();
            neighbors += std::to_string(n);
            neighbors.push_back(' ');
        }

        return neighbors;
    }

    // -------------------------------class 'GamePlay' definitions--------------------

    GamePlay::GamePlay() {
        // here we need to set up rooms and other stuff.

        // creating player instance
        player = Player();

        // creating 20 rooms
        rooms = std::vector<Room>(20);

        // now we need to assign different numbers to rooms
        std::vector<int> differentRoomNumbers;
        std::vector<int> twentyNumbers;

        // vector for storing 20 numbers - these will be ids of rooms
        for (int i = 1; i <= 20; ++i) 
            twentyNumbers.push_back(i);

        int randId;
        int randomNumber;
        for (int i = 0; i < 20; ++i) {
            randId = rand() % twentyNumbers.size();
            randomNumber = twentyNumbers[randId];
            differentRoomNumbers.push_back(randomNumber);
            twentyNumbers.erase(twentyNumbers.begin() + randId);
        }

        // now we set room number 
        for (int i = 0; i < 20; ++i)
            rooms[i].SetRoomNumber(differentRoomNumbers[i]);

        // here we set relations (each room should be connected to 3 others)
        AddRoomNeighbors(rooms[0], 1, 4, 19);
        AddRoomNeighbors(rooms[1], 0, 2, 17);
        AddRoomNeighbors(rooms[2], 1, 3, 15);
        AddRoomNeighbors(rooms[3], 2, 4, 13);
        AddRoomNeighbors(rooms[4], 0, 3, 5);
        AddRoomNeighbors(rooms[5], 4, 6, 12);
        AddRoomNeighbors(rooms[6], 5, 7, 19);
        AddRoomNeighbors(rooms[7], 6, 8, 11);
        AddRoomNeighbors(rooms[8], 7, 9, 18);
        AddRoomNeighbors(rooms[9], 8, 10, 16);
        AddRoomNeighbors(rooms[10], 9, 11, 14);
        AddRoomNeighbors(rooms[11], 7, 10, 12);
        AddRoomNeighbors(rooms[12], 5, 11, 13);
        AddRoomNeighbors(rooms[13], 3, 12, 14);
        AddRoomNeighbors(rooms[14], 10, 13, 15);
        AddRoomNeighbors(rooms[15], 2, 14, 16);
        AddRoomNeighbors(rooms[16], 9, 15, 17);
        AddRoomNeighbors(rooms[17], 1, 16, 18);
        AddRoomNeighbors(rooms[18], 8, 17, 19);
        AddRoomNeighbors(rooms[19], 0, 6, 18);

        // now when we set relations, we need to set hampus, 2 pits, 2 bats
        // in random different rooms
        SetAllObastaclesInRooms();
    }


    void GamePlay::AddRoomNeighbors(Room& r, int n1, int n2, int n3) {
        r.AddNeighbor(&rooms[n1]);
        r.AddNeighbor(&rooms[n2]);
        r.AddNeighbor(&rooms[n3]);
    }


    void GamePlay::SetAllObastaclesInRooms() {
        // here we need to generate 6 random numbers - they are id of rooms
        // 0,1 for bat room; 2,3 for pit room; 4 for hampus room; 5 for player room

        // vector for storing all roomIds, from which we will random some and use
        std::vector<int> roomIds;
        for (int i = 0; i < 20; ++i)
            roomIds.push_back(i);

        // this vector is for randomed room id's
        std::vector<int> randomRoomIds;

        int randomVectorId;
        int roomIdForUse;
        for (int i = 0; i < 6; ++i) {
            randomVectorId = rand() % roomIds.size();
            roomIdForUse = roomIds[randomVectorId];
            randomRoomIds.push_back(roomIdForUse);
            roomIds.erase(roomIds.begin() + randomVectorId);
        }

        // placing bats
        for (int i = 0; i < 2; ++i)
            rooms[randomRoomIds[i]].SetRoomType(RoomType::BatRoom);
        
        // placing pits
        for (int i = 2; i < 4; ++i)
            rooms[randomRoomIds[i]].SetRoomType(RoomType::PitRoom);
        
        // placing hampus
        rooms[randomRoomIds[4]].SetRoomType(RoomType::HampusRoom);

        // saving player room id
        playerRoomId = randomRoomIds[5];
    }

    std::string GamePlay::RoomsInfoToString() {
        std::stringstream resultString;

        for (int i = 0; i < rooms.size(); ++i)
            resultString << rooms[i];

        resultString << "Player is in #" << rooms[playerRoomId].GetRoomNumber() << std::endl;

        return resultString.str();
    }


    TurnChoice GamePlay::GetPlayerTurnChoice() {
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


    std::ostream& operator<<(std::ostream& os, Room r)
    {
        return os << r.GetRoomTypeString() << " #" << r.GetRoomNumber() << " tunnels: " << r.GetRoomNeighborsString() << std::endl;
    }
}