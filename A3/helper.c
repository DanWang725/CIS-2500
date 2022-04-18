//#include "headerA3.h"
#include "helperHeaderA3.h"

/**
 * Finds the tweet at the given index
 * @param tweetList, index
 * @return tweet
 */
tweet * tweetAt(tweet * tweetList, int index){
	tweet* node = tweetList;

	for(unsigned int i = 0; i < index; i++){
		if(node == NULL){
			break;
		}
		node = node->next;
	}

	return node;
}

/**
 * searchTweetID - searches the given list for the specified id
 * @param tweetList - the list to search
 * @param id - must be an integer
 * @return a pointer to the tweet with that ID, returns NULL if not found
 */
tweet * searchTweetID(tweet * tweetList, int id){
	tweet * node = tweetList;
	while(node != NULL){
		if(node->id == id){
			return node;
		}
		node = node->next;
	}
	return NULL;
}

/**
 * tweetLen - gets the length of a tweet list
 * @param tweetList
 * @return
 */
int tweetLen(tweet * tweetList){
	int n = 0;
	while(tweetList != NULL){
		n++;
		tweetList = tweetList->next;
	}
	return n;
}
/**
 * adds a node to the end of the linked list
 * REQUIRES: a non-zero length linked list
 * @param tweetList the list to add to
 * @param tweetListAppend the tweet to add to the end of the list
 */
void appendTweetList(tweet *tweetList, tweet *tweetListAppend) {
	tweet * endTweet = tweetAt(tweetList, tweetLen(tweetList) - 1);
	endTweet->next = tweetListAppend;
}

/**
 * adds the node to the end of the given tweet list
 * @param tweetList - the list to add
 * @param node - the tweet to insert
 */
void addNodeToList(tweet**tweetList,tweet * node){
	if(*tweetList == NULL){
		*tweetList = node;
	} else {
		tweet *nodeBeforeEnd = tweetAt(*tweetList, tweetLen(*tweetList) - 1);
		nodeBeforeEnd->next = node;
	}
}
/**
 * removes the newline from the end of a line, if it exists
 * @param word the word to trim
 */
int trimNewline(char * word){
	if(word[strlen(word) - 1] == '\n'){
		word[strlen(word) - 1] = '\0';
		return 1;
	}
	return 0;
}

/**
 * trims all of the spaces at the end of word
 * @param word
 */
void trimSpaces(char * word){
	if(word[strlen(word) - 1] == ' '){
		int pos = strlen(word) - 2;
		while(word[pos] == ' ' && pos > 0){
			pos--;
		}
		pos++;
		word[pos] = '\0';
	}
}
/**
 * converts the given tweet into a comma separated string that is compatible with .csv files
 * @param node - node to convert to string
 * @return a dynamically allocated char *
 */
char * toString(const tweet * node){
	int totalLength = (ceil(log10((double)(node->id)))) + strlen(node->user) + strlen(node->text) + 5;
	if(totalLength >= STR_MAX){
		printf("Minor Error - String read too long. Please report this issue.\n");
	}
	char * text = malloc(sizeof(char) * totalLength);
	text[0] = '\0';
	//printf("Pointer before: %p\n", text);
	sprintf(text, "%d", node->id);
	//printf("Pointer After: %p\n", text);
	strcat(text, ",");
	strcat(text, node->user);
	strcat(text, ",");
	strcat(text, node->text);
	strcat(text, ",");
	return text;
};

/**
 * turns all of the char into lowercase within the given string
 * @param str - string to process
 * @return - dynamically allocated string
 */
char * toLowerStr(const char * str){
	char * newStr;

	newStr = malloc(sizeof(char) * (strlen(str) + 1));
	for (int i = 0; i < strlen(str); i++) {
		newStr[i] = (char)tolower(str[i]);
	}
	newStr[strlen(str)] = '\0';

	return newStr;
}

/**
 * counts the number of a given word that exists within a sentence
 * @param str the entire string to analyze
 * @param word the word to look for
 * @return the count of the word in the sentence
 */
int numStopWords(char * str, char * word){
	char * strLower = toLowerStr(str);
	char * tempStr = strLower;
	int wordLen = (int)strlen(word);
	int count = 0;
	char * ptr;
	while((ptr = strstr(tempStr, word)) != NULL){
		int flag = 0;
		if(strcmp(ptr, strLower) != 0){
			ptr--;
			if(ptr[0] == ' ')
			{
				flag++;
			}
			ptr++;
		} else {
			flag++;
		}
		if(wordLen < strlen(ptr)){
			if(ptr[wordLen] == ' '){
				flag++;
			}
		} else {
			flag ++;
		}
		count += (flag == 2)? 1:0;
		if(strlen(ptr) <= 1){
			break;
		}
		tempStr = ++ptr;
	}
	/*if(count != 0){
		printf("The stopword %s was found %d times in %s\n", word, count, str);
	}*/
	free(strLower);
	return count;
}

/**
 * frees all elements in the given list
 * @param tweetList
 */
void purge(tweet * tweetList){
	tweet * temp;
	while(tweetList != NULL){
		temp = tweetList->next;
		free(tweetList);
		tweetList = temp;
	}
}

/**
 * getNumInput - gets user input for an integer, handles incorrect input until valid input is entered
 * @return - dynamically allocated string
 */
int getNumInput(){
	int input = 0;
	char * temp = calloc(STR_MAX, sizeof(char));
	while(input == 0){
		fgets(temp, STR_MAX, stdin);
		trimNewline(temp);
		input = atoi(temp);
		if(input == 0){
			if(temp[0] == '0'){
				break;
			}
			printf("Invalid Input! Enter an integer.\n");
		}
	}
	free(temp);
	return input;
}