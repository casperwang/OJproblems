//Meteor Coding Cup Round #5 - A: trivial
#include <iostream>
#include <map>
using namespace std;

int n;
string a;

int main() {
    map <string, bool> A;
	cin >> n;
	for (int i = 0; i < n; i++) {
        cin >> a;
        A[a] = 1;
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
        cin >> a;
        if (A.count(a)) cout << "Yes" << endl;
        else cout << "No" << endl;
	}
	return 0;
}

