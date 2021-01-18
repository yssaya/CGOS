# CGOS
CGOS is Go server for computer programs.
Server is running on  
<http://www.yss-aya.com/cgos/>  
Original source code are on sourceforge.  
<https://sourceforge.net/projects/cgos/>

# Start server
server  
$ cd server/cgos.vfs  
$ tclkit main.tcl ../cgos9.cfg

make standings.html  
$ cd server/webuild.vfs  
$ nohup tclkit webmain.tcl ../cgos9.cfg > /dev/null &

byeselo  
$ cd bin  
$ nohup ./wbloop > /dev/null &

# Anchor
cd cgosboar/9x9  
$ sqlite3 cgos.state  
sqlite> .tables  
sqlite> select * from games;  
anchors   clients   gameid    games     password  
sqlite> .schema anchors  
sqlite> insert into anchors values('Gnugo-3.7.10-a1', 1800);  
sqlite> .exit

# Don Dailey original explanation
How to build from source:  
1. Add tclkit to your path  
  a. Identify your platform specific tclkit in third_party directory  
  b. Make a copy (called tclkit) somewhere in your path  
     (~/bin and /usr/bin are good candidates for unix systems)  
2. Go into the directory of the component you wish to build (e.g. client)
3. Run gnu make (on unix systems, this should just be 'make')

Is there no tclkit for your environment in the repository?  
Other kits can be downloaded from  http://www.equi4.com

Don't have gnu make?  You have two options:  
Option 1: Obtain gnu make  
Option 2: Run individual commands out of the makefile (e.g. sdx wrap)
