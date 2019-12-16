#include <bits/stdc++.h>
#define MAXN 1000000
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

int n, tmp;
int a[MAXN+5];
stack <pii> now;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = n; i; i--) {
		tmp = a[i];
		while (now.size() && a[i] > now.top().ff)
			now.pop();
		if (now.size()) a[i] = now.top().ss-i;
		else a[i] = n-i;
		if (now.size() && a[i] == now.top().ff)
			now.pop();
		now.push(pii(tmp, i));
	}
	for (int i = 1; i <= n; i++)
		cout << a[i] << '\n';
}