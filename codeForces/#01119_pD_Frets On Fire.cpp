#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;

int n, q, p;
long long int a, b;
long long int num[MAXN+5];
long long int dis[MAXN+5];
long long int pre[MAXN+5];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num[i];
  }
  sort(num, num+n);
  p = n;
  for (int i = 0; i < n; i++) {
    if (i) dis[i] = num[i] - num[i-1] - 1;
  }
  sort(dis+1, dis+n);
  for (int i = 1; i < n; i++) {
    pre[i] = pre[i-1] + dis[i];
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> a >> b;
    cout << (b - a)*(n-(upper_bound(dis+1, dis+n, b-a)-1-dis)) + pre[upper_bound(dis+1, dis+n, b-a)-1-dis] + n << " ";
  }
  cout << endl;
  return 0;
} 
