#include <bits/stdc++.h>
using namespace std;

int n, t;

void DFS(int now, int a, int b) {
	if (now-1) DFS(now-1, a, 6-a-b);
	cout << "#" << ++t << " : move the dish from #" << a << " to #" << b << '\n';
	if (now-1) DFS(now-1, 6-a-b, b);
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	DFS(n, 1, 3);
	return 0;
}