
# ***********************************************
# * PROJECT NAME: DUNGEON ADVENTURE             *
# * AUTHOR: STEFANO PERIS                       *
# * PRODUCT PUBLISHER: XENONLAB STUDIO (c) 2018 *
# * LANGUAGE: ANSI C                            *
# * COMPILER: GNU GCC COMPILER (MINGW INCLUDED) *
# ***********************************************
#
# ---------------------------------------------------------------
# - For error/bug reporting, e-mail: xenonlab.develop@gmail.com -
# ---------------------------------------------------------------
#
# -----------
# - LICENSE -
# -----------
#
# This content is free and open-source. You can modify and redistribute it under these terms.
#
# Dungeon Adventure is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Dungeon Adventure is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>.


# two special patterns that match the top and bottom of the input file;
# hence their code blocks are executed first and last, respectively.
BEGIN {
   count = 0;
   obj = "";
   if (pass == "c2")
   {
      print "\nOBJECT objs[] = {";
   }
}

# AWK scans through the input file (object.txt) line by line;
# each line is tested against each of these 'patterns'.
# Whenever a match is found, the code block that follows is executed.

# matches any line that starts with a dash (the 'object lines').
# The code initializes all attributes with an appropriate default.
/^- / {
   outputRecord(",");
   obj = $2;
   prop["description"] = "NULL";
   prop["tags"]        = "";
   prop["location"]    = "NULL";
   prop["destination"] = "NULL";
}

# following an object line, matches any line that starts with whitespace (the 'attribute lines').
# The code sets an attribute value, after having validated the attribute name.
obj && /^[ \t]+[a-z]/ {
   name = $1;
   $1 = "";
   if (name in prop)
   {
      prop[name] = $0;
   }
   else if (pass == "c2")
   {
      print "#error \"" FILENAME " line " NR ": unknown attribute '" name "'\"";
   }
}

# matches all lines that precede the first object line;
# an additional filter condition disperses the lines to the correct output files
# (#include lines to object.c, all others to object.h).
# The code simply outputs each line unchanged.
!obj && pass == (/^#include/ ? "c1" : "h") {
   print;
}

# two special patterns that match the top and bottom of the input file;
# hence their code blocks are executed first and last, respectively.
END {
   outputRecord("\n};");
   if (pass == "h")
   {
      print "\n#define endOfObjs\t(objs + " count ")";
   }
}

function outputRecord(separator)
{
   if (obj)
   {
      # the variable passage is defined at the time of the AWK call; see bash script "build.sh".
      if (pass == "h")
      {
         print "#define " obj "\t(objs + " count ")";
      }
      # the variable passage is defined at the time of the AWK call; see bash script "build.sh".
      else if (pass == "c1")
      {
         print "static const char *tags" count "[] = {" prop["tags"] ", NULL};";
      }
      # the variable passage is defined at the time of the AWK call; see bash script "build.sh".
      else if (pass == "c2")
      {
         print "\t{\t/* " count " = " obj " */";
         print "\t\t" prop["description"] ",";
         print "\t\ttags" count ",";
         print "\t\t" prop["location"] ",";
         print "\t\t" prop["destination"];
         print "\t}" separator;
         delete prop;
      }
      count++;
   }
}
