#include "helperHeaderA3.h"
void countStopWords(tweet * tweetList){
	char * stopWords[] = {"a","an","and","are","as","at","be","by","for","from","has","he","in","is","it","its",
						"of","on","that","the","to","was","were","will","with"};
	int numWords = 25;
	int totalStopWord = 0;
	int numTweet = tweetLen(tweetList);
	tweet * node = tweetList;
	while(node != NULL){
		for(int i = 0; i<numWords; i++){
			totalStopWord += numStopWords(node->text, stopWords[i]); //counting the specific stop word occurrences in the tweet
		}
		//printf("%s: %d\n", node->text, totalStopWord);
		node = node->next;
	}
	printf("Across %d tweets, %d stop words were found.\n", numTweet, totalStopWord);
}