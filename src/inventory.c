/* inventory.c

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

#include "../include/object.h"
#include "../include/misc.h"


/*
moveObject is a generic function to move an object from one location to another;
it is used to get, drop, give and ask an item.
*/
static void moveObject(const char *noun, OBJECT *from, OBJECT *to)
{
   OBJECT *obj = parseObject(noun);
   if (obj == NULL)
   {
      printf("I don't understand what item you mean.\n");
   }
   else if (from != obj->location)
   {
      printf("You can't.\n");
   }
   else if (to == NULL)
   {
      printf("There is nobody here to give that to.\n");
   }
   else
   {
      obj->location = to;
      printf("OK.\n");
   }
}

void executeGet(const char *noun)
{
   moveObject(noun, player->location, player);
}

void executeDrop(const char *noun)
{
   moveObject(noun, player, player->location);
}

void executeGive(const char *noun)
{
   /*
   because of the simplicity of the parser, the give and ask commands have only one argument: the item.
   the person involved is implicit using the personHere function.
   */
   moveObject(noun, player, personHere());
}

void executeAsk(const char *noun)
{
   moveObject(noun, personHere(), player);
}

void executeInventory(void)
{
   /*
   function listObjectsAtLocation is defined in misc.c/misc.h. Its return value tells us how many objects were found.
   */
   if (listObjectsAtLocation(player) == 0)
   {
      /* l'utente si aspetta qualche risposta, anche quando l'elenco degli oggetti è vuoto. */
      printf("You are empty-handed.\n");
   }
}
