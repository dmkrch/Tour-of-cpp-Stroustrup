#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <list>
#include <bits/stdc++.h>
#include <string>

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

        std::string GetRoomTypeString();

        // returns "1 3 5" for example
        std::string GetRoomNeighborsString();
    };

    // returns "Empty room #8 tunnels: 1 11 6\n" for example
    std::ostream& operator<<(std::ostream& os, Room r);



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
        int playerRoomId;

        // function adds neighbors (n1, n2, n3) to room-argument 'r'
        void AddRoomNeighbors(Room& r, int n1, int n2, int n3);

        // sets all obstacles to rooms: bats, pits, hampus, playet
        void SetAllObastaclesInRooms();

    public:
        // default constructor that does some tricks before game
        GamePlay();

        bool IsGameContinues() {
            return player.IsAlive();
        }
        // 
        std::string RoomsInfoToString();
        TurnChoice GetPlayerTurnChoice();
    };
}