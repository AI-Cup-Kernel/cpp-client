# cpp-client
<h1> cpp-client</h1>
note that if you compile using terminal and not IDEs like visual sudio it is essential that you compile like this

<code>g++ client.cpp  resources/GameHandeler.cpp  resources/MainProgram.cpp resources/game.cpp -o your_output_executable -lws2_32</code>

for faster compilation you can use precompile by running compile.exe(source code available in compile.cpp) that compiles externals just once and other times linkes them to others.
in visual studio or other IDE you may not need them so just include externals and resources and stdafx.h and stdafx.cpp and just compile
using IDEs(like visual studio) will make compilation faster