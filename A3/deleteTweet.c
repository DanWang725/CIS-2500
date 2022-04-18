//#include "headerA3.h"
#include "helperHeaderA3.h"
/**
 * deletes a tweet at the nth index. n is taken from user input at runtime
 * @param tweetList
 */
void deleteTweet(tweet ** tweetList){
	int lenOfList = tweetLen(*tweetList);
	int indexToDelete = 0;

	//user input and validity checking

	printf("Currently there are %d tweets.\n", lenOfList);
	if(lenOfList == 0){
		printf("There are no tweets to be deleted!\n");
		return;
	}
	printf("Which tweet do you wish to delete - enter a value between 1 and %d: ", lenOfList);
	while(indexToDelete <= 0 || indexToDelete > lenOfList){
		indexToDelete = getNumInput();
		if(indexToDelete <= 0 || indexToDelete > lenOfList){
			printf("Number entered is out of bounds!\n");
		}
	}

	if(indexToDelete == 1){ //if user deletes the head tweet
		tweet * newHead = (*tweetList)->next;
		indexToDelete = (*tweetList)->id;
		free((*tweetList));
		*tweetList = newHead;
	} else {
		tweet * nodeBefore = tweetAt(*tweetList, indexToDelete - 2);
		tweet * temp = nodeBefore -> next;
		if(temp -> next == NULL){
			nodeBefore -> next = NULL;
		} else {
			nodeBefore -> next = temp -> next;
		}
		indexToDelete = temp->id;
		free(temp);
	}
	printf("Tweet %d was deleted. There are now %d tweets remaining.\n", indexToDelete, tweetLen(*tweetList));
}