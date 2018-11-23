//Bangla Numbers: trivial
#include <iostream>
#include <cmath> 
using namespace std;

long long int t, n;

int main() {
	while (cin >> n) {
		t++;
		for (int i = 3; i > log10(t); i--) cout << " ";
		cout << t << ".";
		bool tf = 0;
		if (n >= 1000000000) tf = 1;
		bool tf2 = 0;
		if (n < 100) tf2 = 1;
		if (n >= 100000000000000) {
			cout << " " << n/100000000000000 << " kuti";
			n %= 100000000000000;
		}
		if (n >= 1000000000000) {
			cout << " " << n/1000000000000 << " lakh";
			n %= 1000000000000;
		}
		if (n >= 10000000000) {
			cout << " " << n/10000000000 << " hajar";
			n %= 10000000000;
		}
		if (n >= 1000000000) {
			cout << " " << n/1000000000 << " shata";
			n %= 1000000000;
		}
		if (n >= 10000000) {
			cout << " " << n/10000000 << " kuti";
			n %= 10000000;
		} else if (tf) cout << " kuti";
		if (n >= 100000) {
			cout << " " << n/100000 << " lakh";
			n %= 100000;
		}
		if (n >= 1000) {
			cout << " " << n/1000 << " hajar";
			n %= 1000;
		}
		if (n >= 100) {
			cout << " " << n/100 << " shata";
			n %= 100;
		}
		if (tf2 || n > 0) cout << " " << n;
		cout << endl;
	}
	return 0;
}
