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

        bool HasSuchNeighbor(int n) {
            for (int i = 0; i < neighborRooms.size(); ++i) {
                if (neighborRooms[i]->GetRoomNumber() == n) 
                    return true;
            }
            
            return false;
        }

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

        // returns state of game
        bool IsGameContinues() { return player.IsAlive(); }

        std::string RoomsInfoToString();

        TurnChoice GetPlayerTurnChoice();

        bool MovePlayer(int tunnelTo) {
            if (rooms[playerRoomId].HasSuchNeighbor(tunnelTo)) {
                // if so, than we find this neighbor and set it to player's position
                for (int i = 0; i < rooms.size(); ++i) {
                    if (rooms[i].GetRoomNumber()==tunnelTo) {
                        playerRoomId=i;
                        break;
                    }
                }
                return true;
            }
            else
                return false;
        }

        std::string GetStartRoundInfo() {
            // 1. objects interraction
            // 2. where is player
            // 3. attentions
            // 4. all neighbors

            std::stringstream ss;
            ss << "YOU ARE IN ROOM " << rooms[playerRoomId].GetRoomNumber() << std::endl
            << "TUNNELS LEAD TO " << rooms[playerRoomId].GetRoomNeighborsString() << std::endl;

            return ss.str();
        }
    };
}