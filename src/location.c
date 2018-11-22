/* location.c

***********************************************
* PROJECT NAME: DUNGEON ADVENTURE             *
* AUTHOR: STEFANO PERIS                       *
* PRODUCT PUBLISHER: XENONLAB STUDIO (c) 2018 *
* LANGUAGE: ANSI C                            *
* COMPILER: GNU GCC COMPILER (MINGW INCLUDED) *
***********************************************

---------------------------------------------------------------
- For error/bug reporting, e-mail: xenonlab.develop@gmail.com -
---------------------------------------------------------------

-----------
- LICENSE -
-----------

This content is free and open-source. You can modify and redistribute it under these terms.

Dungeon Adventure is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Dungeon Adventure is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <string.h>

#include "../include/object.h"
#include "../include/misc.h"


/*
I use a single statement to define a type (struct location),
declare a variable (locs) and fill it with its initial values.
*/
struct location {
   const char *description;
   const char *tag;
}

/*
the array length (2) is not specified; in this case, the C compiler will automatically determine the length
based on the number of elements in the initializer.
*/
locs[] = {
   {"an open field", "field"},
   {"a little cave", "cave"}
};

/*
as variable locs is allocated statically, we can let the compiler calculate the total number of locations;
very handy once we start adding more locations. The calculation is rather obscure to look at,
so we give it a meaningful name numberOfLocations. The calculation is performed at compile time, not in runtime,
so we can use #define without any performance penalty.
*/
#define numberOfLocations (sizeof(locs) / sizeof(*locs))

/*
the position of the player is initially 0 (indexing of the first element of the array: the field);
change the value of locationOfPlayer to move the player to a different location.
*/
static unsigned locationOfPlayer = 0;

void executeLook(const char *noun)
{
   if (noun != NULL && strcmp(noun, "around") == 0)
   {
      printf("You are in %s.\n", player->location->description);
      /*
      use function listObjectsAtLocation (from misc.c)
      to show a list of items and persons present at the current location.
      */
      listObjectsAtLocation(player->location);
   }
   else
   {
      printf("I don't understand what you want to see.\n");
   }
}

void executeGo(const char *noun)
{
   /*
   using the parseObject function (from misc.c),
   I deleted the loop from the executeGo function,
   making the code more readable.
   */
   OBJECT *obj = parseObject(noun);
   if (obj == NULL)
   {
      printf("I don't understand where you want to go.\n");
   }
   else if (obj == player->location)
   {
      printf("You are already there.\n");
   }
   else
   {
      printf("OK.\n");
      player->location = obj;
      executeLook("around");
   }
}
