#include "Server.h"
#include <string>
#include <iostream>

	
//End the session
void Server::endSession()
{
	printf("Ending session...\n\n");
	session.removeAllClients();
	session.running = false;
	printf("Session ended...\n\n");
}

void Server::startSession()
{
	if (!session.running)
	{
		if (session.clientCount()<session.maxPlayers)
		{
			printf("Cannot start the session. Still waiting for players. %d out of %d\n\n",session.clientCount(),session.maxPlayers);
			return;
		}
		else
		{
			session.running = true;
			printf("Session running!\n\n");
		}
	}
	else
	{
		printf("Session already running.\n\n");
	}

}

//Create a new matchmaking session
void Server::newSession(char* port, char* stype, char* max_players) {
	printf("Starting session on port: %s \n", port);
	printf("Session Type is: %s \n", stype);
	printf("Max player count is: %s \n", max_players);

	std::string sessionType=std::string(stype);

	if (sessionType=="Ranked")
	{
		session.session_type = Session::sessionType::Ranked;
	}
	else if (sessionType == "Casual") 
	{
		session.session_type = Session::sessionType::Casual;
	}
	else if (sessionType == "Headtohead") 
	{
		session.session_type = Session::sessionType::HeadTohead;
	}
	else{
		printf("Unknown session type specified: %s \n", stype);
		return;
	}

	session.maxPlayers = atoi(max_players);
}