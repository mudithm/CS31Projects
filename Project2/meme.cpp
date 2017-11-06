#include <iostream>
    using namespace std;

    int main()
    {
        int side;

        cout << "Enter a number: ";
        cin >> side;
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
        }while (i <= side);
    }
