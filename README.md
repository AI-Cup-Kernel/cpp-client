# cpp-client
<h1> cpp-client</h1>
<h2>How to Set Up</h2>
We have prepared a make file to simplify the building process. If you are using any editor or IDE, please build using the make file. First, you should install `make`. If you are on macOS or Linux, there is a good chance you already have `make` installed.
notice :you might run to some errors saying some dll file doesnt exist so install them :)
notice2: make sure to install g++ compiler(you need to worry about it when you have always used visual studio only(withh pretty much other IDEs it automaticly wil ber installed but make sure of that and make sure that its address is in the path(again,it is most probably there)))
#### Linux
<code>sudo apt-get update</code><br>
<code>sudo apt-get install make</code><br>
<code>sudo apt-get install libcurl4-openssl-dev</code><br>

#### macOS
(if you don't have HomeBrew)<code>/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"</code><br>
You can also install it similarly to Windows, but look for the macOS version on this <a href="https://www.gnu.org/software/make/">link</a>. Just look for binaries, not the source.
<code>brew install make</code>

<code>brew install curl-openssl</code>
(If these two commands didn't work, use the instructions for Windows).

<strong>if you got errors using an IDE or editor do the things described in the last paragraph of the windows section</strong>
#### Windows

for make Download <a href="https://sourceforge.net/projects/gnuwin32/files/make/3.81/make-3.81-bin.zip/download?use_mirror=netactuate&download=&failedmirror=deac-riga.dl.sourceforge.net">this</a> and extract it.thete is a make.exe in bin folder.add bin folder to windows path we will use that later (alternatively you can use the complete path like C:/Users/..../bin/make.exe to run that later).
for libcurl go to <a href="https://curl.se/download.html">this link </a> and download the binary version suitable for you (not the links on the top look for them in the table)
fir example for windows 64 bit download <a href="https://curl.se/windows/dl-8.2.1_8/curl-8.2.1_8-win64-mingw.zip">this</a>.
extract the downloaded file anywhere.
<em>Optional:</em> Add its `include` and `lib` directories to your PATH.
If you are using a code editor like VS Code and it doesn't recognize `<curl/curl.h>`, hover over the error, click on Quick Fix, and go to Include Path settings. There you should see a line like <code>One include path per line.</code> Write the path below it, and it will be recognized. Of course, this is not necessary because you are using `make` to build, and it's just to prevent annoying editor errors.
In the make file, change the `path:` to your own libcurl directory (if you installed it manually on Windows). For example, for me, it looks like (path:=C:/libcurl).


#### run the program
Now, just run the `make` command in the root folder (if it's not recognized, run it using the full path), and the executable the file named `game` will be built.
