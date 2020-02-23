#pragma once

#include <thread>
#include <string>
#include <iostream>

//Client CLASS ()
class Client{

 public:   

     struct coordinates
     {
         float x = 0;
         float y = 0;
         float z = 0;
     };

     Client(std::string alias, Client::coordinates start_pos)
     {
        player_pos = start_pos;
        player_alias = alias;
        std::cout << "Client created ["<<player_alias << "] at pos ("<<player_pos.x<<","<<player_pos.y<<","<<player_pos.z<<")"<<std::endl;
     }
    ~Client(){}
    

/////////////////////////////////////////////////////////////////////////////////////////////////
//          PROPERTIES
/////////////////////////////////////////////////////////////////////////////////////////////////
    //Player Properties
    int client_ID = int(&client_ID);
    coordinates player_pos;
    std::string player_alias = "";


/////////////////////////////////////////////////////////////////////////////////////////////////
//          PLAYER METHODS
/////////////////////////////////////////////////////////////////////////////////////////////////
    void updatePlayerPos(coordinates newPos);



 private:
};