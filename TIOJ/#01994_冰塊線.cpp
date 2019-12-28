#include <bits/stdc++.h>
#define pb push_back
using namespace std;

vector<vector<int>> f(int n) {
	vector<vector<int>> t, s;
	if (n == 0) {
		s.pb(vector<int>(1));
		return s;
	}
	s = f(n-1);
	t.resize(1<<n);
	for (int i = 0; i < t.size(); i++) {
		t[i].resize(1<<n);
	}
	int k = (1<<(n-1));
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++)
			t[i][j] = s[j][i];
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++)
			t[i+k][j] = s[i][j]+k*k;
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++)
			t[i+k][j+k] = s[i][j]+2*k*k;
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++)
			t[i][j+k] = s[k-1-j][k-1-i]+3*k*k;
	return t;
}

int n;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  vector <vector<int>> ans = f(n);
  for (int i = 0; i < (1<<n); i++) {
  	for (int j = 0; j < (1<<n); j++) {
  		cout << ans[i][j] << " \n"[j==(1<<n)-1];
  	}
  }
}