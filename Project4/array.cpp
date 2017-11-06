#include <iostream>
#include <string>

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
	string meme[6] = {"hello", "1", "2", "3", "4", "hll"};
	string meme2[6] = {"hello", "1", "2", "3", "4", "hll"};

	cout << differ(meme, 6, meme2, 6) << endl;
	for (int i = 0; i < 6; i++)
		cout << meme[i] << " ";
	cout << endl;	

	rotateLeft(meme, 6, 3);
	

	for (int i = 0; i < 6; i++)
		cout << meme[i] << " ";
	cout << endl;	

	flip(meme, 6);

	
	for (int i = 0; i < 6; i++)
		cout << meme[i] << " ";
	cout << endl;	

	string d[9] = {
  	  "tony", "bruce", "steve", "steve", "diana", "diana", "diana", "steve", "steve"
	};
	string f[3] = {"shitboi", "shitboa", "bruce"};


	cout << subsequence(d, 9, f, 3) << endl;
	cout << lookupAny(d, 9, f, 3) << endl;
	cout << countRuns(d, 9) << endl;
}

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
	if (n < 0 || pos >= n)
		return -1;
	string str = a[pos];
	for (int i = pos; i < n - 1; i++){
		a[i] = a[i+1];
	}
	a[n-1] = str;
	return n;
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

}
