//Network Connections: disjoint set
#include <iostream>
#include <stack>
#define N 1000000
using namespace std;

int t, n, a, b, T, F;
int ancestor[N+5];
char action;

void finding(int a) {
	stack <int> family;
	family.push(a);
	while (ancestor[family.top()] != family.top()) {
		family.push(ancestor[family.top()]);
	}
	int tmp = family.top();
	while (family.size()) {
		ancestor[family.top()] = tmp;
		family.pop();
	}
	return;
}

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		if (i) cout << endl;
		cin >> n;
		T = 0;
		F = 0;
		for (int j = 1; j <= n; j++) ancestor[j] = j;
		cin.get();
		action = cin.get();
		while (action == 'c' || action == 'q') {
			cin.get();
			cin >> a >> b;
			finding(a);
			finding(b);
			if (action == 'c') ancestor[ancestor[a]] = ancestor[b];
			else if (ancestor[a] == ancestor[b]) T++;
			else F++;
			cin.get();
			action = cin.peek();
		}
		cout << T << "," << F << endl; 
	} 
	return 0;
}
