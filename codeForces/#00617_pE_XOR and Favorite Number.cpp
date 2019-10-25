#include <bits/stdc++.h>
#define MAXN 1048576
#define int long long
#define pb push_back
#define ff first
#define ss second
#define pip pair <int,pair<int,int> >
using namespace std;

int n, m, k;
int l, r, id, sum;
int arr[MAXN+5];
pip qry[MAXN+5];
int ans[MAXN+5];
int appr[MAXN+5];

bool cmp1 (const pip a, const pip b) {
	return a.ss.ff < b.ss.ff;
}
bool cmp2 (const pip a, const pip b) {
	return a.ss.ss < b.ss.ss;
}
bool cmp3 (const pip a, const pip b) {
	return a.ss.ss > b.ss.ss;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i], arr[i] ^= arr[i-1];
	for (int i = 0; i <  m; i++) {
		cin >> qry[i].ss.ff >> qry[i].ss.ss;
		qry[i].ff = i, qry[i].ss.ff--;
	}
	sort(qry, qry+m, cmp1);
	for (int i = 0; i*i <= m; i++) {
		if (i % 2)
			sort(qry+i*(int)sqrt(m), qry+min((i+1)*(int)sqrt(m), m), cmp2);
		else
			sort(qry+i*(int)sqrt(m), qry+min((i+1)*(int)sqrt(m), m), cmp3);
	}
	int nowL = 0, nowR = -1;
	for (int i = 0; i < m; i++) {
		id = qry[i].ff;
		l = qry[i].ss.ff, r = qry[i].ss.ss;
		//cout << l << " " << r << endl;
		while (nowL > l) {
			nowL--;
			sum += appr[arr[nowL]^k];
			appr[arr[nowL]]++;
		}
		while (nowR < r) {
			nowR++;
			sum += appr[arr[nowR]^k];
			appr[arr[nowR]]++;
		}
		while (nowL < l) {
			appr[arr[nowL]]--;
			sum -= appr[arr[nowL]^k];
			nowL++;
		}
		while (nowR > r) {
			appr[arr[nowR]]--;
			sum -= appr[arr[nowR]^k];
			nowR--;
		}
		ans[id] = sum;
	}
	//for (int i = 1; i <= n; i++) cout << arr[i] << " \n"[i==n];
	for (int i = 0; i < m; i++) cout << ans[i] << endl;
	return 0;
}