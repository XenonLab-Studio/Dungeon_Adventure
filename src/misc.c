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


/*
function parseObject returns a pointer to the object with the specified tag (parameter noun).
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
function listObjectsAtLocation prints a list of objects (items, persons)
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
         the list starts with a line “You see:”, but it is not printed until the first object is found.
         There is no output when the list is empty.
         */
         if (count++ == 0)
         {
            printf("You see:\n");
         }
         printf("%s\n", obj->description);
      }
   }
   /* the function returns the number of objects in the list. */
   return count;
}
