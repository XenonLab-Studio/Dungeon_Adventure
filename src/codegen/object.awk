
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


BEGIN {
   count = 0;
   obj = "";
   if (pass == "c2")
   {
      print "\nOBJECT objs[] = {";
   }
}

/^- / {
   outputRecord(",");
   obj = $2;
   prop["description"] = "NULL";
   prop["tags"]        = "";
   prop["location"]    = "NULL";
   prop["destination"] = "NULL";
}

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

!obj && pass == (/^#include/ ? "c1" : "h") {
   print;
}

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
      if (pass == "h")
      {
         print "#define " obj "\t(objs + " count ")";
      }
      else if (pass == "c1")
      {
         print "static const char *tags" count "[] = {" prop["tags"] ", NULL};";
      }
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
