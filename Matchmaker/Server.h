#pragma once

#include "Session.h"
#include <thread>
#include <iostream>
#include <mutex>
#include <chrono>
//Server will have session
//Sessions contain clients



//SERVER CLASS () Ranked, Casual, Head to head with a friend (invite)
class Server {
 public:

     

    //mutex serverMutex;
    bool serverRunning;
    //Currently running session

    void sessionRunner();

    //void sessionRunner();
    //std::thread ServersessionThread(sessionRunner);
    Session session;

    void endSession();
    void newSession(char* port, char* stype, char* max_players);
    void startSession();
 private:
};

