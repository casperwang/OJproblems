//Babelfish: STL-map
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

string a, b;
char c;

int main() {
	map <string, string> dictionary;
	while (cin >> a) {
		c = cin.get();
		if (c == ' ') {
			cin >> b;
			dictionary.insert(pair<string, string>(b, a));
		} else {
			if (dictionary.count(b)) cout << dictionary[b] << endl;
			else cout << "eh" << endl;
		}
	}
	return 0;
}
