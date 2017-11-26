#include <iostream>
#include <cstring>
#include "utilities.h"

using namespace std;

// An object to store the star and planet variables of a given probe
struct StarPlan{ 
	int stars;
	int planets;
};

int runOneRound(const char words[][MAXWORDLEN + 1], int nWords, int wordNum);
bool findWord(const char probe[], const char words[][MAXWORDLEN + 1], int nWords);
StarPlan findStarsAndPlanets(const char probe[], const char target[]);

bool badChar(const char probe[]);
int getMin(int arr[], int len);
int getMax(int arr[], int len);
double getAvg(int arr[], int len);

int main(){
	const int MAXWORDS = 9000;
	const int MAXWORDLEN = 6;
	char wordList[MAXWORDS][MAXWORDLEN + 1];
	
	int wordNum;
	int numWords = 0;
	const char WORDFILENAME[] = "words.txt";
	
	// Fills the wordList array with words from the utility files
	numWords = getWords(wordList, MAXWORDS, WORDFILENAME);  
	
	// Checks that the array has a positive number of elements
	if ( numWords == 0){
		cout << "No words were loaded, so I can't play the game." << endl;
		return 1;
	}

	//Asks the user how many rounds to play
	cout << "How many rounds do you want to play? ";
	int numRounds;
	cin >> numRounds;
	cin.ignore(10000, '\n');
	
	if (numRounds <= 0){
		cout << "The number of rounds must be positive." << endl;
		return 1;
	}
	int min = 0;
	int max = 0;
	double avg = 0;
	int tries = 0;
	int tryArray [numRounds];
	char tryString[7];
	

	for (int i = 1 ; i <= numRounds; i++){
		cout << endl << "Round " << i << endl;
		wordNum = randInt(0, numWords - 1); // Chooses a random index in the array for a target word
		
		//test:
//		cerr << "Word: " << wordList[wordNum]  << endl; 
		//end test
		
		//Gives the length of the secret word
		cout << "The secret word is " << strlen(wordList[wordNum]) << " letters long." << endl;

		// runs a single round of the game
		tries = runOneRound(wordList, numWords, wordNum);
		
		// adds the number of tries it took to the array
		tryArray[i - 1] = tries;

		// searches the array to find the min, max, and avg
		min = getMin(tryArray, i);
		max = getMax(tryArray, i);
		avg = getAvg(tryArray, i);
		
		cout.setf(ios::fixed);
		cout.precision(2);
		
		
		if (tries == 1)
			strcpy(tryString, " try");
		else
			strcpy(tryString, " tries");
	
		cout << "You got it in " << tries << tryString << '.' << endl;
		cout << "Average: " << avg << ", minimum: " << min << ", maximum: " << max << endl;
}
}		
	
	



bool badChar(const char probe[]){
	int len = strlen(probe);
	for (int i = 0; i < len; i++)
		// Checks that the characters are lowercase and alphabetic
		if (!(islower(probe[i]) && isalpha(probe[i]))) 
			return true;
	return false;

}

int runOneRound(const char words[][MAXWORDLEN + 1], int nWords, int wordNum){
	if (nWords <= 0 || (wordNum < 0 || wordNum >= nWords))
		return -1;
	
	char probe[100];
	int stars = 0;
	int planets = 0;
	int count = 0;
	bool isMatch = false;
	while ( ! isMatch){ // while the probe is not the mystery string
		
		cout << "Probe word: ";
		cin.getline(probe, 100);

		if (strlen(probe) < 4 || strlen(probe) > 6 || badChar(probe)){ // if the probe is not of the right length/has bad characters
			cout << "Your probe word must be a word of 4 to 6 lowercase letters." << endl;
			continue;
		}else if (! findWord(probe, words, nWords)){ // if the probe is not in the word array
			cout << "I don't know that word." << endl;
			continue; 
		}else if (strcmp(probe, words[wordNum]) != 0){ // if the probe is not the target
			
			StarPlan set = findStarsAndPlanets(probe,words[wordNum]); // find the stars and planets
			stars = set.stars;
			planets = set.planets;
			cout << "Stars: " << stars << ", Planets: " << planets << endl;
		}else // if the probe is the target string, exit the loop
			isMatch = true;
		
		count++;	
	}
	return count;
	
	
}

bool findWord(const char probe[], const char words[][MAXWORDLEN + 1], int nWords){
	for (int i = 0; i < nWords; i++)
		if (strcmp(words[i], probe) == 0) // Checks if the probe is in the word array
			return true;

	return false;
}

StarPlan findStarsAndPlanets(const char probe[], const char target[]){
	// Creates an object of type StarPlan to store the star and planet variables
	StarPlan meme;
	int stars = 0;
	int planets = 0;

	// Copies the cstrings containing the probe and the secret word
	char inter [strlen(probe)];
	char tarjay [strlen(target)];
	strcpy(inter, probe);
	strcpy(tarjay, target);	

	// Iterates through the characters in the probe and secret
	// string to check for stars
	for (int i = 0; i < strlen(probe); i++)
		for (int j = 0; j < strlen(target); j++)
			if (probe[i] == target[j])
				if (i == j){
					stars++;
					inter[i] = '!';  // Assigns nonalpha values to chars
					tarjay[j] = '@'; // that have already been mapped as stars
				}
	// Test:		
//	cerr << "Inter: " << inter << endl;
	// end test

	// Iterates through the characters in the probe and the secret
	// string to check for planets
	for (int k = 0; k < strlen(inter); k++)
		for (int l = 0; l < strlen(tarjay); l++)
			if (inter[k] == tarjay[l]){
				planets++;
				tarjay[l] = '@'; // Assigns nonalpha values to chars
				inter[k] = '!';  // that have already been mapped as planets
			}
	// Test:
//	cerr << "Tarjay: " << tarjay << endl;
	// end test 	
	meme.stars = stars;
	meme.planets = planets;	
	return meme;
}


int getMin(int arr[], int len){
	int min = arr[0];
	// Finds the minimum integer of an array
	for (int i = 0; i < len; i++){
		if (arr[i] < min)
			min = arr[i]; 
	}
	return min;

}
int getMax(int arr[], int len){
	int max = arr[0];
	// Finds the maximum integer of an array
	for (int i = 0; i < len; i++){
		if (arr[i] > max)
			max = arr[i]; 
	}
	return max;

}
double getAvg(int arr[], int len){
	double tot = 0;
	// Finds the average value of an array
	for (int i = 0; i < len; i++)
		tot += arr[i];
	return tot / len;
}
