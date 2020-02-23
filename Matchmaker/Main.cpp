#include "Server.h"
#include <stdio.h>
#include <iostream>
#include <thread>
#include <string>
#include <chrono>


using namespace std;
void sleep(int ms);

void header(string msg)
{
    printf("\n\n%s\n",msg.c_str());
    printf("--------------------------------------------\n");
    sleep(3000);
}

int main(int acount, char *args[]) 
{
    if (acount>1)
    { 
        if (string(args[1])=="SERVER")
        {
            if (acount>4)
            {
                /*Pretend a request is made from a socket (client) to join a matchmaking session, for the sake of simplicity in this example
                  the session properties are defined here by the runtime arguments of main(). 

                  There would be some logic here to check to see if newly requested matchmaking sessions are of the same type, if so it would add them to
                  An existing session or create a new one if a session doesn't arleady exist for the type.

                  Additionally the server would necessarily wait after starting a session of a given type, for futher connections for a certain amount of time.
                  If no additional connections were made for the same session type the session would be terminated.

                  All of the above pretty much requires an actual networking layer that would be dynamically sending requests to the matchmaking server. 
                  I wasn't going to take the time to implement a legit network layer in vanilla C++. ^_^
                */
                Server *server = new Server();
                server->newSession(args[2],args[3],args[4]);//Port, Session_type, Players(1v1, 2v2)

                
                //Create some clients to Test
                int maxPlayers = server->session.maxPlayers;
                Client::coordinates pos{ 10.0, 22.0, 0.0 };

               
                //Attempt to start session without Players
                header("Attempt to start session without Players");
                server->startSession();

                //Add required clients
                header("Add required clients");
                for (int i=0;i<maxPlayers;i++)
                {
                    sleep(2000);
                    pos.x=i*27;
                    pos.y=i*35;
                    pos.z=0;
                    server->session.addClient(string("Player"+to_string(i)), pos);
				}

                //Try to add one more client when session is full
                header("Try to add one more client when session is full");
                server->session.addClient(string("Player"+to_string(25)), pos);

                //start session when it is full
                header("start session when it is full");
                server->startSession();

                //attempt to remove non existing Player
                printf("\n\nattempt to remove non existing Player\n");
                printf("--------------------------------------------\n");
                sleep(3000);
                server->session.removeClient(string("PlayerThatDoesntExist"));

                //Remove 2 clients by name
                header("Remove 2 clients by name");
                for (int i=0;i<2;i++)
                {
                    server->session.removeClient(string("Player"+to_string(i)));
                    sleep(2000);
                }

                //Attempt to add client when session running (flag to enable or disable in session params)
                header("Attempt to add client when session running (flag to enable or disable in session params)");
                server->session.addClient(string("Player"+to_string(18)), pos);

                //Attempt to start session when already started
                header("Attempt to start session when already started");
                server->startSession();

                //End the session with players still in it (They should be cleared)
                header("End the session with players still in it (They should be cleared)");
                server->endSession();
			}
            else
            {
                cout << "Not enough args for Server. Ex. SERVER port sessionType max_players"   << endl;  
			}

            printf("Server shutting down...");
            return 0;
        }      
    }
    else 
    {
        cout << "Invalid arguments";
        return 1;
    }   
}


void sleep(int ms)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}