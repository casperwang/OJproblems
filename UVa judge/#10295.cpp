//Hay Points: trivial map
#include <iostream>
#include <map>
using namespace std;

long long int n, m, ans, val;
string a;
map <string, int> value;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a >> val;
		value[a] = val;
	}
	for (int i = 0; i < m; i++) {
		ans = 0;
		while(cin >> a) {
			if (a == ".") break;
			ans += value[a];
		}
		cout << ans << endl; 
	}
	return 0;
}
