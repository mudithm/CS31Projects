#include <cassert>
#include <iostream>
#include <string>
#include <regex>


using namespace std;

int getBeats(string noteString);
bool isPlayableBeat(string note);
bool isValidBeat(string note);
bool isValidSong(string song);

char encodeNote(int octave, char noteLetter, char accidentalSign);

bool hasCorrectSyntax(string song);
int encodeSong(string song, string& instructions, int& badBeat);

int main(){
	string instruc;
	int badBeat = 0;
	string song = "G3B3DD5//G/A/A3B/C5/B3D5//G//G//CE5//C5/D5/E5/F#5/B3G5//G//G/";
	//string song;
	//getline(cin, song);
	int meme = encodeSong(song, instruc, badBeat);
	cout << meme << " | " << instruc << " | " << badBeat << endl;



	assert(hasCorrectSyntax("D5//D/"));
    assert(!hasCorrectSyntax("D5//Z/"));
    string instrs;
    int badb;
    instrs = "xxx"; badb = -999; // so we can detect whether these get changed
    assert(encodeSong("G3B3DD5//G/A/A3B/C5/B3D5//G//G//CE5//C5/D5/E5/F#5/B3G5//G//G/", instrs, badb) == 0  &&  instrs == instruc  &&  badb == -999);
    instrs = "xxx"; badb = -999; // so we can detect whether these get changed
    assert(encodeSong("D5//Cb2/", instrs, badb) == 2  &&  instrs == "xxx"  &&  badb == 3);
    assert(encodeSong("D5//D8/", instrs, badb) == 2  &&  instrs == "xxx"  &&  badb == 3);
	cerr << "all tests succ" << endl;


	for (;;){
		getline(cin, song);
		if (song == "quit")
			break;
		cout << "hasCorrectSyntax returns  ";
		if (hasCorrectSyntax(song))
			cout << "true" << endl;
		else 
			cout << "false" << endl;

	}
	
}

//Function to encode a playable note

char encodeNote(int octave, char noteLetter, char accidentalSign)
{
      // This check is here solely to report a common CS 31 student error.
    if (octave > 9)
    {
        cerr << "********** encodeNote was called with first argument = "
             << octave << endl;
    }

      // Convert Cb, C, C#/Db, D, D#/Eb, ..., B, B#
      //      to -1, 0,   1,   2,   3, ...,  11, 12

    int note;
    switch (noteLetter)
    {
      case 'C':  note =  0; break;
      case 'D':  note =  2; break;
      case 'E':  note =  4; break;
      case 'F':  note =  5; break;
      case 'G':  note =  7; break;
      case 'A':  note =  9; break;
      case 'B':  note = 11; break;
      default:   return ' ';
    }
    switch (accidentalSign)
    {
      case '#':  note++; break;
      case 'b':  note--; break;
      case ' ':  break;
      default:   return ' ';
    }

      // Convert ..., A#1, B1, C2, C#2, D2, ... to
      //         ..., -2,  -1, 0,   1,  2, ...

    int sequenceNumber = 12 * (octave - 2) + note;

    string keymap = "Z1X2CV3B4N5M,6.7/A8S9D0FG!H@JK#L$Q%WE^R&TY*U(I)OP";
    if (sequenceNumber < 0  ||  sequenceNumber >= keymap.size())
        return ' ';
    return keymap[sequenceNumber];
}


// Function to get the number of beats in a song
int getBeats(string noteString){
	int numBeats = 0;

	for (int i = 0; i < noteString.size(); i ++)
		if (noteString[i] == '/')
			numBeats++;
		
	return numBeats;

}

// Function to test whether a beat is playable
bool isPlayableBeat(string note){
	regex e("(([ABDEFG][#b]?[2345]?)*|(B#1)*|(C[#b]?[345]?)*|(Cb?6)*|(C#2)*)+/");
	bool match = regex_match(note, e);
	
	return match;
}

bool isValidBeat(string note){
	regex e("([ABCDEFG][#b]?[0123456789]?)*/");
	bool match = regex_match(note, e);
	
	return match;
}

bool hasCorrectSyntax(string song){
	int numBeats = getBeats(song); // Count the number of beats in the song
	string beats [numBeats]; //Create a string array to store the individual beats

	/* Split the song into individual beats and store them in an array */
	
	int loc;
	
	for (int i = 0; i < numBeats; i++){
		loc = song.find('/');		
		beats[i] = song.substr(0, loc+1);

		// Checks that this beat contains playable notes
		if (!(isPlayableBeat(beats[i])))
			return false;

		 //removes the part of the song string that has just been processed
		song = song.substr((loc)+1, song.size());
	}

	if (!(isPlayableBeat(song)) && song != "") // Checks if there are any trailing values after the last beat
			return false;


	return true;
}

bool isValidSong(string song){
	int numBeats = getBeats(song); // Count the number of beats in the song
	string beats [numBeats]; //Create a string array to store the individual beats

	/* Split the song into individual beats and store them in an array */
	
	int loc;
	
	for (int i = 0; i < numBeats; i++){
		loc = song.find('/');		
		beats[i] = song.substr(0, loc+1);

		// Checks that this beat contains playable notes
		if (!(isValidBeat(beats[i])))
			return false;

		 //removes the part of the song string that has just been processed
		song = song.substr((loc)+1, song.size());
	}

	if (!(isValidBeat(song)) && song != "") // Checks if there are any trailing values after the last beat
			return false;


	return true;
}

int encodeSong(string song, string& instructions, int& badBeat){
	if (hasCorrectSyntax(song)){
		int numBeats = getBeats(song); // Count the number of beats in the song
		string beats [numBeats]; //Create a string array to store the individual beats

		/* Split the song into individual beats and store them in an array */

		int loc;

		for (int i = 0; i < numBeats; i++){
			loc = song.find('/');		
			beats[i] = song.substr(0, loc+1);

			 //removes the part of the song string that has just been processed
			song = song.substr((loc)+1, song.size());
		}

		instructions = "";

		int octave = 4;
		char noteLetter, accidentalSign;

		regex e("(([ABCDEFG][#b]?[0123456789]?))|//");
		regex o("[0123456789]");
		regex nl("[ABCDEFG]");
		regex as("[#b]");
		smatch nLet;
		smatch oct;
		smatch accSig;

		string tem;
		string ins;
		int count;
		for (int note = 0; note < numBeats; note++){
			tem = beats[note];
			ins = "";

			sregex_iterator iter(tem.begin(), tem.end(), e);
			sregex_iterator end;


			count = 0;
			while (iter != end ){

				accidentalSign = ' ';
				noteLetter = ' ';
				octave = 4;

				string n = (*iter)[0].str();

				if(n == "//"){
					ins += " ";
					iter++;
					continue;
				}

				
				if (regex_search(n, oct, o))
					octave = atoi((oct[0].str()).c_str());
				if(regex_search(n, nLet, nl))
					noteLetter = (nLet[0].str())[0];
				if(regex_search(n, accSig, as))
					accidentalSign = (accSig[0].str())[0];
				
				ins += encodeNote(octave, noteLetter, accidentalSign);
				

				count++;

				++iter;
			}
			if (count > 1)
				instructions += "[" + ins + "]";
			else
				instructions += ins;
			if (beats[note] == "/")
				instructions += ' ';
		}



		

	

		return 0;

	}else if(! isValidSong(song)){
		return 1;
	}else if(isValidSong(song)){
		string s = song;
		int numBeats = getBeats(s);
		string beats [numBeats];

		int loc = 0;
		for (int i = 0; i < numBeats; i++){
			loc = s.find('/');		
			beats[i] = s.substr(0, loc+1);

			// Checks that this beat contains playable notes
			if (!(isPlayableBeat(beats[i])))
				badBeat = i + 1;

		 	//removes the part of the song string that has just been processed
			s = s.substr((loc)+1, s.size());
		}

		return 2;
	}
	return 0;

}

