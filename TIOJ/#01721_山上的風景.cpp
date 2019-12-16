#include <bits/stdc++.h>
#define MAXN 100000
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

int n, a[MAXN+5];
int ans[MAXN+5];
stack <pii> now;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> n) {
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		while (now.size()) now.pop();
		for (int i = 1; i <= n; i++) {
			while (now.size() && a[i] > now.top().ff) now.pop();
			if (!now.size()) ans[i] = i;
			else ans[i] = i-now.top().ss+1;
			if (now.size() && a[i] == now.top().ff) now.pop();
			now.push(pii(a[i], i));
		}
		while (now.size()) now.pop();
		for (int i = n; i >= 1; i--) {
			while (now.size() && a[i] > now.top().ff) now.pop();
			if (!now.size()) ans[i] += n-i;
			else ans[i] += now.top().ss-i;
			if (now.size() && a[i] == now.top().ff) now.pop();
			now.push(pii(a[i], i));
		}
		for (int i = 1; i <= n; i++)
			cout << ans[i] << " \n"[i==n];
	}
}