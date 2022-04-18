#include "headerA3.h"
#include <math.h>
#include <string.h>
#include <ctype.h>
#define STR_MAX_USER 51
#define STR_MAX_TWEET 141
#define STR_MAX 200

tweet * tweetAt(tweet * tweetList, int index);
tweet * searchTweetID(tweet * tweetList, int id);
int tweetLen(tweet * tweetList);
void appendTweetList(tweet * tweetList, tweet * tweetListAppend);
int trimNewline(char * word);
void trimSpaces(char * word);
char * toString(const tweet * node);
char * toLowerStr(const char * str);
int numStopWords(char * str, char * word);
void purge(tweet * tweetList);
int getNumInput();