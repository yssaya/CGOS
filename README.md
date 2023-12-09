# CGOS
CGOS is a Go server for computer programs.
Server is running on  
<http://www.yss-aya.com/cgos/>  
Latest (2023/12/09) code is here.  
This version can show winrate, and has my cgos changes.  
<https://github.com/zakki/cgos>
Original source code are on sourceforge.  
<https://sourceforge.net/projects/cgos/>

# Start server
server  
$ cd server/cgos.vfs  
$ tclkit main.tcl ../cgos9.cfg  
$ cd cgosboar/9x9  
$ echo ban_user_name >> badusers.txt

make standings.html  
$ cd server/webuild.vfs  
$ nohup tclkit webmain.tcl ../cgos9.cfg > /dev/null &

byeselo  
$ cd bin  
$ nohup ./wbloop > /dev/null &

# Anchor
$ cd cgosboar/9x9  
$ sqlite3 cgos.state  
sqlite> .tables  
sqlite> select * from games;  
anchors   clients   gameid    games     password  
sqlite> .schema anchors  
sqlite> insert into anchors values('Gnugo-3.7.10-a1', 1800);  
sqlite> .exit

# Changes
1. Recent 300 games on cross-table page.  
2. Default rating is average of active players.  
3. WGo viewer  
4. 7.0 komi and handling draw for rating calculation.  
5. Shorter pgn file for BayesElo (cgosBayes).  
6. Forbid number only account.  
7. Bug fixed to send info all 'catch {puts $soc "info $msg"}'  
8. badusers.txt for not removing dead stones or too many timeout.  
9. Reduce anchor vs anchor.

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
