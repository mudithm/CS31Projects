#include <iostream>
#include <string>

using namespace std;

int main(){
	
	double fare;
	int age, boundaries;
	string student, destination;

	cout << "Age of rider: ";
	cin >> age;
	cin.ignore(10000, '\n');
	
	cout << "Student? (y/n): ";
	getline(cin, student);

	cout << "Destination: ";
	getline(cin, destination);
	
	cout << "Number of zone boundaries crossed: ";
	cin >> boundaries;

	cout << "---" << endl;
	

	if (age >= 65 && boundaries == 0)
		fare = .45; 
	else if ((age < 18 || student == "y") && boundaries < 2)
		fare = .65;
	else if (age >= 65 && boundaries > 0)
		fare = .25 * boundaries + .55;
	else
		fare = .55 * boundaries + 1.35;


	if (age < 0){
		cout << "The age must not be negative." << endl;
		return -1;
	} else if (!(student == "y" || student == "n")){
		cout << "You must enter y or n" << endl;
		return -1;
	}else if (boundaries < 0){
		cout << "The number of zone boundaries crossed must not be negative." << endl;
		return -1;
	} else
		cout << "The fare to " << destination << " is S" << fare << endl;
	

	return 0;
}	
