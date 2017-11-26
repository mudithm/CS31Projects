
#include <iostream>
    using namespace std;

    int* nochange(int* p)
    {
        return p;
    }

    int* getPtrToArray(int& m)
    {
        int anArray[100];
        for (int j = 0; j < 100; j++)
            anArray[j] = 100-j;
        m = 100;
        return nochange(anArray);
    }

    void f(int* ptr)
    {
        int junk[100];
        for (int k = 0; k < 100; k++)
            junk[k] = 123400000 + k;
        for (int i = 0; i < 100; i++){
        	cout << *(ptr + i) << " ";

        }
        cout << endl;
        junk[50]++;
    }


     double mean(const double* scores, int numScores)
    {
    	
        int count = 0;
        double tot = 0;
        while (count < numScores)
        {
            tot += *(scores + count);
            count++;
        }
        return tot/numScores;
    }
/*
    const char* findTheChar(const char* str, char chr)
    {
        for (int k = 0; *str != 0; k++)
            if (*(str + k) == chr)
                return (str + k);

        return NULL;

    }
*/

     const char* findTheChar(const char* str, char chr)
    {
        for (; str != 0; str++)
            if (*str == chr)
                return str;

        return NULL;
    }


void removeS(char* ch){
        char* inter = ch;
        while(*inter != 0){
            while (*inter == 'S' || *inter == 's')
                inter++;
            
            *ch = *inter;
			ch++;
            inter++;

        }
        ch++;
        *ch = '\0';

    }


    int main()
    {
        int n;
        int* ptr = getPtrToArray(n);
        f(ptr);
        for (int i = 0; i < 3; i++)
            cout << ptr[i] << ' ';
        for (int i = n-3; i < n; i++)
            cout << ptr[i] << ' ';
        cout << endl;

/*
        double* cat;
        double mouse[4];
        cat = &mouse[4];

        *cat = 25;
        *(mouse + 3) = 42;
        cat -= 3;
        *(cat + 1) = 54;
        (cat - 1)[1] = 27;
        bool b = (*cat == *(cat + 1));
        bool d = (cat == mouse);

        double scores [5] = {95, 85, 95, 85, 100};
        cout << mean(scores, 5) << endl;

        char meme [50] = "shittyfhello";
        cout << findTheChar(meme, 'f') << endl;

        char mem [50] = "Shit shit shit SHit sHit";
        removeS(mem);
        cout << mem << endl;*/

    }
