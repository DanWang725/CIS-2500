//#include "headerA3.h"
#include <time.h>
#include "helperHeaderA3.h"
/**
 * creates a tweet with an id that is pairwise disjoint with the other ids in the linked list
 * @param tweetList
 * @return
 */
tweet * createTweet( tweet * tweetList){
	time_t t;
	int sumId = 0;
	srand((unsigned )time(&t));
	tweet * newTweet = malloc(sizeof(tweet));

	//user input
	printf("Enter a username: ");
	while(1){ //validity check for user name length
		char veryTemp[STR_MAX_USER+1];
		fgets(veryTemp, STR_MAX_USER+1, stdin);

		if(trimNewline(veryTemp) == 1 && strlen(veryTemp) < STR_MAX_USER){ //handling the case when len == 51
			if(strlen(veryTemp) > 0) {
				strcpy(newTweet->user, veryTemp);
				break;
			} else {
				printf("No text entered!\n");
			}
		} else {
			fgets(newTweet->user, STR_MAX_USER, stdin);
			printf("User's name is too long! Enter something at most %d characters!\n", STR_MAX_USER-1);
		}
	}

	printf("Enter the user's tweet: ");
	while(1){ //validity check for tweet length
		char veryTemp[STR_MAX_TWEET+1];
		fgets(veryTemp, STR_MAX_TWEET+1, stdin);

		if(trimNewline(veryTemp) == 1 && strlen(veryTemp) < STR_MAX_TWEET){
			if(strlen(veryTemp) > 0) {
				strcpy(newTweet->text, veryTemp);
				break;
			} else {
				printf("No text entered!\n");
			}
		} else {
			fgets(newTweet->text, STR_MAX_TWEET, stdin);
			printf("Tweet is too long! Enter something at most %d characters!\n", STR_MAX_TWEET-1);
		}
	}

	//generating the id of the tweet
	for(int i = 0; i< strlen(newTweet ->user); i++){
		sumId += newTweet->user[i];
	}
	sumId += (int)strlen(newTweet->text);
	while(searchTweetID(tweetList, sumId) != NULL){ //adding random numbers to id if there is an id already in the list
		sumId += rand() % 999;
	}

	newTweet->id = sumId;
	newTweet->next = NULL;
	printf("Your computer-generated userid is %d.\n", sumId);
	return newTweet;
}