/*
A good way to organize such rules is to use a 2-dimensional array that for each letter indexes an array with the hyphenation rules. In my implementation, I only included the hyphenation rules for the letter 'c'.
A function to return a suffix hyphenation must grab the array of rules according to the last letter of the word, and then iterate through that array until the suffix matches with any rule. To attempt the match,
we will define an auxiliary function, suffix_match(), that grabs a rule, such as "h-nic", and matches it right-to-left with the end of the word, skipping the '-' hyphenation character. When a match is found, we stop looking for further matches.
Note that my implementation could be more efficient. strlen() is called too many times, it would be a good optimization to:
	a) store the suffix rules reversed, so that position 0 of a suffix is the last letter;
	b) pass a pointer to the end of the word in the call to suffix_match(), because the caller already knows the string length

The rules for letter 'c' were directly hardcoded in the program. In a real implementation, we could read them from a file for each letter. A good structure would be an input file with the letter, the number of rules for that
letter, and then the rules. For example, for letter c, we have 24 rules, so the input would look like:

c 24
et-ic
al-is-tic
...
i-ac

The array of rules is declared as an array of char **, so that we can dynamically allocate only the required space, no more, no less, for each set of rules for each letter. This ensures that no space is wasted, and it
gets along with the input format I mentioned above. Every array of rules is terminated by a null pointer, thus, we can easily know when to stop attempting a match.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ALPHABET_SIZE 26
#define C_RULES_SIZE ((int) (sizeof(c_rules)/sizeof(c_rules[0])))

char *c_rules[] = {
	"et-ic",
	"al-is-tic",
	"s-tic",
	"p-tic",
	"-lyt-ic",
	"ot-ic",
	"an-tic",
	"n-tic",
	"c-tic",
	"at-ic",
	"h-nic",
	"n-ic",
	"m-ic",
	"l-lic",
	"b-lic",
	"-clic",
	"l-ic",
	"h-ic",
	"f-ic",
	"d-ic",
	"-bic",
	"a-i",
	"-mac",
	"i-ac"
};

char **rules[ALPHABET_SIZE] = { NULL };
char *hyphenizer(char *word);

int main(int argc, char *argv[]) {
	/* Fill the rules array with known rules */
	int i;
	char *str;
	rules['c'-'a'] = (char **) malloc(sizeof(char *)*(C_RULES_SIZE+1));
	for (i = 0; i < C_RULES_SIZE; i++)
		rules['c'-'a'][i] = c_rules[i];
	rules['c'-'a'][i] = NULL; /* signalizes end of rules */
	
	/* Print hyphenizers for the words in argv */
	for (i = 1; i < argc; i++)
		printf("%s: %s\n", argv[i], ((str = hyphenizer(argv[i])) == NULL ? "[no match]" : str));
	return 0;
}

int suffix_match(char *, char *);

char *hyphenizer(char *word) {
	char **p;
	
	for (p = rules[word[strlen(word)-1]-'a']; *p; p++)
		if (suffix_match(word, *p))
			return *p;
	
	return NULL;	
}

int suffix_match(char *word, char *suffix) {
	int i, j;	
	for (i = strlen(word)-1, j = strlen(suffix)-1; word[i] == suffix[j]; i--, j -= 1+(suffix[j-1] == '-'))
		if (!i || j < 0)
			break;
	return j < 0;
}
