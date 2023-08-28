# cpp-client
<h1> cpp-client</h1>
<h2>How to Set Up</h2>
We have prepared a make file to simplify the building process. If you are using any editor or IDE, please build using the make file. First, you should install `make`. If you are on macOS or Linux, there is a good chance you already have `make` installed.

<h3>Linux</h3>
<code>sudo apt-get update</code><br>
<code>sudo apt-get install make</code><br>
<code>sudo apt-get install libcurl4-openssl-dev</code><br>

<h3>macOS</h3>
(if you don't have HomeBrew)<code>/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"</code><br<
You can also install it similarly to Windows, but look for the macOS version on this <a href="https://www.gnu.org/software/make/">link</a>. Just look for binaries, not the source.
<code>brew install make</code>

<code>brew install curl-openssl</code>
(If these two commands didn't work, use the instructions for Windows).

<h3>Windows</h3>

Download <a href="https://sourceforge.net/projects/gnuwin32/files/make/3.81/make-3.81-bin.zip/download?use_mirror=netactuate&download=&failedmirror=deac-riga.dl.sourceforge.net">this</a> and install it.

<<<<<<< HEAD
#### macOS
If you don't have Homebrew, you can install it using the following command:

/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
You can also install it like in Windows, but look for the macOS version on this link. Just download the binaries, not the source.
=======
Now, extract it anywhere and add the `bin` folder to your PATH (or you can use the complete path instead of just the `make` command).
>>>>>>> 496e0596742c6674b3c50197018fd1077bd665c0


Go to this <a href="https://curl.se/download.html">link</a> and download the appropriate libcurl version for your Windows (64-bit) system. Note that you should download binaries listed in the long list below, not the source archives.
<a href="https://curl.se/windows/dl-8.2.1_7/curl-8.2.1_7-win64-mingw.zip">(For Windows 64-bit use this)</a>, extract the downloaded file anywhere.
<em>Optional:</em> Add its `include` and `lib` directories to your PATH. If you are using a code editor like VS Code and it doesn't recognize `<curl/curl.h>`, hover over the error, click on Quick Fix, and go to Include Path settings. There you should see a line like <code>One include path per line.</code> Write the path below it, and it will be recognized. Of course, this is not necessary because you are using `make` to build, and it's just to prevent annoying editor errors.

In the make file, change the `path:` to your own libcurl directory (if you installed it manually on Windows). For example, for me, it looks like (path:=C:/libcurl).
<h3>Run the program</h3>
Now, just run the `make` command in the root folder (if it's not recognized, run it using the full path), and the executable file named `game` will be built.
