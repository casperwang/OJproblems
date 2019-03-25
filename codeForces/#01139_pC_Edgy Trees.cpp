#include <bits/stdc++.h>
#define MAXN 200000
#define MOD 1000000007
using namespace std;

int n, k, a, b, x;
long long int ans, tmp, m;
int v[MAXN], size[MAXN];
stack <int> arr;

void Find(int a) {
	arr.push(a);
	while (v[arr.top()] != arr.top()) {
		arr.push(v[arr.top()]);
	}
	int tmp = arr.top();
	while (arr.size()) {
		v[arr.top()] = tmp;
		arr.pop();
	}
}

void Union(int a, int b) {
  Find(a), Find(b);
  size[v[b]] += size[v[a]];
  v[v[a]] = v[b];
}


int main() {
  cin >> n >> k;
  ans = 1, tmp = n;
  for (int j = 1; j <= k; j *= 2) {
    if (j & k) ans = (ans * tmp) % MOD;
    tmp = (tmp * tmp) % MOD;
  }
  for (int i = 1; i <= n; i++) {
    v[i] = i;
    size[i] = 1;
  }
  for (int i = 1; i < n; i++) {
    cin >> a >> b >> x;
    if (x == 0) Union(a, b);
  }
  for (int i = 1; i <= n; i++) {
    if (v[i] == i) {
      m = 1, tmp = size[i];
      for (int j = 1; j <= k; j *= 2) {
        if (j & k) m = (m * tmp) % MOD;
        tmp = (tmp * tmp) % MOD;
      }
      ans = (ans - m + MOD) % MOD;
    }
  }
  cout << ans << endl;
  return 0;
}
