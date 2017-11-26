#define _CRT_SECURE_NO_DEPRECATE
//#include "utilities.h"
#include "utilities.cpp"
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

const char WORDFILENAME[] = "words.txt";

//function prototypes
int runOneRound(const char words[][7], int nWords, int wordnum);
int getNumStars(const char target[], const char probe[], int sizeTarget, int sizeProbe);
int getNumPlanets(const char target[], const char probe[], int sizeTarget, int sizeProbe);
bool isLowerLetters(char word[], int length);
int main()
{
	int numRounds; 
	int numTriesPerRound;
	double average; 
	int totalTries = 0; 
	int min = 0; 
	int max = 0; 
	char w[9000][7];
	int n;
	cout << "How many rounds do you want to play? ";
	cin >> numRounds; 
	cin.ignore(10000, '\n');
	cout << endl; 
	n = getWords(w, 9000, WORDFILENAME);
	for (int counterRounds = 0; counterRounds < numRounds; counterRounds++)
	{
		cout << "Round " << counterRounds + 1 << endl;
		numTriesPerRound = runOneRound(w, n, randInt(0, n - 1));
		cout << "You got it in " << numTriesPerRound << " tries." << endl;
		totalTries = totalTries + numTriesPerRound;
		average = double(totalTries) / double(counterRounds + 1);
		if (counterRounds == 0)
		{
			min = numTriesPerRound; 
			max = numTriesPerRound; 
		}
		else
		{
			if (min > numTriesPerRound)
			{
				min = numTriesPerRound; 
			}
			if (numTriesPerRound > max)
			{
				max = numTriesPerRound; 
			}
		}
		cout << "Average: " << fixed << setprecision(2) << average; 
		cout << ", minimum: " << min << ", maximum: " << max;
		cout << endl << endl; 

	}
	cout << " ";
	return 0; 
}
int getNumStars(const char target[], const char probe[], int sizeTarget, int sizeProbe)
{
	int numStars = 0;
	for (int counter = 0; counter < sizeTarget && counter < sizeProbe; counter++)
	{
		if (target[counter] == probe[counter])
		{
			numStars++;
		}
	}
	return numStars;
}
int getNumPlanets(const char target[], const char probe[], int sizeTarget, int sizeProbe)
{
	int numPlanets = 0;
	int numStars = 0;
	int indexStar[7];
	int probeMatched[7] = { 0 };
	int numIndexStar = 0;
	int numMatches;
	for (int counter = 0; counter < sizeTarget && counter < sizeProbe; counter++)
	{
		if (target[counter] == probe[counter])
		{
			numStars++;
			indexStar[numIndexStar] = 1;
			numIndexStar++;
		}
		else
		{
			indexStar[numIndexStar] = 0;
			numIndexStar++;
		}
	}
	for (int i = 0; i < 7; i++)
	{
		if (indexStar[i] == 0)
		{
			numMatches = 0;
			for (int j = 0; j < sizeProbe && numMatches < 1; j++)
			{
				if (target[i] == probe[j] && indexStar[j] != 1 && probeMatched[j] == 0)
				{
					numPlanets++;
					probeMatched[j] = 1;
					numMatches++;
				}
			}
		}
	}
	return numPlanets;
}
bool isLowerLetters(char word[], int length)
{
	if (length < 4)
	{
		return false; 
	}
	if (length > 6)
	{
		return false; 
	}
	for (int i = 0; i < length; i++)
	{
		if (islower(word[i]) != 0  && isalpha(word[i]) != 0  && ispunct(word[i]) == 0 && isspace(word[i]) == 0)
		{
		}
		else
		{
			return false; 
		}
	}
	return true; 
}
int runOneRound(const char words[][7], int nWords, int wordnum)
{	
	nWords++;
	nWords--;	
	int numStars;
	int numPlanets;
	int numTries = 0;
	bool isProbe = false;
	char currentWord[7];
	strcpy(currentWord, words[wordnum]);
	int i = strlen(currentWord);
	cout << "The secret word is " << i << " letters long." << endl;
	// testing
	cout << currentWord << endl;
	//testing
	numStars = 0;
	numPlanets = 0;
	char probeWord[100];
	while (! (strcmp(probeWord, words[wordnum]) == 0))// change back to i
	{
		 
			
		cout << "Probe word: ";
		cin.getline(probeWord, 100);
		//cin.ignore(10000, '\n');
		
		bool probeInArray = false;
		for (int i = 0; i < nWords && probeInArray == false; i++)
		{
			if (strcmp(probeWord, words[i]) == 0)
			{
				probeInArray = true;
			}
		} 


		int j;
		for (j = 0; probeWord[j] != '\0'; j++)
		{
		}
		if (!isLowerLetters(probeWord, j))
		{
			cout << "Your probe word must be a word of 4 to 6 lower case letters." << endl;
			continue;
		}
		for (int counter = 0; counter < 9000 && isProbe != true; counter++)
		{
			if (strcmp(probeWord, words[counter]) == 0)
			{
				isProbe = true;
			}
		}
		if (!( probeInArray))
		{
			cout << "I don't know that word." << endl;
			isProbe = true;
			continue;
		}
		numStars = getNumStars(currentWord, probeWord, i, j);
		numPlanets = getNumPlanets(currentWord, probeWord, i, j);
		if (numStars != i)
		{
			cout << "Stars: " << numStars;
			cout << ", Planets: " << numPlanets;
			numTries++;
			cout << endl;
		}
		else
		{
			numTries++; 
		}
	}
	return numTries; 
	
}
