//Three Families: trivial math problem
#include <iostream>
using namespace std;

int T, x, y, z;

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> x >> y >> z;
		cout << 3*x*z/(x+y)-z << endl;
	}
	return 0;
}
