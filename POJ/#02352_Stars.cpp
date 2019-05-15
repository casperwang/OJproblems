#include <iostream>
#define MAXN 15000
#define MAXM 32000
using namespace std;

int n;
int ans[MAXN+5];
pair <int, int> pos[MAXN+5];
int bit[MAXM+5];

inline int lowbit(int k) {
  return k & -k;
}

void add(int a) {
  bit[a] += 1;
  if (a+lowbit(a) <= MAXM) add(a+lowbit(a));
}

int sum(int n) {
  return n ? bit[n] + sum(n-lowbit(n)) : 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> pos[i].first >> pos[i].second;
    ans[sum(pos[i].first+1)]++;
    add(pos[i].first+1);
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << endl;
  }
}
