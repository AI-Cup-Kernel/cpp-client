#include "MainProgram.h"
Game game;
//write your program for each state here
void init() {
	//it will be executed in a new thread when init requestws arrives

	std::cout<<"init has been called";
	try{
		//write you code here

		int i = 0;
		while (true) {
			i++;
			try{
				auto x =  game.getAdj();
			}catch(...){
				
				break;

			}
		}
		std::cout<<i<<' ';
	}
	catch(const std::exception& e){
		std::cerr<<e.what()<<std::endl;
	}
	
		

	
	
}
void yourTurn() {
	//it will be executed in a new thread when turn requestws arrives
	std::cout << "yourTurn has been called" << std::endl;
	try{
		//write you code here
		
	}
	catch(const std::exception& e){
		std::cerr<<e.what()<<std::endl;
	}
}
void end() {
	//it will be executed in a new thread when end requestws arrives

	std::cout << "end has been called" << std::endl;
	try{
		//write you code here
		
	}
	catch(const std::exception& e){
		std::cerr<<e.what()<<std::endl;
	}
}