#include "helperHeaderA3.h"

int main(int argc, char * argv[]){
	tweet * head = NULL;
	int input;
	int exit = 0;
	while(exit == 0){
		printf("1. Create a new tweet\n");
		printf("2. Display tweets\n");
		printf("3. Search a tweet (by keyword)\n");
		printf("4. Find how many words are \"stop words\"\n");
		printf("5. Delete the nth tweet\n");
		printf("6. Save tweets to a file\n");
		printf("7. Load tweets from a file\n");
		printf("8. Sort the given linked list on userid.\n");
		printf("9. Exit\n");
		printf("Enter your choice:\n");
		input = getNumInput();
		switch (input) {
			case 1:
				addNodeToList(&head, createTweet(head));
				break;
			case 2:
				displayTweets(head);
				break;
			case 3:
				searchTweetsByKeyword(head);
				break;
			case 4:
				countStopWords(head);
				break;
			case 5:
				deleteTweet(&head);
				break;
			case 6:
				saveTweetsToFile(head);
				break;
			case 7:
				loadTweetsFromFile(&head);
				break;
			case 8:
				sortID(&head);
				break;
			case 9:
				purge(head);
				exit = 1;
				break;
			default:
				printf("Invalid Input!\n");
		}
	}
	return 0;
}