#include "wangDanielA1.h"

/** openFileForReading - takes in a file name and attempts to open file
* in: char* fileName
* out: File* file
*/
FILE* openFileForReading(char* fileName) {
	FILE* file = NULL;
	file = fopen(fileName, "r");
	return file;
}

/** readMovies - parses data from a text file and puts movie names into an array
* in: FILE* file, char movieNames[][] 
* out: 
*/
int readMovies(FILE* file, char movieNames[NUMBER_MOVIES][MAX_STR])
{
	char temp[MAX_STR];
	int count = 0;
	if (file == NULL) {
		return 0;
	}
	else {
		while (!feof(file)) {
			if (fgets(temp, MAX_STR, file) != NULL) {
				strcpy(movieNames[count], temp);
				movieNames[count][strlen(movieNames[count]) - 1] = '\0';
				//printf("Movie %d: %s", count, movieNames[count]);
				count++;
			}
			else {
				if (count != NUMBER_MOVIES) {
					return 0;
				}
			}
			
		}
	}
	return 1;
}

int readReviews(FILE* file, struct reviewStruct reviews[NUMBER_REVIEWERS])
{
	char temp[MAX_STR];
	int count = 0;
	if (file == NULL) {
		return 0;
	}
	else {
		while (!feof(file)) {

			if (fgets(temp, MAX_STR, file) != NULL) {

				temp[strlen(temp) - 1] = '\0';
				char* tok = strtok(temp, " ");

				strcpy(reviews[count].reviewer, tok);

				for (int i = 0; i < NUMBER_MOVIES; i++) {
					tok = strtok(NULL, " ");
					if (tok != NULL) {
						if (strcmp(tok, "y") == 0 || strcmp(tok, "Y") == 0) {
							reviews[count].feedback[i] = 1;
						}
						else if (strcmp(tok, "n") == 0 || strcmp(tok, "N") == 0) {
							reviews[count].feedback[i] = 0;
						}
					}
				}
				count++;
			}
			else {
				if (count != NUMBER_REVIEWERS) {
					return 0;
				}
			}
		}
	}
	/*for (int i = 0; i < NUMBER_REVIEWERS; i++) {
		printf("%s %d %d %d\n", reviews[i].reviewer, reviews[i].feedback[0], reviews[i].feedback[1], reviews[i].feedback[2]);
	}*/
	return 1;
}

/** getMostCriticalReviewers - gets a list of the reviewers with the most negative recommendations
* in: struct reviewStruct reviews[], char mostCriticalReviewers[][]
* out: the number of critical reviewers
*/
int getMostCriticalReviewers(struct reviewStruct reviews[NUMBER_REVIEWERS], char mostCriticalReviewers[NUMBER_REVIEWERS][MAX_STR])
{
	int maxNeg = 0;
	int numCrit = 0;
	long indexComb = 0;

	//this for loop generates a unique integer that represents the indexes of the most critical reviews

	//goes through the array of reviews backwards and calculates the number of negative reviews
	for (int i = NUMBER_REVIEWERS - 1; i >= 0; i--) {

		//since positive reviews are represented as 1, remove from a sum to get number of n reviews
		int tempMaxNeg = 3;
		for (int k = 0; k < NUMBER_MOVIES; k++) {
			tempMaxNeg -= reviews[i].feedback[k];
		}

		//comparing to see if current number of n's are higher than the max
		if (tempMaxNeg > maxNeg) {
			maxNeg = tempMaxNeg;
			indexComb = i;	//resetting the index integer
			numCrit = 1;	//reset the num of most critical
		}

		//if the number of n equal max
		else if (tempMaxNeg == maxNeg) {
			indexComb *= 10;	//shifts the previous digits (indexes) with mult by 10
			indexComb += i;		//setting the ones digit to the current index
			numCrit++;
		}
	}
	//printf("Unique digit: %ld\n", indexComb);

	//going through the unique integer
	for (int i = 0; i < numCrit; i++) {
		int index = (int)(indexComb % 10);	//getting the ones digit, which is an index
		strcpy(mostCriticalReviewers[i], reviews[index].reviewer);	//adding name to the array
		indexComb /= 10;	//going to the next index in the integer | 8432 -> 843
	}

	return numCrit;
}

int getMostRecommendedMovies(
	const char movieNames[NUMBER_MOVIES][MAX_STR],
	const struct reviewStruct reviews[NUMBER_REVIEWERS],
	char mostRecommendedMovies[NUMBER_MOVIES][MAX_STR])
{
	int numVotesMovie[NUMBER_MOVIES];
	int maxVotes = 0;
	int count = 0;

	for (int i = 0; i < NUMBER_MOVIES; i++) {
		numVotesMovie[i] = 0;
		for (int k = 0; k < NUMBER_REVIEWERS; k++) {
			numVotesMovie[i] += reviews[k].feedback[i];
		}
		if (maxVotes < numVotesMovie[i]) {
			maxVotes = numVotesMovie[i];
		}
	}

	for (int i = 0; i < NUMBER_MOVIES; i++) {
		if (numVotesMovie[i] == maxVotes) {
			strcpy(mostRecommendedMovies[count], movieNames[i]);
			count++;
		}
	}

	return count;
}

int predictMovie(const char movie[MAX_STR])
{
	char tempMovie[MAX_STR];
	strcpy(tempMovie, movie);
	char* tok = strtok(tempMovie, " ");
	int wordCount = 0;
	int charEven = 0;
	int movieScore = 0;
	
	bool isSameChar = true;
	int sameCharNum = strlen(tok);
	
	while (tok != NULL) {
		int tempLen = strlen(tok);
		wordCount++;
		
		if (tempLen % 2 == 0) {
			charEven++;
		}

		if (isSameChar && tempLen != sameCharNum) {
			isSameChar = false;
		}

		tok = strtok(NULL, " ");
	}

	if (wordCount < 2) {
		movieScore--;
	}

	if (wordCount == 1) {
		movieScore -= 2;
	}

	if (charEven > 1) {
		movieScore++;
	}

	if (isSameChar) {
		movieScore += 2;
	}

	if (movieScore >= 3) {
		movieScore = 2;
	}
	if (movieScore <= -3) {
		movieScore = -2;
	}

	return movieScore;
}

int enumerateMovie(const char movie[MAX_STR], int charCounts[MAX_WORDS])
{
	char tempMovie[MAX_STR];
	strcpy(tempMovie, movie);
	char* tok = strtok(tempMovie, " ");
	int count = 0;
	
	while (tok != NULL) {
		charCounts[count] = strlen(tok);
		count++;
		tok = strtok(NULL, " ");
	}
	return count;
}
