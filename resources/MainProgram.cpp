#include "MainProgram.h"
#include <vector>
Game game;


void init() {
	//it will be executed in a new thread once the init request arrives
	
	std::cout<<"init has been called"<<std::endl;
	try{
		
		
		game.putOneTroop(1);

		
		
		
		
		
	}
	catch(const std::exception& e){
		std::cerr<<e.what()<<std::endl;
	}
	
}
void yourTurn() {
	//it will be executed in a new thread when turn requestws arrives
	std::cout << "yourTurn has been called" << std::endl;
	try{
		game.putTroop(1,3);
		game.putTroop(2,3);
		
	//write your code here
	
		
	}
	catch(const std::exception& e){
		std::cerr<<e.what()<<std::endl;
	}
}
void end() {
	//it will be executed in a new thread when end requestws arrives

	std::cout << "end has been called" << std::endl;
	try{
		//write your code here
		
	}
	catch(const std::exception& e){
		std::cerr<<e.what()<<std::endl;
	}
}
