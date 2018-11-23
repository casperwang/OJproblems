//Street Numbers: math
#include <iostream>
#include <cmath>
using namespace std;

long long int t, a, b;

int main() {
	for (a = 2; t < 10; a++) {
		b = (sqrt(8*a*a+1)-1)/2;
		if (b*b+b-2*a*a == 0) {
			for (int i = 9; i > log10(a); i--) cout << " ";
			cout << a;
			for (int i = 9; i > log10(b); i--) cout << " ";
			cout << b << endl;
			t++;
		}
	}
	return 0;
}
