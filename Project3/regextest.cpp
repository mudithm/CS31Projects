#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main(){
	string note;
	while (true){
		getline(cin, note);
		regex e("(([ABDEFG][#b]?[2345]?)*|(B#1)*|(C[#b]?[345]?)*|(Cb?6)*|(C#2)*)+/");
		bool match = regex_match(note, e);
	

		cout << (match? "Matched" : "Not matched") << endl << endl;
	}


}
