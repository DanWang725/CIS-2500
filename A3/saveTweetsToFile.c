#include "helperHeaderA3.h"
/**
 * saves the current list of tweets to an inputted
 * @param tweetList - list of tweets to save
 */
void saveTweetsToFile(tweet * tweetList){
	char * fileName = malloc(sizeof(char) * STR_MAX);
	printf("Enter the filename where you would like to store your tweets:");
	fgets(fileName, STR_MAX, stdin);
	trimNewline(fileName);
	FILE * file = fopen(fileName, "w");
	if(file == NULL){
		printf("Error?");
	} else {
		tweet * node = tweetList;
		while(node != NULL){ //going through the list and adding each tweet to the file
			char * final = toString(node);

			fprintf(file, "%s", final);
			node = node->next;
			if(node != NULL){
				fprintf(file, "\n");
			}
			free(final);
		}
		fclose(file);
		printf("Output Successful!\n");
	}
	free(fileName);
}