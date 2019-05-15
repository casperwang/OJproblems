#include <bits/stdc++.h>
#define ll long long int
#define MAXN 200000
using namespace std;

ll n, k, x, m;
ll num[MAXN+5];
ll neg[MAXN+5];
priority_queue <pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> now; 

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k >> x;
  for (int i = 0; i < n; i++) {
    cin >> num[i];
    if (num[i] < 0) {
      neg[i] = -1;
      now.push({-num[i], i});
      m++;
    } else {
      neg[i] = 1;
      now.push({num[i], i});
    }
  }
  if (m % 2 == 0) {
    pair <ll, int> p = now.top();
    now.pop();
    while (k && p.first >= 0) {
      p.first -= x;
      k--;
    }
    if (p.first < 0) {
      p.first = -p.first;
      neg[p.second] = -neg[p.second];
    }
    now.push(p);
  }
  while (k) {
    pair <ll, int> p = now.top();
    now.pop();
    p.first += x;
    now.push(p);
    k--;
  }
  while (now.size()) {
    num[now.top().second] = now.top().first;
    now.pop();
  }
  for (int i = 0; i < n; i++) {
    if (neg[i] == -1 && num[i] != 0) cout << '-';
    cout << num[i] << " ";
  }
  cout << endl;
}
