CC=gcc
CCFLAGS= -Wall -std=c99
TweetManager: createTweet.o displayTweets.o searchTweetsByKeyword.o countStopWords.o deleteTweet.o saveTweetsToFile.o loadTweetsFromFile.o sortID.o helper.o main.o
	$(CC) createTweet.o displayTweets.o searchTweetsByKeyword.o countStopWords.o deleteTweet.o saveTweetsToFile.o loadTweetsFromFile.o sortID.o helper.o -lm main.o -o TweetManager
createTweet.o: createTweet.c headerA3.h helperHeaderA3.h
	$(CC) $(CCFLAGS) -c createTweet.c
displayTweets.o: displayTweets.c headerA3.h helperHeaderA3.h
	$(CC) $(CCFLAGS) -c displayTweets.c
searchTweetsByKeyword.o: searchTweetsByKeyword.c headerA3.h helperHeaderA3.h
	$(CC) $(CCFLAGS) -c searchTweetsByKeyword.c
countStopWords.o: countStopWords.c headerA3.h helperHeaderA3.h
	$(CC) $(CCFLAGS) -c countStopWords.c
deleteTweet.o: deleteTweet.c headerA3.h helperHeaderA3.h
	$(CC) $(CCFLAGS) -c deleteTweet.c
saveTweetsToFile.o: saveTweetsToFile.c headerA3.h helperHeaderA3.h
	$(CC) $(CCFLAGS) -c saveTweetsToFile.c
loadTweetsFromFile.o: loadTweetsFromFile.c headerA3.h helperHeaderA3.h
	$(CC) $(CCFLAGS) -c loadTweetsFromFile.c
sortID.o: sortID.c headerA3.h helperHeaderA3.h
	$(CC) $(CCFLAGS) -c sortID.c
helper.o: helper.c headerA3.h helperHeaderA3.h
	$(CC) $(CCFLAGS) -c helper.c
main.o: main.c headerA3.h helperHeaderA3.h
	$(CC) $(CCFLAGS) -c main.c
clean:
	rm *.o TweetManager