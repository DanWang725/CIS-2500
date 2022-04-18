#include "helperHeaderA3.h"
/**
 * loads the tweets from an inputted csv file
 * @param tweetList  - list to add tweets to
 */
void loadTweetsFromFile(tweet ** tweetList){
	char fileName[100];
	char * tempRead = malloc(sizeof(char) * STR_MAX);
	printf("Enter a filename to load from: ");
	fgets(fileName, STR_MAX, stdin);
	trimNewline(fileName);

	FILE * file = fopen(fileName, "r");

	if(file == NULL){
		printf("Error, file does not exist!\n");
	} else {
		while(fgets(tempRead, STR_MAX, file) != NULL){
			int stage = 0; //which stage of file reading it is
			tweet * newTweet = malloc(sizeof(tweet)); //creating a new tweet
			newTweet->next = NULL;
			newTweet->text[0] = '\0';
			trimNewline(tempRead);
			trimSpaces(tempRead);

			char * tok = strtok(tempRead, ",");
			while (tok != NULL && tok[0] != 13){ //reading the parts and adding to string
				//printf("%d ", tok[0]);
				
				switch (stage) { //populating the tweet struct with the token
					case 0:
						newTweet->id = atoi(tok);
						stage = 1;
						break;
					case 1:
						strcpy(newTweet->user,tok);
						stage = 2;
						break;
					case 2:
						if(strlen(newTweet->text) != 0){
							strcat(newTweet->text, ",");
						}
						strcat(newTweet->text, tok);

						break;
					default:
						printf("This shouldn't happen!\n");
						break;
				}
				tok = strtok(NULL, ",");
			}
			addNodeToList(tweetList, newTweet);
		}
		fclose(file);
		printf("Tweets Imported!\n");
	}
	free(tempRead);

}