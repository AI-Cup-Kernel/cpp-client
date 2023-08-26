#include "MainProgram.h"
Game game;
//write your program for each state here
void init() {
	//it will be executed in a new thread when init requestws arrives
	int i = 0;
	while (true) {
		i++;
		auto x =  game.getAdj();
		if (x.size() == 0) {
			break;
		}

	}
	std::cout << i << "-----\n";
	
}
void yourTurn() {
	//it will be executed in a new thread when turn requestws arrives
	std::cout << "yourTurn has been called" << std::endl;
}
void end() {
	//it will be executed in a new thread when end requestws arrives

	std::cout << "end has been called" << std::endl;
}