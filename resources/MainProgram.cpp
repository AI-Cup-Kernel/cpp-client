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
	auto owners=game.getOwners();
	int me=game.getPlayerID();
	auto all_troops=game.getTroopsCount();
	std::cout<<"init has been called";
	try{
		if(stra_nodes.size()<2){
			auto owners=game.getOwners();
			auto strategic_nodes=game.getStrategicNodes();
			for(const auto& i:strategic_nodes){
				if(owners[i.first]==0){
					if(stra_nodes.size()==2)
						break;
					stra_nodes.push_back(i.first);

				}
			}
		}
		if(cnt%3==1||cnt%3==0){
			game.putOneTroop(stra_nodes[cnt%2]);
		}else{
			for(auto i:owners){
				if(i.second==me||all_troops[i.first]<3){
					game.putOneTroop(i.first);
					break;
				}else if(i.second!=me){
					game.putOneTroop(i.first);
					nodes.push_back(i.first);
					
				}

			}

		}
		cnt++;

		
		
		
	}
	catch(const std::exception& e){
		std::cerr<<e.what()<<std::endl;
	}
	
}
void yourTurn() {
	//it will be executed in a new thread when turn requestws arrives
	std::cout << "yourTurn has been called" << std::endl;
	try{
		int me=game.getPlayerID();
		auto owners=game.getOwners();
		auto adj=game.getAdj();
		auto all_troops=game.getTroopsCount();
		int all=game.getNumberOfTroopsToPut();
		for(auto i:stra_nodes){
			
			game.putTroop(stra_nodes[i],all/4);
		}
		for(int i=0;i<nodes.size();i++){
			game.putTroop(stra_nodes[i],all/2/nodes.size());
			
		}
		game.nextState();
		for(auto node:nodes){
			if(owners[node]!=me){
				continue;
			}
			int troops=all_troops[node];
			for(auto adj_node :adj[node]){
				if(troops>2*all_troops[adj_node]){
					if(game.attack(node,adj_node,1,0.4)){
						nodes.push_back(adj_node);
					}
				}
			}
		
		}
		game.nextState();
		turn_cnt++;
		if(turn_cnt>70&&!has_forted){
			game.fort(stra_nodes[0],all_troops[stra_nodes[0]]);
			has_forted=true;
		}
		
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