#pragma once

#include "Client.h"
#include <string>
#include <vector>
#include <iostream>

//SESSION CLASS ()
class Session{
 public:

    enum sessionType{
            Ranked, 
            Casual, 
            HeadTohead
        };  

     sessionType session_type;
     int session_ID = int(&session_ID);
     int maxPlayers = 0;
     bool running=false;
     bool allowJoinWhileRunning=false;
     Session(){};
     ~Session(){};   


    //Clients in session
    std::vector<Client *> clients;
    
    int clientCount();

    void addClient(std::string alias, Client::coordinates start_pos);  
    void removeClient(std::string pname);
    void removeAllClients();


};

