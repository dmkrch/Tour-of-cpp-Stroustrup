#include "Gameplay.h"

namespace WumpusGame {

    // ------------------------------class 'Room' definitions--------------------------
    std::string Room::GetRoomNeighborsString() {
        std::string neighbors = "";

        for (int i = 0; i < static_cast<int>(neighborRooms.size()); ++i) {
            int n = neighborRooms[i]->GetRoomNumber();
            neighbors += std::to_string(n);
            neighbors.push_back(' ');
        }

        return neighbors;
    }

    bool Room::HasMonstersNearby() {
        for (int i = 0; i < static_cast<int>(neighborRooms.size()); ++i) {
            if (neighborRooms[i]->GetRoomType()==RoomType::BatRoom || 
                neighborRooms[i]->GetRoomType()==RoomType::PitRoom ||
                neighborRooms[i]->GetRoomType()==RoomType::WumpusRoom)
                    return true;
        }
        return false;
    }

    std::vector<std::string> Room::GetAttentionMessages() {
        std::vector<std::string> attentions;

        attentions.push_back("\n");

        for (int i = 0; i < static_cast<int>(neighborRooms.size()); ++i) {
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
            case RoomType::EmptyRoom:
                break;
            }
        }

        return attentions;
    }

    bool Room::HasSuchNeighbor(int roomNumber) {
        for (int i = 0; i < static_cast<int>(neighborRooms.size()); ++i) {
            if (neighborRooms[i]->GetRoomNumber() == roomNumber) 
                return true;
        }
        
        return false;
    }

    // -------------------------------class 'GamePlay' definitions--------------------

    GamePlay::GamePlay() {
        // here we need to set up rooms and other stuff.
        gameover=false;

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

    void GamePlay::MovePlayer(int roomNumberTo) {
        for (int i = 0; i < static_cast<int>(rooms.size()); ++i) {
            if (rooms[i].GetRoomNumber()==roomNumberTo) {
                playerRoomId=i;
                break;
            }
        }
    }

    bool GamePlay::MovePlayerLogic(int roomNumberTo) {
        if (rooms[playerRoomId].HasSuchNeighbor(roomNumberTo)) {
            // if so, than we find this neighbor id
            int neighborId = GetRoomIdByItsNumber(roomNumberTo);
            
            // first checking if room has monsters
            if (rooms[neighborId].IsRoomWithMonsters()) {
                switch(rooms[neighborId].GetRoomType()) {
                case RoomType::EmptyRoom:
                    break;
                case RoomType::WumpusRoom:
                    std::cout << std::endl << "WUMPUS HAS EATEN YOU!" << std::endl;
                    player.SetPlayerDeath();
                    break;
                case RoomType::PitRoom:
                    std::cout << std::endl << "YYYIIIIEEEE . . . FELL IN PIT" << std::endl;
                    player.SetPlayerDeath();
                    break;
                case RoomType::BatRoom:
                    std::cout << std::endl << "ZAP—SUPER BAT SNATCH! ELSEWHEREVILLE FOR YOU!" << std::endl;
                    // we should move player to random room, but without bats;
                    int randId = rand() % rooms.size();

                    // skipping bat rooms
                    while(rooms[randId].GetRoomType()==RoomType::BatRoom)
                        randId = rand() % rooms.size();

                    // first we move player to neighbor room of result room
                    int neighborToResultRoomNumber = rooms[randId].GetFirstNeighborRoomNumber();
                    MovePlayer(neighborToResultRoomNumber);

                    std::cout << std::endl << "BAT HAS MOVED YOU INTO ROOM " << 
                        rooms[randId].GetRoomNumber() << std::endl;

                    // and then we move again player to result room
                    MovePlayerLogic(rooms[randId].GetRoomNumber());
                    break;
                }
            }
            else
                MovePlayer(roomNumberTo);

            return true;
        }
        else
            return false;
    }

    int GamePlay::GetRoomIdByItsNumber(int roomNumber) {
        for (int i = 0; i < static_cast<int>(rooms.size()); ++i) {
            if (rooms[i].GetRoomNumber()==roomNumber)
                return i;
        }

        return -1;
    }


    std::string GamePlay::GetStartGameInfo() {
        std::stringstream ss;

        ss << blue << "\t\t\t\tWELCOME TO GAME HUNT THE WUMPUS!" << def;

        return ss.str();
    }

    std::string GamePlay::GetStartRoundInfo() {
        std::stringstream ss;
        ss << "------------------------------------------------------------------";

        if (rooms[playerRoomId].HasMonstersNearby()) { // room without monsters, but monsters are nearby
            std::vector<std::string> attentions = rooms[playerRoomId].GetAttentionMessages();
            
            for (int i = 0; i < static_cast<int>(attentions.size()); ++i)
                ss << red << attentions[i] << def;
        }
        
        ss << std::endl << "YOU ARE IN ROOM " << green << rooms[playerRoomId].GetRoomNumber() << def << std::endl;
        ss << "TUNNELS LEAD TO " << green << rooms[playerRoomId].GetRoomNeighborsString() << def << std::endl << std::endl;

        return ss.str();
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
        rooms[randomRoomIds[4]].SetRoomType(RoomType::WumpusRoom);

        // saving player room id
        playerRoomId = randomRoomIds[5];
    }

    TurnChoice GamePlay::GetPlayerTurnChoice() {
        std::string choice;

        while(true) {
            std::cout << "MOVE, SHOOT OR QUIT ?(M-S-Q)?   ";
            std::cin >> choice;

            if (choice=="s"||choice=="S"||choice=="m"||choice=="M"||choice=="q"||choice=="Q")
                break;

            std::cout << "BAD INPUT, TRY AGAIN" << std::endl;
        }

        if (choice=="s" || choice=="S")
            return TurnChoice::Shoot;
        else if (choice=="m" || choice=="M")
            return TurnChoice::Move;
        else
            return TurnChoice::Quit;
    }

    std::string GamePlay::GetEndGameInfo() {
        std::stringstream ss;

        if (player.HasWon())
            ss << std::endl << "YOU WON" << std::endl;
        else if (!player.IsAlive())
            ss << std::endl << "YOU LOST" << std::endl;
        else if (gameover)
            ss << "";

        return ss.str();
    }

    void GamePlay::ShootLogic(std::string path) {
            std::stringstream ss;
            ss << path;

            int roomNumber;
            std::vector<int> shootRoomNumbers;
            while(!ss.eof()) {
                ss >> roomNumber;
                shootRoomNumbers.push_back(roomNumber);
            }

            if (shootRoomNumbers.size() > 5) {
                std::cout << "TOO MANY TUNNELS! MAXIMUM IS FIVE" << std::endl;
                return;
            }

            int currentArrowRoomId = playerRoomId;

            for (int i = 0; i < static_cast<int>(shootRoomNumbers.size()); ++i) {
                if (rooms[currentArrowRoomId].HasSuchNeighbor(shootRoomNumbers[i])) {
                    // moving currentArrowRoomId to next room
                    currentArrowRoomId = GetRoomIdByItsNumber(shootRoomNumbers[i]);

                    // heck if wumpus is there. If so, player killed
                    // him and has won the game
                    // if not - continue the cycle

                    if (rooms[currentArrowRoomId].GetRoomType()==RoomType::WumpusRoom) {
                        std::cout << std::endl << "YOU KILLED WUMPUS!" << std::endl;
                        player.SetPlayerVictory();
                        return;
                    }
                }
                else {
                    std::cout << std::endl << "WRONG TUNNEL PATH! YOU LOST" << std::endl;
                    gameover=true;
                    return;
                }
            }

            // if cycle has left the scope - that means player missed the shot
            std::cout << std::endl << "YOU MISSED YOUR SHOT!" << std::endl;
            player.WasteArrow();

            if (!player.HasArrows()) {
                std::cout << std::endl << "YOU HAVE WASTED ALL YOUR ARROWS! YOU LOST" << std::endl;
                gameover=true;
                return;
            }

            std::cout << player.GetArrowsAmount() << " ARROWS LEFT!" << std::endl;
        }
}