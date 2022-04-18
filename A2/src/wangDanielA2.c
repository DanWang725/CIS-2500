#include "../include/wangDanielA2.h"
/** Helper file,
 * dynamically allocates a new string and copies the given string
 * @param str string to copy
 * @return a pointer to the new string
 */
char* copyStr(char * str){
	char * newStr = (char *)malloc(sizeof(char) * (strlen(str) + 1));
	strcpy(newStr, str);
	return newStr;
}

/**
 * readFile - reads the content of a file
 * @param filename - name of file to open, format is a char array
 * @return char pointer, initialized in heap
 */
char* readFile(char* filename){
	int length;
	int maxSentence = MAX_WORDS * MAX_LENGTH;
	char * fileStr;
	char * tempStr = (char *)malloc(sizeof(char) * maxSentence);

	FILE* file = NULL;
	//opening file and stopping execution if no file is read
	file = fopen(filename, "r");
	if(file == NULL){
		return NULL;
	}
	//reading how many characters is stored in the file
	fseek(file, 0, SEEK_END);
	length = ftell(file);
	fseek(file, 0, SEEK_SET);

	//allocating a char pointer the length of the file
	fileStr = (char *)malloc(sizeof(char) * length);
	fileStr[0] = '\0';

	//reading all input from the file and strcat to the fileStr
	while(fgets(tempStr, maxSentence, file) != NULL){
		strcat(fileStr, tempStr);
	}
	fclose(file);	//closing file
	free(tempStr);
	return fileStr;
}

/**
 * stretches characters in a string based on user input
 * @param aStringToStretch - string as char array
 * @return char pointer, initialized in heap
 */
char* stretchMe(char* aStringToStretch)
{
	int n = (int)strlen(aStringToStretch);
	int newStrLength = 1;
	int curIndex = 0;
	char * newStr = (char *)malloc(sizeof(char)*1); //initialize size of 1 to hold the '\0' at the end

	for(int i = 0; i < n; i++){
		int mult = 0;
		while(mult <= 0){
			scanf("%d", &mult);
		}

		newStrLength += mult;
		newStr = (char *)realloc(newStr, sizeof(char)*newStrLength);

		for(int j = curIndex + mult; curIndex < j; curIndex++){
			newStr[curIndex] = aStringToStretch[i];
		}
	}
	newStr[curIndex] = '\0'; //adding null char to the end of the generated string
	return newStr;
}
/**
 * splitMe - splits a string into words, based on spaces between each
 * @param aStringToSplit - a string as a char array to split. Will not be changed.
 * @param static2D - a statically initialized 2d array to store each word
 * @return number of words
 */
int splitMe(char* aStringToSplit, char static2D[MAX_WORDS][MAX_LENGTH])
{
	int count = 0;
	char * tempString = copyStr(aStringToSplit);
	char * tok = strtok(tempString, " \n");

	while(tok != NULL) {
		//printf("DEBUG splitMe: %s\n", tok); //debug printf
		strcpy(static2D[count], tok);
		tok = strtok(NULL, " \n");
		count++;
		if(count >= 50){
			break;
		}
	}
	free(tempString);
	return count;
}

/**
 * shrinkMe - removes the punctuation {. : ; ? !} from a string
 * @param aStringToShrink - the string to be edited
 * @return number of punctuation removed
 */
int shrinkMe(char* aStringToShrink)
{
	int count = 0;
	char * punct;
	char * tempStr = (char *)malloc(sizeof(char) * (strlen(aStringToShrink) + 1));
	punct = copyStr(".;:?!");
	tempStr[0] = '\0';

	//counting the number of punctuation in the string
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < strlen(aStringToShrink); j++){
			count += (aStringToShrink[j] == punct[i]);
		}
	}

	//removing punctuation
	char *tok = strtok(aStringToShrink, punct);

	while (tok != NULL) {
		strcat(tempStr, tok);
		//printf("DEBUG shrinkMe: %s added\n", tok);
		tok = strtok(NULL, punct);
	}
	strcpy(aStringToShrink, tempStr);
	free(tempStr);
	free(punct);
	return count;
}

/**
 * isItAPalindrome - finds if each letter is a palindrone, ignoring punctuation.
 * @param aString - string to run test on. Will not be changed
 * @return boolean - if string meets conditions
 */
bool isItAPalindrome(char* aString)
{
	//initializing the var
	char * tempStr = copyStr(aString);
	(void)shrinkMe(tempStr);
	bool isPalindrome = true;
	char * tok = strtok(tempStr, " ,\n"); //splitting the string by spaces and newlines

	//while loop for each word
	while(tok != NULL){
		int leftPointer = 0;	//two pointers that compare each letter from front and back
		int rightPointer = strlen(tok) - 1;
		//printf("DEBUG: word we are looking at: %s\n", tok);

		while(leftPointer <= rightPointer){
			//printf("DEBUG: left pointer: %d. right pointer: %d\n", leftPointer, rightPointer);
			//if characters are not the same, set the bool to false and break the loop
			if(tolower(tok[leftPointer]) != tolower(tok[rightPointer])){
				isPalindrome = false;
				printf("DEBUG: %s is not a palindrome.\n", tok);
				break;
			}
			//moving the pointers to the next char
			leftPointer++;
			rightPointer--;
		}
		//if we detected 1 word that is not a palindrome, no point in checking anymore
		if(!isPalindrome){
			break;
		}
		tok = strtok(NULL, " \n");
	}
	free(tempStr);
	return isPalindrome;
}

/**
 * finds given word in position, and prints n words, the first char is one letter of chosen word
 * @param aString - the string to input
 * @param whichWord - the word at this position to split and add to suffix
 * @param desiredSuffix - the string to write after the char
 * @print n words, where n is the length of the chosen word
 */
void printSuffixes(char* aString, int whichWord, char* desiredSuffix)
{
	char * tempStr = copyStr(aString);
	(void)shrinkMe(tempStr);
	char * tok = strtok(tempStr, " \n");
	for(int i = 1; i < whichWord; i++){ //going to the word at the specified position
		if(tok == NULL){ //if the sentence has less words than required, print error
			printf("Error! Word index out of bounds!");
			return;
		}
		tok = strtok(NULL, " \n");
	}
	for(int i = 0; i < strlen(tok); i++){
		printf("%c%s\n", tok[i], desiredSuffix);
	}
	free(tempStr);
}
