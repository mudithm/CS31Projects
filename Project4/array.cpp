#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int appendToAll(string a[], int n, string value); // appends a string to each element of the array
int lookup(const string a[], int n, string target); // returns the position of a target string in the array
int positionOfMax(const string a[], int n); // returns the position of the greatest string in the array
int rotateLeft(string a[], int n, int pos); // Move an element to the end and shift all elements after it back
int countRuns(const string a[], int n); // returns the number of sequences of one or more consecutive identical items in the array
int flip(string a[], int n); // reverses the order of the elements in the array
int differ(const string a1[], int n1, const string a2[], int n2); // returns the posiiton og the first element that doesnt match between the two arrays
int subsequence(const string a1[], int n1, const string a2[], int n2); // if the whole second array is a subsequence of the first, return the index of the first element of the subsequence
int lookupAny(const string a1[], int n1, const string a2[], int n2); // returnsint split(string a[], int n, string splitter) the posiiton of the first term in a2 that shows up in a1.
int split(string a[], int n, string splitter); // compares each element to splitter. Thoses less than splitter go first, those greater go after.


int main(){

 	    string h[7] = { "selina", "reed", "diana", "tony", "", "logan", "peter" };
	    assert(lookup(h, 7, "logan") == 5);
	    assert(lookup(h, 7, "diana") == 2);
	    assert(lookup(h, 2, "diana") == -1);
	    assert(positionOfMax(h, 7) == 3);

	    string g[4] = { "selina", "reed", "peter", "sue" };
	    assert(differ(h, 4, g, 4) == 2);
	    assert(appendToAll(g, 4, "?") == 4 && g[0] == "selina?" && g[3] == "sue?");
	    assert(rotateLeft(g, 4, 1) == 1 && g[1] == "peter?" && g[3] == "reed?");

	    string e[4] = { "diana", "tony", "", "logan" };
	    assert(subsequence(h, 7, e, 4) == 2);

	    string d[5] = { "reed", "reed", "reed", "tony", "tony" };
	    assert(countRuns(d, 5) == 2);
	
	    string f[3] = { "peter", "diana", "steve" };
	    assert(lookupAny(h, 7, f, 3) == 2);
	    assert(flip(f, 3) == 3 && f[0] == "steve" && f[2] == "peter");
	
	    assert(split(h, 7, "peter") == 3);
	
	    cout << "All tests succeeded" << endl;	
}
// appends a string to each element of the array
int appendToAll(string a[], int n, string value){ 
	if (n < 0)
		return -1;

	for (int i = 0; i < n; i++){
		a[i] += value;
	}
	
	return n;

}

int lookup(const string a[], int n, string target){
	if (n < 0)
		return -1;
	for (int i = 0; i < n;  i++){
		if (a[i] == target)
			return i;	
	}
	return -1;
		
}

int positionOfMax(const string a[], int n){
	if (n < 0)
		return -1;
	string max = "";
	int maxPos = 0;
	for (int i = 0; i < n; i++)
		if (a[i] > max){
			max = a[i];
			maxPos = i;
		}
	return maxPos;

}

int rotateLeft(string a[], int n, int pos){
	if (n < 0 || pos > n)
		return -1;
	string str = a[pos];
	for (int i = pos; i < n - 1; i++){
		a[i] = a[i+1];
	}
	a[n-1] = str;
	return pos;
}


int countRuns(const string a[], int n){
	if (n < 0)
		return -1;
	string currentRun = "";
	int count = 0;
	for (int i = 0; i < n; i++){
		if (a[i] != currentRun){
			currentRun = a[i];
			count++;
		}	
	}
	return count;
}

int flip(string a[], int n){
	if (n < 0)
		return -1;
	for (int i = n - 1; i >= n / 2; i--){
		string temp = a[i];
		a[i] = a[(n-1)-i];
		a[(n-1)-i] = temp;
	}
	return n;

}


int differ(const string a1[], int n1, const string a2[], int n2){
	if (n1 < 0 || n2 < 0)
		return -1;
	for (int i = 0; i < n1 && i < n2; i++){
		if (a1[i] != a2[i])
			return i;
	}
	if (n1 <= n2)
		return n1;
	else
		return n2;	

}

int subsequence(const string a1[], int n1, const string a2[], int n2){
	bool isSub = false;
	int firstPos = -1;
	if (n2 == 0)
		return 0;
	if (n1 < 0 || n2 < 0 || n2 > n2)
		return -1;
	for (int i = 0; i < n1 - n2; i++){
		for (int j = 0; j < n2; j++){
			if (a1[i+j] == a2[j]){
				isSub = true;
				firstPos = i;
			}else{
				isSub = false;
				break;	
			}
		}
		if (isSub)
			return firstPos;
	}
	return firstPos;

}

int lookupAny(const string a1[], int n1, const string a2[], int n2){
	if (n1 < 0 || n2 < 0)
		return -1;
	for (int i = 0; i < n1; i++)
		for (int j = 0; j < n2; j++)
			if (a1[i] == a2[j])
				return i;
	return -1;

}

int split(string a[], int n, string splitter){
	if (n < 0)
		return -1;
	int numLess = 0;
	for (int i = 0; i < n; i++)
		if (a[i] < splitter)
			numLess++;
	for (int j = 0; j < n; j++){
		if (a[j] < splitter){
			for (int k = 0; k <= j; k++)
				if (a[k] >= splitter){
					string temp = a[j];
					a[j] = a[k];
					a[k] = temp;
				}
		}else if (a[j] > splitter){
			for (int k = n - 1; k >= j; k--){
				if (a[k] <= splitter){
					string temp = a[j];
					a[j] = a[k];
					a[k] = temp;
				}	
			}
		}
	}
	return numLess;		
}	
