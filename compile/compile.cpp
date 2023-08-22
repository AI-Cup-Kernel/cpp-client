#include <iostream>
#include <fstream>

#define COMMAND ""
#ifdef _WIN32
#define COMMAND "-lws2_32"
#else
#define COMMAND ""
#endif


bool isFirstCompile() {
    std::ifstream file("first_compile.txt");
    return !file.is_open();  // If file doesn't exist, it's the first compile
}

void markCompile() {
    std::ofstream file("first_compile.txt");
    if (file.is_open()) {
        file << "compiled";  // Write something to the file
        file.close();
    }
}

int main() {
    if (isFirstCompile()) {
        std::cout<<"first compile"<<std::endl;
        system("g++ -c stdafx.cpp -o stdafx.o ");
        markCompile();  // Mark that it's no longer the first compile

    } else {
        std::cout << "Not the first compile." << std::endl;
    }
    system(("g++ -c ../resources/Game.cpp -o game.o -include stdafx.h "+std::string(COMMAND)).c_str());
    system(("g++ -c ../resources/GameHandeler.cpp -o GameHandeler.o -include stdafx.h "+std::string(COMMAND)).c_str());
    system(("g++ -c ../resources/MainProgram.cpp -o MainProgram.o -include stdafx.h "+std::string(COMMAND)).c_str());
    system(("g++ -c ../client.cpp -o client.o -include stdafx.h "+std::string(COMMAND)).c_str());
    system(("g++ stdafx.o game.o GameHandeler.o MainProgram.o client.o -o mygame "+std::string(COMMAND)).c_str());

    return 0;
}

