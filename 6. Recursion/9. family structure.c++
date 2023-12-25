#include<bits/stdc++.h>
using namespace std;

/* Que. */
// Aakash is a member of Ninja club. He has a weird family structure. Every male member(M)
// gives birth to a male child first and then a female child, whereas every female (F)
// member gives birth to a female child first and then to a male child. Aakash analyses
// this pattern and wants to know what will be the Kth child in his Nth generation.

string kthChildNthGeneration(int n, long long int k){
	if(n == 1 || k == 1) {
		return "Male";
	}
		
	// Parent of the Kth child of Nth generation
	long long int par = (k+1)/2;

	// Recursively find the gender of the parent
	string parGender = kthChildNthGeneration(n-1, par);

	// If Kth child of Nth generation is the first child of its parent
	if(k == (2*par)-1) {
		return parGender;
	}
	// If Kth child of Nth generation is the second child of its parent
	else {
		if(parGender == "Male") {
			return "Female";
		}
		else {
			return "Male";
		}
	}
}

int main() {
    int n; cin >> n;
    int k; cin >> k;

    cout << kthChildNthGeneration(n,k) << endl;

    return 0;
}