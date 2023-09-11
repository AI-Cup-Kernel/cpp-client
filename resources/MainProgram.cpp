#include "MainProgram.h"
#include <vector>
Game game;


void init() {
	//it will be executed in a new thread once the init request arrives
	
	std::cout<<"init"<<std::endl;
	try{
		
	
		

		
		
		
		
		
	}
	catch(const std::exception& e){
		std::cerr<<e.what()<<std::endl;
	}
	
}
void yourTurn() {
	//it will be executed in a new thread when turn requestws arrives
	std::cout << "turn" << std::endl;
	try{
		
		
	//write your code here
	
		
	}
	catch(const std::exception& e){
		std::cerr<<e.what()<<std::endl;
	}
}
void end() {
	//it will be executed in a new thread when end requestws arrives

	std::cout << "end" << std::endl;
	try{
		//write your code here
		
	}
	catch(const std::exception& e){
		std::cerr<<e.what()<<std::endl;
	}
}
