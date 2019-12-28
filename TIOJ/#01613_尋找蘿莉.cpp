#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int n, a, b, ans;
priority_queue <int, vector<int>,greater<int>> pq;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
  	cin >> a;
  	pq.push(a);
  }
  while (pq.size() > 1) {
  	a = pq.top(), pq.pop();
  	b = pq.top(), pq.pop();
  	ans += a+b;
  	pq.push(a+b);
  }
  cout << ans << '\n';
}