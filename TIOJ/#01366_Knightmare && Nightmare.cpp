#include <bits/stdc++.h>
#define pii pair<int,int>
#define psp pair<string,pii>
#define ff first
#define ss second
using namespace std;

const int MAXN = 100000;
int n;
psp arr[MAXN];

bool const cmp(const psp a, const psp b) {
	if (a.ss.ff != b.ss.ff)
		return a.ss.ff < b.ss.ff;
	return a.ss.ss < b.ss.ss;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].ff;
		for (int j = 0; j < arr[i].ff.size(); j++)
			arr[i].ss.ff += arr[i].ff[j]-'0';
		arr[i].ss.ss = i;
	}
	sort(arr, arr+n, cmp);
	for (int i = 0; i < n; i++)
		cout << arr[i].ff << " \n"[i==n-1];
	return 0;
}