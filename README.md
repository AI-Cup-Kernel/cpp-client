# cpp-client
<h1> cpp-client</h1>
<h2>How to set up</h2>
we have prepared a make file to make building easier if you are using any edito o IDE please build using the make file
first you should install make(if you are mac or linux there is a godd chance you already have make  )

<h3>Linux</h3>
<code>sudo apt-get install make</code>
<h3>MacOs</h3>
(if you dont have HomeBrew)<code></code>/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"<code>
you could just install like window(but look for mac version in this <a href="https://www.gnu.org/software/make/">link</a>)
just look for binaries not source
<code>brew install make</code>

<h3>Windows</h3>

download <a href="https://sourceforge.net/projects/gnuwin32/files/make/3.81/make-3.81-bin.zip/download?use_mirror=netactuate&download=&failedmirror=deac-riga.dl.sourceforge.net">this</a>
and install

now extract it anywhere and add the bin folder in it to path (or instead of just make command you can just use the complete path)

<h2>installing libcurl</h2>
<h3>Linux</h3>
<code>sudo apt-get install libcurl4-openssl-dev</code>
<h3>MacOs</h3>
<code>brew install curl-openssl</code>
(for these two you can follow the windows instruction too)
<h3>windows</h3>
go to this <a href="https://curl.se/download.html">link</a> and download your apropraite libcurl version
note that you should download binaries listed in the long list below not the source archives
 extract the downloaded file any where 
 <italic>optional:</italic>add its include and lib to path
 then in any code editor you use add the path to include for example if you are using vs code:
 consider your path is "C:\\libcurl\\include" if you go to resources/game.cpp moset likely the editor is not recognizing <curl/curl.h>
 move your mouse on that and click on Quick Fix and go to Include Path settings there you should se a line like <code>One include path per line.</code>
 write the path under it and it will recognize it of course it is not neccessary because you are using make to build and its just for not getting annoying
 editor errors.