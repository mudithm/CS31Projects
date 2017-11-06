#include <iostream>
#include <string>
#include <regex>

using namespace std;


string surroundWithBrackets(string& inst){
	string out = "";

	regex e("\'[.]+\'");

	sregex_iterator iter(inst.begin(), inst.end(), e);
	sregex_iterator end;

	while (iter != end){
		string n = (*iter)[0].str();
		cout << n << endl;
		iter++;
	}

	return out;

}

int main(){
	string beem = "'This''THis''s'";
	surroundWithBrackets(beem);
	cout << beem << endl;
}



