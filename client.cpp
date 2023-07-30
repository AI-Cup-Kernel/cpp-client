#include <iostream>

#include <string>
#include <map>
#include <winsock2.h>
#include <sstream>
#include <chrono>
#include "MainProgram.h"
#include "GameHandeler.h"
#pragma comment(lib, "ws2_32.lib")

const int PORT = 8080;//set the port here
const std::string response = "salam daaaaash";//set this to the response you want to give if the request reaches your-turn



int main() {
	httplib::Headers headers;
	GameHandeler handeler;

	handeler.begin();
	handeler.join();
	
   
   
}
