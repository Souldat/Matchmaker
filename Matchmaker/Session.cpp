#include "Session.h"
#include <string>
#include <iostream>
using namespace std;


int Session::clientCount()
{
	return static_cast<int>(clients.size());
}

void Session::addClient(std::string alias, Client::coordinates start_pos)
{
    if (!running || allowJoinWhileRunning)
    {
        if ((clientCount()<maxPlayers))
        {
            Client* newClient = new Client(alias, start_pos);
            clients.push_back(newClient);
		}
        else
        {
            printf("Cannot add player %s because the session is already full!\n\n",alias.c_str());  
		}
	}
    else
    {
        printf("Cannot add a client while session is in progress unless allowJoinWhileRunning is set to true!\n\n");
	}
}

    //Remove client by player name
    void Session::removeClient(string playerName)
    {
        
        bool clientFound=false;
        cout << "CLIENT COUNT: " << clientCount()<< std::endl;

        for (int i=0;i<clientCount();i++)
        {
            if (clients[i]->player_alias == playerName)
            {           
                clientFound=true;
                printf("Dropping client %s with id %d\n", clients[i]->player_alias.c_str(), clients[i]->client_ID);
                clients.erase(clients.begin()+i);
			}
		}
        if (!clientFound)
        {
            printf("Failed to remove client by name. Player with alias %s doesn't exist\n",playerName.c_str());
		}
	}

     void Session::removeAllClients()
     {
        printf("Session ending, removing all clients...\n\n");
        cout << "CLIENT COUNT: " << clientCount() << std::endl;
        printf("Dropping remaining clients...");
        clients.clear();
	 }