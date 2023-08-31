#include "MainProgram.h"
#include <vector>
Game game;
using namespace std;
//write your program for each state here
int target_node=-2;
vector<int> stra_nodes;
vector<int> nodes;
int cnt=0;
int target_node=-1;
int current_target_node=-1;
vector<int> path;
int turn_cnt=0;
bool has_forted=false;
/*void BFS(int origin){
	int my_id=game.getPlayerID();
	auto all_strategic_nodes_with_points=game.getStrategicNodes();
	vector<int> all_strategic_nodes;
	for(int i=0;i<all_strategic_nodes_with_points.size();i++){
		all_strategic_nodes.push_back(all_strategic_nodes_with_points[i].first);
	}
	auto owners=game.getOwners();
	auto adj=game.getAdj();
	vector<vector<int>> queue;
	queue.push_back({origin});
	vector<int> current={};
	while(queue.empty()){
		current=queue.back();
		queue.pop_back();
		for(const auto i:adj[current.back()]){
			if(all_strategic_nodes.find(i)!=all_strategic_nodes.end()&& owners[i]!=my_id)
		}

	}

}*/
void init() {
	//it will be executed in a new thread when init requestws arrives
	
	std::cout<<"init has been called";
	try{
		
		
		
		
	}
	catch(const std::exception& e){
		std::cerr<<e.what()<<std::endl;
	}
	
}
void yourTurn() {
	//it will be executed in a new thread when turn requestws arrives
	std::cout << "yourTurn has been called" << std::endl;
	try{
	
		
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