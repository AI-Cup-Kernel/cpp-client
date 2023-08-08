#include <iostream>

#include <string>
#include <map>
#include <winsock2.h>
#include <sstream>
#include <chrono>
#include "resources/MainProgram.h"
#include "resources/GameHandeler.h"

#pragma comment(lib, "ws2_32.lib")

const int PORT = 8080;
const std::string HOST = "127.0.0.1";

extern Game game;


int main() {
	httplib::Headers headers;
	GameHandeler handeler;
	game.SetHostsPort(PORT);
	game.SetHost(HOST);
	game.SetToken(handeler.GetToken());

	handeler.begin();
	while (true);//wait or server
	handeler.join();
	
   
   
}
