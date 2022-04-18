#include "../include/wangDanielA2.h"

int main(int argc, char * argv[]){
	printf("test\n");
	int count, punctCount;
	char static2d[MAX_WORDS][MAX_LENGTH];


	char * thisString = readFile(argv[1]);
	printf("Read File\n");
	printf("enter %d numbers:\n", strlen(thisString));
	char * stretchedString = stretchMe("Nice Cock Bro!!!");
	printf("Stretched: %s\n", stretchedString);

	printf("Now at splitme\n");
	count = splitMe(thisString, static2d);
	printf("Counted %d words:\n", count);
	for(int i = 0; i < count; i++){
		printf("%s\n", static2d[i]);
	}

	printf("%s\n", thisString);
	punctCount = shrinkMe(thisString);
	printf("Found %d punctuation\n", punctCount);
	printf("%s\n", thisString);


	if(isItAPalindrome(thisString)){
		printf("is a palindrome\n");
	} else {
		printf("not a palindrome\n");
	}
	printSuffixes(thisString, 1, "hehehehaw");
	free(thisString);
}