/* main.c

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


/* a old-style text adventure needs no fancy libraries; standard library is sufficient, and is widely available. */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* uses the functions defined in the separate modules of the program. */
#include "../include/location.h"
#include "../include/inventory.h"


/* string buffer to collect keyboard input. */
static char input[100];

static int getInput()
{
   /* prompt */
   printf("\n\n\n--> ");
   /*
   standard function fgets gets input from the keyboard.
   If the player presses end-of-file, function getInput will return false and the program will end.
   */
   return fgets(input, sizeof(input), stdin) != NULL;
}

static int parseAndExecute()
{
   /* standard function strtok is used to build a very basic verb-noun parser in just two lines of code. */
   char *verb = strtok(input, " \n");
   /*
   C compiler may give a warning regarding the unused variable ‘noun’ on this line.
   Please ignore this message; the issue will be gone in the next commit.
   */
   char *noun = strtok(NULL, " \n");
   /* nothing to do if the player enters nothing (or just spaces). */
   if (verb != NULL)
   {
      /*
      using standard function strcmp to match keyboard input with known verbs (quit, look and go).
      For now, this is a case-sensitive match, so the player should be careful not to hold shift or press caps lock.
      */
      if (strcmp(verb, "quit") == 0)
      {
         /* in C, false is represented by zero. This return will cause the main loop to end. */
         return 0;
      }
      else if (strcmp(verb, "look") == 0)
      {
         /* call the new functions. */
         executeLook(noun);
      }
      else if (strcmp(verb, "go") == 0)
      {
         /* call the new functions. */
         executeGo(noun);
      }
      else if (strcmp(verb, "get") == 0)
      {
         executeGet(noun);
      }
      else if (strcmp(verb, "drop") == 0)
      {
         executeDrop(noun);
      }
      else if (strcmp(verb, "give") == 0)
      {
         executeGive(noun);
      }
      else if (strcmp(verb, "ask") == 0)
      {
         executeAsk(noun);
      }
      else if (strcmp(verb, "inventory") == 0)
      {
         executeInventory();
      }
      else
      {
         /* a typical printf-style format string, with %s as placeholder for the additional parameter verb. */
         printf("I don't know how to '%s'.\n", verb);
      }
   }
   /* in C, true is represented by any non-zero number (typically 1). */
   return 1;
}

/* function main is the starting point of any C program. */
int main()
{
   printf("\n");
   printf("\t\t\t********************************\n");
   printf("\t\t\t* Welcome to Dungeon Adventure *\n");
   printf("\t\t\t********************************\n\n");
   printf("\t\t\t     Stefano Peris (c) 2018\n");
   printf("\n\n\n\n\n\n\n\n");
   /* at the start of the game, describe the player's surroundings, as if the player entered the command 'look around'. */
   executeLook("around");
   /* output text to the screen; the escape sequence \n represents a newline. */
   /* printf("It's very dark in here.\n"); */

   /*
   this is the main loop; it alternately calls getInput and parseAndExecute until either one of them returns false
   (represented by zero in C).
   */
   while (getInput() && parseAndExecute());
   printf("\nBye!\n");
   /* function main returns a zero exit code to successfully complete the program. */
   return 0;
}
