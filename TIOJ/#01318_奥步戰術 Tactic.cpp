#include <bits/stdc++.h>
#pragma ("Ofast")
#define MAXN 100000
#define pb push_back
#define pii pair<int,int>
#define ff first
#define ss second
#define int long long
using namespace std;

int n, t, ans;
int h, c;
int now, tmp, k, mmax, L;
int Ta[MAXN*2+5];
int minR[MAXN+5];
vector <pii> b;

bool cmp(const pii a, const pii b) {
	if (a.ss != b.ss) return a.ss < b.ss;
	return a.ff > b.ff;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> t;
	b.reserve(n);
	for (int i = 0; i < n; i++) {
		cin >> h >> c;
		if (h-c >= c) Ta[now++]=h-c, Ta[now++]=c;
		else b.pb(pii(c, h));
	}
	sort(Ta, Ta+now);
	for (int i = 1; i < now; i++)
		Ta[i] += Ta[i-1];
	//for (int i = 0; i < now; i++) 
	//	cout << Ta[i] << " \n"[i==now-1];
	ans = upper_bound(Ta, Ta+now, t) - Ta;
	sort(b.begin(), b.end(), cmp);
	minR[b.size()] = MAXN*10;
	for (int i = b.size()-1; i >= 0; i--)
		minR[i] = min(b[i].ff, minR[i+1]);
	for (pii i : b) {
		//cout << i.ff << " " << i.ss << " ";
		tmp = t - minR[k>>1];
		//cout << tmp << " ";
		if (tmp >= 0)
			ans = max(ans, (int)(upper_bound(Ta, Ta+now, tmp) - Ta) + k+1);
		t -= i.ss, k += 2;
		//cout << t << " ";
		if (t >= 0)
			ans = max(ans, (int)(upper_bound(Ta, Ta+now, t) - Ta) + k);
		mmax = max(mmax, i.ss-i.ff);
		tmp = t + mmax;
		//cout << tmp << "\n";
		if (tmp >= 0)
			ans = max(ans, (int)(upper_bound(Ta, Ta+now, tmp) - Ta) + k-1);
		else break;
	}
	cout << ans << '\n';
}