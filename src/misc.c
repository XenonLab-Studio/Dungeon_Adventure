/* misc.c

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


OBJECT *getPassageTo(OBJECT *targetLocation)
{
   OBJECT *obj;
   /*
   scans all objects until it encounters a passage that starts from player-> location
   (the current position of the player) to targetLocation (the function parameter).
   */
   for (obj = objs; obj < endOfObjs; obj++)
   {
      if (obj->location == player->location &&
          obj->destination == targetLocation)
      {
         /* if a matching passage is found, it returns a pointer to the object of the passage. */
         return obj;
      }
   }
   /* if such a passage does not exist, it returns NULL. */
   return NULL;
}

DISTANCE distanceTo(OBJECT *obj)
{
   return
      obj == NULL                                 ? distUnknownObject :
      obj == player                               ? distPlayer :
      obj == player->location                     ? distLocation :
      obj->location == player                     ? distHeld :
      obj->location == player->location           ? distHere :
      getPassageTo(obj) != NULL                   ? distOverthere :
      obj->location == NULL                       ? distNotHere :
      obj->location->location == player           ? distHeldContained :
      obj->location->location == player->location ? distHereContained :
                                                    distNotHere;
}

/*
Function parseObject returns a pointer to the object with the specified tag (parameter noun).
If the tag could not be found in the array of objects, NULL is returned.
*/
OBJECT *parseObject(const char *noun)
{
   OBJECT *obj, *found = NULL;
   for (obj = objs; obj < endOfObjs; obj++)
   {
      if (noun != NULL && strcmp(noun, obj->tag) == 0)
      {
         found = obj;
      }
   }
   return found;
}

/*
Function personHere returns a pointer to the person in the same position as the player or NULL if the player is alone.
I have also included a comprehensive and codified list of non-player (in this case, only one: the guard).
*/
OBJECT *personHere(void)
{
   OBJECT *obj;
   for (obj = objs; obj < endOfObjs; obj++)
   {
      /* simplify some code using the new distanceTo function. */
      if (distanceTo(obj) == distHere && obj == guard)
      {
         return obj;
      }
   }
   return NULL;
}

/*
Function listObjectsAtLocation prints a list of objects (items, persons)
present at a specific location (parameter location).
Object player is excluded from the list.
*/
int listObjectsAtLocation(OBJECT *location)
{
   int count = 0;
   OBJECT *obj;
   for (obj = objs; obj < endOfObjs; obj++)
   {
      if (obj != player && obj->location == location)
      {
         /*
         The list starts with a line “You see:”, but it is not printed until the first object is found.
         There is no output when the list is empty.
         */
         if (count++ == 0)
         {
            printf("You see:\n");
         }
         printf("%s\n", obj->description);
      }
   }
   /* The function returns the number of objects in the list. */
   return count;
}
