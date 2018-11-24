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
      switch (distanceTo(obj))
      {
      case distPlayer:
         printf("You should not be doing that to yourself.\n");
         break;
      case distHeld:
         printf("You already have %s.\n", obj->description);
         break;
      case distLocation:
      case distOverthere:
         printf("That's not an item.\n");
         break;
      case distHere:
         if (from == player)
         {
            printf("You have no %s.\n", noun);
         }
         else
         {
            printf("Sorry, %s has no %s.\n", from->description, noun);
         }
         break;
      case distHeldContained:
      case distHereContained:
         printf("Sorry, %s is holding it.\n", obj->location->description);
         break;
      default:
         /*
         I deliberately publish the noun here, not the description; that would give away too much of the game.
         For example, the player could make a lucky guess and type "get gold" without ever visiting the cave
         (where the gold coin is located).
         Responding with "You do not see a gold coin here" is like not being able to hide the wires that suspend
         the spaceships in a science fiction movie.
         Instead, we limit ourselves to echoing the name entered by the player: "You do not see any gold here".
         */
         printf("You don't see any %s here.\n", noun);
      }
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
