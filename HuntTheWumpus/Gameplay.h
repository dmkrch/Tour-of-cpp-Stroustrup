#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <list>
#include <bits/stdc++.h>

namespace HampusGame {
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


    // std::ostream& operator<<(std::ostream& os, Room r)
    // {
    //     return os << "room #" << r.GetRoomNumber() << std::endl <<
    //     "neighbors: " << r.GetRoomNeighbors() << std::endl <<
    //     "type: " << r.GetRoomType();
    // }

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
        int player_room_id;

        void AddRoomNeighbors(Room& r, int n1, int n2, int n3) {
            r.AddNeighbor(&rooms[n1]);
            r.AddNeighbor(&rooms[n2]);
            r.AddNeighbor(&rooms[n3]);
        }

        void SetAllObastaclesInRooms() {
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
            player_room_id = randomRoomIds[5];
        }

    public:
        GamePlay() {
            // here we need to set up rooms and other stuff.

            // creating player instance
            player = Player();

            // creating 20 rooms with unique number 1..20
            rooms = std::vector<Room>(20);

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
}