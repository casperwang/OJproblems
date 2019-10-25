#include <bits/stdc++.h>
#define MAXN 300000
#define int long long
#define pb push_back
#define ff first
#define ss second
using namespace std;

int n, k;
pair <int, pair<int,int> > arr[MAXN+5];
vector <int> ans;
set < pair<int,int> > appr;

class BIT{
public:
	int arr[MAXN+5];
	int lowbit(int a) {
		return a &- a;
	}
	int qry(int now) {
		return now?qry(now-lowbit(now))+arr[now]:0;
	}
	void mdy(int now, int k) {
		arr[now] += k;
		if (now+lowbit(now)<=MAXN) mdy(now+lowbit(now), k);
	}
} bit;

bool cmp(const pair <int, pair<int,int> > a, const pair <int, pair<int,int> > b) {
	if (a.ss.ff != b.ss.ff) return a.ss.ff < b.ss.ff;
	else return a.ss.ss < b.ss.ss;
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].ss.ff >> arr[i].ss.ss;
		arr[i].ff = i+1;
	}
	sort(arr, arr+n, cmp);
	for (int i = 0; i < n; i++) {
		bit.mdy(arr[i].ss.ss, 1);
		appr.insert({arr[i].ss.ss, arr[i].ff});
		int tmp = bit.qry(MAXN) - bit.qry(arr[i].ss.ff-1);
		while (tmp > k) {
			auto it = appr.end();
			it--;
			ans.pb(it->ss);
			bit.mdy(it->ff, -1);
			appr.erase(it);
			tmp--;
		}
	}
	cout << ans.size() << endl;
	for (int i = 0 ;i < ans.size(); i++) {
		cout << ans[i] << " \n"[i==ans.size()-1];
	}
	return 0;
}