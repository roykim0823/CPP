#include <stdio.h>
#define ALPHABET_SIZE 26

// The best approach to solve this problem is to store each letter's encoding in an array 
// that is indexed by letter number (assuming there are 26 upper case letters).
// So, for example, "A" is letter 0, so the array must hold, in position 0, the representation of A. 
// A can be graphically depicted like this:
/*
                  
				  X
				X   X
               X     X
			  X       X
			 X         X
			XXXXXXXXXXXXX
		   X             X
		  X               X
		 X                 X
*/

//We will store a multi-line character string with each letter's representationy.

char *letters[ALPHABET_SIZE] = {
"\
         X              \n\
       X   X            \n\
      X     X           \n\
     X       X          \n\
    X         X         \n\
   XXXXXXXXXXXXX        \n\
  X             X       \n\
 X               X      \n\
X                 X     \n\
",
"\
XXXXXXXXXXXX \n\
X          X \n\
X          X \n\
X          X \n\
XXXXXXXXXXXX \n\
X            \n\
XXXXXXXXXXXX \n\
X          X \n\
X          X \n\
X          X \n\
XXXXXXXXXXXX \n\
",
"\
XXXXXXXXXXXX \n\
X            \n\
X            \n\
X            \n\
X            \n\
X            \n\
X            \n\
XXXXXXXXXXXX \n\
",
"\
XXXXXXXXXXXXX \n\
  X         X \n\
  X         X \n\
  X         X \n\
  X         X \n\
  X         X \n\
  X         X \n\
  X         X \n\
  X         X \n\
XXXXXXXXXXXXX \n\
",
"\
XXXXXXXXXXXX \n\
X            \n\
X            \n\
XXXXXXXXXXXX \n\
X            \n\
X            \n\
XXXXXXXXXXXX \n\
",
"\
XXXXXXXXXXXX \n\
X            \n\
X            \n\
XXXXXXX      \n\
X            \n\
X            \n\
X            \n\
",
"\
XXXXXXXXXXXX \n\
X            \n\
X            \n\
X    XXXXXX  \n\
X         X  \n\
X         X  \n\
XXXXXXXXXXX  \n\
",
"\
XX       XX \n\
XX       XX \n\
XX       XX \n\
XXXXXXXXXXX \n\
XXXXXXXXXXX \n\
XX       XX \n\
XX       XX \n\
XX       XX \n\
XX       XX \n\
",
"\
XXXXXXXXXXX \n\
XXXXXXXXXXX \n\
    XX      \n\
    XX      \n\
    XX      \n\
    XX      \n\
    XX      \n\
XXXXXXXXXXX \n\
XXXXXXXXXXX \n\
",
"\
XXXXXXXXXX \n\
XXXXXXXXXX \n\
        XX \n\
        XX \n\
 XX    XX  \n\
 XX   XX   \n\
 XXXXXX    \n\
",
"\
X    X \n\
X   X  \n\
X  X   \n\
X X    \n\
XX     \n\
X X    \n\
X  X   \n\
X   X  \n\
",
"\
X          \n\
X          \n\
X          \n\
X          \n\
X          \n\
X          \n\
XXXXXXXXXX \n\
",
"\
XX      XX \n\
X X    X X \n\
X  X  X  X \n\
X   XX   X \n\
X        X \n\
X        X \n\
X        X \n\
",
"\
XX      X \n\
X X     X \n\
X  X    X \n\
X   X   X \n\
X    X  X \n\
X     X X \n\
X      XX \n\
",
"\
XXXXXXXXXX \n\
X        X \n\
X        X \n\
X        X \n\
X        X \n\
X        X \n\
XXXXXXXXXX \n\
",
"\
XXXXXXXXXX \n\
X        X \n\
X        X \n\
XXXXXXXXXX \n\
X          \n\
X          \n\
X          \n\
",
"\
XXXXXXXXXX \n\
X        X \n\
X        X \n\
X        X \n\
X    X   X \n\
X     X  X \n\
XXXXXXXXXX \n\
        X  \n\
         X \n\
",
"\
XXXXXXXXXX \n\
X        X \n\
X        X \n\
XXXXXXXXXX \n\
XXXXX      \n\
X    X     \n\
X     X    \n\
X      X   \n\
X       X  \n\
",
"\
XXXXXXXXXX \n\
X          \n\
X          \n\
XXXXXXXXXX \n\
         X \n\
         X \n\
XXXXXXXXXX \n\
",
"\
XXXXXXXXXX \n\
    X      \n\
    X      \n\
    X      \n\
    X      \n\
    X      \n\
",
"\
X        X \n\
X        X \n\
X        X \n\
X        X \n\
X        X \n\
XXXXXXXXXX \n\
",
"\
X       X \n\
 X     X  \n\
  X   X   \n\
   X X    \n\
    X     \n\
",
"\
X       XX       X \n\
 X     X  X     X  \n\
  X   X    X   X   \n\
   X X      X X    \n\
    X        X     \n\
",
"\
X     X \n\
 X   X  \n\
  X X   \n\
   X    \n\
  X X   \n\
 X   X  \n\
X     X \n\
",
"\
X      X \n\
 X    X  \n\
  X  X   \n\
   XX    \n\
   XX    \n\
   XX    \n\
   XX    \n\
",
"\
XXXXXXXXX \n\
       X  \n\
     X    \n\
   X      \n\
 X        \n\
XXXXXXXXX \n\
"
};

char *banner(char c) {
	return letters[c-'A'];
}

int main() {
	/* Print the alphabet! */
	int i;
	for (i = 0; i < ALPHABET_SIZE; i++)
		printf("%s\n", banner('A'+i));
	return 0;
}
