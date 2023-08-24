#include <iostream>

#include <string>
#include <map>
#include <sstream>
#include <chrono>
#include "resources/MainProgram.h"
#include "resources/GameHandeler.h"

#pragma comment(lib, "ws2_32.lib")

const int PORT = 12345;
const std::string HOST = "127.0.0.1";

extern Game game;


int main() {
	
	GameHandeler handeler(HOST,PORT);
	game.SetHostsPort(PORT);
	game.SetHost(HOST);
	handeler.begin();
	game.SetToken(handeler.GetToken());
	handeler.ready();
	while (true);//wait or server
	//it will not pass above line but for fuurther development I placed the line below
	handeler.join();
	
   
   
}
