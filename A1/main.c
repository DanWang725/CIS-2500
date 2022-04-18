#include "wangDanielA1.h"

int main(int argc, char* argv[]) {
	char movieArr[NUMBER_MOVIES][MAX_STR];
	//functions to test: getMostCriticalReviews, getMostRecommendedMovies, predictMovie, enumerateMovie
	struct reviewStruct reviewers[NUMBER_REVIEWERS];
	char mostCriticalReviewers[NUMBER_REVIEWERS][MAX_STR];

	int numCrit;

	char mostRecommendedMovies[NUMBER_MOVIES][MAX_STR];
	int numRecomm;

	char moviePredict[MAX_STR];
	int rating;

	int charCounts[MAX_WORDS];
	int numChar;

	FILE* stuff = openFileForReading(argv[1]);
	FILE* stuff2 = openFileForReading(argv[2]);
	if (readMovies(stuff, movieArr) == 1) {
		for(int i = 0; i<NUMBER_MOVIES; i++){
			printf("Movie at index %d, %s\n", i, movieArr[i]);
		}
	}
	else {
		printf("error");
	}

	if (readReviews(stuff2, reviewers) == 1) {
		for(int i = 0; i<NUMBER_REVIEWERS; i++){
			printf("Reviewer at index %d, %s: %d %d %d\n", i, reviewers[i].reviewer,
			reviewers[i].feedback[0],
			reviewers[i].feedback[1],
			reviewers[i].feedback[2]);
		}
	}
	else {
		printf("error");
	}

	numCrit = getMostCriticalReviewers(reviewers, mostCriticalReviewers);
	printf("Critical Reviewers\n");
	for(int i = 0; i<numCrit; i++){
		printf("%s\n", mostCriticalReviewers[i]);
	}

	numRecomm = getMostRecommendedMovies(movieArr, reviewers, mostRecommendedMovies);
	printf("Recommended Movies\n");
	for(int i = 0; i<numRecomm; i++){
		printf("%s\n", mostRecommendedMovies[i]);
	}
	strcpy(moviePredict, "Star Wars");

	printf("Movie Score: %d\n", predictMovie(moviePredict));
	
	numChar = enumerateMovie("test t t", charCounts);
	printf("enumerateMovie test: \n");
	for(int i = 0; i<numChar; i++){
		printf("Word had %d char.\n", charCounts[i]);
	}
	return 0;
}