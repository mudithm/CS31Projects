#include <iostream>
#include <string>

using namespace std;

int main()
{




	cout << "1" << endl << endl;

	string grendel = "endl";
	cout << "endl";
	cout << grendel;
	cout << endl;
	cout << "grendel";

	cout << "2" << endl << endl;

	 int side;

	    cout << "Enter a number: ";
	    cin >> side;

	    for (int i = 0; i < side; i++)
	    {
		for (int j = i; j >= 0; j--)
		{
		    cout << "#";
		}
		cout << "\n";
	    }


	cout << "3" << endl << endl;

	int sode;

        cout << "Enter a number: ";
        cin >> sode;

        for (int i = 0; i < sode; i++)
        {
            int j = i;
        
        while (j >= 0)
        {
            cout << "#";
            j--;
        }
        
        cout << "\n";
        }


    cout << "4" << endl << endl;

    int sude;

        cout << "Enter a number: ";
        cin >> sude;
        int i = 0;
        do 
        {
        int j = i;

        while (j > 0)
        {
            cout << "#";
            j--;
        }

        cout << "\n";
        i++;
        }while (i <= sude);



        cout << "5" << endl << endl;

	int codeSection;

	cout << "enter the code  ";
	cin >> codeSection;

	switch (codeSection)
{
    case 281:
        cout << "bigamy";
        break;
    case 321:
    case 322:
        cout << "selling illegal lottery tickets";
        break;
    case 383:
        cout << "selling rancid butter";
        break;
    case 598:
        cout << "wounding a bird in a public cemetery";
        break;
    default:
        cout << "some other crime";
}


	return 0;
}
