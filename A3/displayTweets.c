#include "helperHeaderA3.h"
/**
 * prints out all of the tweets in the linked list
 * @param tweetList - the list to print
 */
void displayTweets(tweet * tweetList){
	tweet * node = tweetList;
	while(node != NULL){ //iterating through the list and printing out each tweet
		printf("%d: Created by %s: %s\n", node -> id, node -> user, node -> text);
		node = node->next;
	}
}