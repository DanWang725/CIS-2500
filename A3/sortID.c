#include "helperHeaderA3.h"


void merge(tweet ** first, tweet * second){
	tweet * newHead = NULL;
	tweet * tempNode;
	while(*first != NULL && second != NULL){
		if((*first)->id > second ->id){
			tempNode = second->next;
			second->next = NULL;
			addNodeToList(&newHead, second);
			second = tempNode;
		} else {
			tempNode = (*first)->next;
			(*first)->next = NULL;
			addNodeToList(&newHead, *first);
			*first = tempNode;
		}
	}
	if(*first != NULL){
		appendTweetList(newHead, *first);
	}
	if(second != NULL){
		appendTweetList(newHead, second);
	}
	*first = newHead;
}

/**
 * conducts merge sort on the list
 * @param head - head of the current partition
 */
void mergeSort(tweet ** head){ //points to address, make that address that it i

	int len = tweetLen(*head);
	if(len > 1){ //if there is only 1 node in the list
		int middle = len / 2;
		tweet * middleNode = tweetAt(*head, middle - 1);
		tweet * nextNode = middleNode->next;
		middleNode->next = NULL;

		//recursively splitting up the list, calling the function on the lower half and the upper half, if it exists
		mergeSort(head);
		if(nextNode != NULL){
			mergeSort(&nextNode);
		}
		merge(head, nextNode); //merging the two lists
	}
}

/**
 * intermediate function that calls a merge sort on the list
 * @param head - the head of the function
 */
void sortID (tweet ** head){
	mergeSort(head);
	printf("Tweets Successfully Sorted!\n");
}