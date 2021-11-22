#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <list>
#include <bits/stdc++.h>
#include <string>

namespace WumpusGame {
    enum class RoomType {
        EmptyRoom,
        BatRoom,
        WumpusRoom,
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
        bool HasMonstersNearby() {
            for (int i = 0; i < neighborRooms.size(); ++i) {
                if (neighborRooms[i]->GetRoomType()==RoomType::BatRoom || 
                    neighborRooms[i]->GetRoomType()==RoomType::PitRoom ||
                    neighborRooms[i]->GetRoomType()==RoomType::WumpusRoom)
                        return true;
            }
            return false;
        }
        
        bool IsRoomWithMonsters() {
            return !(roomType==RoomType::EmptyRoom);
        }

        std::vector<std::string> GetAttentionMessages() {
            std::vector<std::string> attentions;

            for (int i = 0; i < neighborRooms.size(); ++i) {
                switch(neighborRooms[i]->GetRoomType()) {
                case RoomType::BatRoom:
                    attentions.push_back("YOU HEAR A RUSTLING...\n");
                    break;
                case RoomType::PitRoom:
                    attentions.push_back("YOU FEEL A COLD WIND BLOWING FROM A NEARBY CAVERN...\n");
                    break;
                case RoomType::WumpusRoom:
                    attentions.push_back("YOU SMELL SOMETHING TERRIBLE NEARBY...\n");
                    break;
                }
            }

            return attentions;
        }

        bool HasSuchNeighbor(int n) {
            for (int i = 0; i < neighborRooms.size(); ++i) {
                if (neighborRooms[i]->GetRoomNumber() == n) 
                    return true;
            }
            
            return false;
        }

        RoomType GetRoomType() { return roomType; }

        std::string GetRoomTypeString();

        // returns "1 3 5" for example
        std::string GetRoomNeighborsString();
    };

    // returns "Empty room #8 tunnels: 1 11 6\n" for example
    std::ostream& operator<<(std::ostream& os, Room r);



    class Player {
    private:
        bool isAlive;
        bool hasWon;

    public:
        Player() : isAlive(true) {};
        void SetPlayerDeath() { isAlive=false; }
        bool IsAlive() { return isAlive; }
        bool HasWon() { return hasWon; }
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

        void MovePlayer(int tunnelTo) {
            for (int i = 0; i < rooms.size(); ++i) {
                if (rooms[i].GetRoomNumber()==tunnelTo) {
                    playerRoomId=i;
                    break;
                }
            }
        }

        bool MovePlayerLogic(int tunnelTo) {
            if (rooms[playerRoomId].HasSuchNeighbor(tunnelTo)) {
                // if so, than we find this neighbor
                int neighborId = 0;
                while(rooms[neighborId].GetRoomNumber() != tunnelTo)
                    ++neighborId;
                
                // first checking if room has monsters
                if (rooms[neighborId].IsRoomWithMonsters()) {
                    switch(rooms[neighborId].GetRoomType()) {
                    case RoomType::WumpusRoom:
                        std::cout << "WUMPUS HAS EATEN YOU!\n";
                        player.SetPlayerDeath();
                        break;
                    case RoomType::PitRoom:
                        std::cout << "YYYIIIIEEEE . . . FELL IN PIT\n";
                        player.SetPlayerDeath();
                        break;
                    case RoomType::BatRoom:
                        std::cout << "ZAP—SUPER BAT SNATCH! ELSEWHEREVILLE FOR YOU!\n";
                        MovePlayer(tunnelTo);
                        // we should move player to random room, but without bats;
                        break;
                    }
                }
                else if (rooms[neighborId].HasMonstersNearby()) { // room without monsters, but monsters are nearby
                    std::vector<std::string> attentions = rooms[neighborId].GetAttentionMessages();
                    
                    for (int i = 0; i < attentions.size(); ++i)
                        std::cout << attentions[i];
                    
                    MovePlayer(tunnelTo);
                }
                else if (rooms[neighborId].GetRoomType()==RoomType::EmptyRoom)
                    MovePlayer(tunnelTo);

                return true;
            }
            else
                return false;
        }

        std::string GetStartGameInfo() {
            std::stringstream ss;

            ss << "WELCOME TO GAME HUNT THE WUMPUS!" << std::endl;

            if (rooms[playerRoomId].HasMonstersNearby()) { // room without monsters, but monsters are nearby
                std::vector<std::string> attentions = rooms[playerRoomId].GetAttentionMessages();
                
                for (int i = 0; i < attentions.size(); ++i)
                    ss << attentions[i];
            }

            return ss.str();
        }

        std::string GetStartRoundInfo() {
            std::stringstream ss;
            ss << "YOU ARE IN ROOM " << rooms[playerRoomId].GetRoomNumber() << std::endl
            << "TUNNELS LEAD TO " << rooms[playerRoomId].GetRoomNeighborsString() << std::endl;

            return ss.str();
        }
    };
}