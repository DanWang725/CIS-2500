#include "helperHeaderA3.h"
/**
 * searchTweetsByKeyword - finds tweets that contain the string that is inputted at runtime
 * @param tweetList - the list to search
 * @return - status of search
 */
int searchTweetsByKeyword(tweet * tweetList){
	tweet * node = tweetList;
	int numResults = 0;
	char * input = (char *)calloc(STR_MAX, sizeof(char));
	char * inputLower;
	printf("Enter a keyword to search: ");
	fgets(input, STR_MAX, stdin);
	trimNewline(input);
	inputLower = toLowerStr(input);

	while(node != NULL){
		char * tempLower = toLowerStr(node->text);
		if(strstr(tempLower, inputLower) != NULL){
			printf("Match found for '%s': %s wrote: \"%s\"\n", input, node->user, node->text);
			numResults ++;
		}
		free(tempLower);
		node = node->next;
	}
	if(numResults == 0){
		printf("There were no tweets found containing the keyword '%s'\n", input);
	}
	free(input);
	free(inputLower);

	return (numResults == 0) ? 0 : 1;
}