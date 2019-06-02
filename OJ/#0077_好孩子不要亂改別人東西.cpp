#include <bits/stdc++.h>
#define MAXN 300000
using namespace std;

int N, op[MAXN+5], x[MAXN+5], y[MAXN+5], sze;
map <int, int> appr;

class BIT{
  public:
  int bit[MAXN*2+5];
  int lowbit(int n) {
    return n&-n;
  }
  void add(int now) {
    bit[now] += 1;
    if (now+lowbit(now) <= MAXN*2) add(now+lowbit(now));
  }
  int sum(int now) {
    return now ? sum(now-lowbit(now)) + bit[now] : 0;
  }
} X, Y;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> op[i] >> x[i] >> y[i];
    appr[x[i]] = 1;
    appr[y[i]] = 1;
  }
  int j = 0;
  for (auto i : appr) {
    appr[i.first] = ++j;
  }
  for (int i = 0; i < N; i++) {
    if (op[i] == 1) {
      sze++;
      X.add(appr[x[i]]);
      Y.add(appr[y[i]]);
    } else {
      cout << sze-X.sum(appr[x[i]])-Y.sum(appr[y[i]]) << endl;
    }
  }
}
