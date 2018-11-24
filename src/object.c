/* object.c

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


/*
tag lists do not have a fixed length;
use NULL to indicate the nounIsInTags function (defined below) in which the list ends.
*/
static const char *tags0[] = {"field", NULL};
static const char *tags1[] = {"cave", NULL};
static const char *tags2[] = {"silver", "coin", "silver coin", NULL};
static const char *tags3[] = {"gold", "coin", "gold coin", NULL};
static const char *tags4[] = {"guard", "burly guard", NULL};
static const char *tags5[] = {"yourself", NULL};
static const char *tags6[] = {"east", "entrance", NULL};
static const char *tags7[] = {"west", "out", NULL};
static const char *tags8[] = {"west", "north", "south", "forest", NULL};
static const char *tags9[] = {"east", "north", "south", "rock", NULL};

OBJECT objs[] = {
   {"an open field"              , tags0, NULL , NULL  },
   {"a little cave"              , tags1, NULL , NULL  },
   {"a silver coin"              , tags2, field, NULL  },
   {"a gold coin"                , tags3, cave , NULL  },
   {"a burly guard"              , tags4, field, NULL  },
   {"yourself"                   , tags5, field, NULL  },
   {"a cave entrance to the east", tags6, field, cave  },
   {"a way out to the west"      , tags7, cave , field },
   /*
   I added steps for any "walls" surrounding the places; otherwise "go west"
   in the field would return "You do not see any west here".
   You could represent a wall with a passage with a destination equal to the point of origin,
   but which results in a misleading answer to "go to the west" ("OK" followed by a description of the current position).
   Instead I simply made the destination NULL, effectively making the transition a dummy object not passing through.
   The answer of the game will still be questionable ("you can not get any closer than this")
   but this will be solved later.
   */
   {"dense forest all around"    , tags8, field, NULL  },
   {"solid rock all around"      , tags9, cave , NULL  }
};
