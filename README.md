<pre>
 
  *******************************************************************************
            |                   |                  |                     |
   _________|________________.=""_;=.______________|_____________________|_______
  |                   |  ,-"_,=""     `"=.|                  |
  |___________________|__"=._o`"-._        `"=.______________|___________________
            |                `"=._o`"=._      _`"=._                     |
   _________|_____________________:=._o "=._."_.-="'"=.__________________|_______
  |                   |    __.--" , ; `"=._o." ,-"""-._ ".   |
  |___________________|_._"  ,. .` ` `` ,  `"-._"-._   ". '__|___________________
            |           |o`"=._` , "` `; .". ,  "-._"-._; ;              |
   _________|___________| ;`-.o`"=._; ." ` '`."\` . "-._ /_______________|_______
  |                   | |o;    `"-.o`"=._``  '` " ,__.--o;   |
  |___________________|_| ;     (#) `-.o `"=.`_.--"_o.-; ;___|___________________
  ____/______/______/___|o;._    "      `".o|o_.--"    ;o;____/______/______/____
  /______/______/______/_"=._o--._        ; | ;        ; ;/______/______/______/_
  ____/______/______/______/__"=._o--._   ;o|o;     _._;o;____/______/______/____
  /______/______/______/______/____"=._o._; | ;_.--"o.--"_/______/______/______/_
  ____/______/______/______/______/_____"=.o|o_.--""___/______/______/______/____
  /______/______/______/______/______/______/______/______/______/______/______/
  *******************************************************************************
___________________________________________________________________________________
 ___  _   _ _  _  ___ ___ ___  _  _     _   _____   _____ _  _ _____ _   _ ___ ___ 
|   \| | | | \| |/ __| __/ _ \| \| |   /_\ |   \ \ / / __| \| |_   _| | | | _ \ __|
| |) | |_| | .` | (_ | _| (_) | .` |  / _ \| |) \ V /| _|| .` | | | | |_| |   / _|
|___/ \___/|_|\_|\___|___\___/|_|\_| /_/ \_\___/ \_/ |___|_|\_| |_|  \___/|_|_\___|
___________________________________________________________________________________

</pre>

<br>

## INSTALLATION

<br>

### Unix/Linux
----------------------

On Linux (and other Unix-like systems), I do not guarantee that it will work
under Windows and MacOS, in case of problems contact me:

**Linux Ubuntu/Mint:**
$ sudo apt-get install git build-essential cmake make gawk

**Arch Linux/Manjaro:**
$ sudo pacman -S git base-devel cmake make gawk

**Build**
Open a terminal window, and navigate to your Downloads directory: <br>
1. **$ git clone https://github.com/XenonLab-Studio/Dungeon_Adventure.git** <br>
2. **$ cd Dungeon_Adventure** <br>
3. **$ cmake .** <br>
4. **$ make** <br>
5. **$ cd build** <br>
6. **$ ./dungeonadv** to start the game! <br>

**Optional:** *to clean the folder from the compilation files, write "make clean-all" Cleans all files except the "build" directory and the executable you created.*

<br>

### Windows
-----------------

*Is possible to build this code for Windows 10 (compiler MinGW)*.

<br>

### MacOS

*The build should be identical on MacOS (the project uses the standard C libraries). I do not own MacOS, so I do not have any useful information to give.*

<br>

## LICENSE

(c) 2018 Stefano Peris

email: <xenonlab.develop@gmail.com>

Dungeon Adventure is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Dungeon Adventure is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
