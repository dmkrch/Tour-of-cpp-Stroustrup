#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <list>
#include <bits/stdc++.h>
#include <string>
#include "colormod.h"

namespace WumpusGame {
    enum class RoomType {
        EmptyRoom,
        BatRoom,
        WumpusRoom,
        PitRoom
    };

    enum class TurnChoice {
        Move = 1,
        Shoot,
        Quit
    };

    class Room {
    public:
        Room() : roomType{RoomType::EmptyRoom}, roomNumber{0} { }

        void SetRoomNumber(int n) { roomNumber = n; }
        void SetRoomType(RoomType t) { roomType = t; }
        int GetRoomNumber() const { return roomNumber; }
        int GetFirstNeighborRoomNumber() { return neighborRooms[0]->GetRoomNumber(); }
        std::string GetRoomNeighborsString();
        RoomType GetRoomType() { return roomType; }

        // returns attention messages, depending on neighbor rooms - bats/wumpus/pits
        std::vector<std::string> GetAttentionMessages();

        // returns true if there is a monster nearby that room
        bool HasMonstersNearby();  

        // returns true if room has such neighbor with roomNumber
        bool HasSuchNeighbor(int roomNumber);
        bool IsRoomWithMonsters() { return !(roomType==RoomType::EmptyRoom); }
        void AddNeighbor(Room* room) { neighborRooms.push_back(room); }

    private:
        // members
        RoomType roomType;
        int roomNumber;
        std::vector<Room*> neighborRooms;
    };


    class Player {
    public:
        Player() : isAlive{true}, hasWon{false}, arrowsAmount{5} {};
        int GetArrowsAmount() { return arrowsAmount; }
        void SetPlayerDeath() { isAlive=false; }
        void SetPlayerVictory() { hasWon = true; }
        bool IsAlive() { return isAlive; }
        bool HasWon() { return hasWon; }
        void WasteArrow() { --arrowsAmount; }
        bool HasArrows() { return arrowsAmount; }

    private:
        bool isAlive;
        bool hasWon;
        int arrowsAmount;
    };


    class GamePlay {
    public:
        // default constructor that does some tricks before game
        GamePlay();

        // ends the game by setting gameover to true
        void QuitTheGame() { gameover = true; }

        // returns state of game: true if player is alive and not gameover
        bool IsGameContinues() { return (player.IsAlive() && !gameover && !player.HasWon()); }

        // gets player turn choice: either move or shoot from std::cin
        TurnChoice GetPlayerTurnChoice();

        // main logic for moving player. It expects that player stands somewhere and
        // wants to go to neighbor room, which has roomNumberTo room.roomNumber
        bool MovePlayerLogic(int roomNumberTo);

        // main logic for shooting. It expects that player stands somewhere and
        // wants to shoot in wumpus through rooms 2 4 5...(maximum is 5 rooms). 
        // if he mixed up the tunnels - he lost
        void ShootLogic(std::string path);

        // returns start game information and attentions if player is already nearby monsters
        std::string GetStartGameInfo();

        // returns player position info and tunnels to other rooms
        std::string GetStartRoundInfo();

        std::string GetEndGameInfo();
    
    private:
        bool gameover;
        Player player;
        std::vector<Room> rooms;
        int playerRoomId;
        Color::Modifier red=Color::FG_RED;
        Color::Modifier def=Color::FG_DEFAULT;
        Color::Modifier green=Color::FG_GREEN;
        Color::Modifier blue=Color::FG_BLUE;

        // function adds neighbors (n1, n2, n3) to room-argument 'r'
        void AddRoomNeighbors(Room& r, int n1, int n2, int n3);

        // sets all obstacles to rooms: bats, pits, hampus, playet
        void SetAllObastaclesInRooms();

        // just sets playerRoomId to needed room
        void MovePlayer(int roomNumberTo);

        void SetGameOver() { gameover = true; }
        
        int GetRoomIdByItsNumber(int roomNumber);
    };
}