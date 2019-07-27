#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k, p = 1;
int x = 0;
int m, nowM;
const int INF = 2147483648*2-1;
stack <int> K;
string op;
bool tf;

signed main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> op;
    if (op == "for") {
      cin >> k;
      if (p*k <= INF && m == nowM) {
        p *= k;
        K.push(k);
        m++;
      }
      nowM++;
    } else if (op == "add") {
      x += p;
      if (x > INF || nowM > m || p > INF) {
        tf = 1;
      }
    } else if (op == "end") {
      if (nowM == m) {
        p /= K.top();
        K.pop();
        m--;
      }
      nowM--;
    }
  }
  if (!tf) cout << x << endl;
  else cout << "OVERFLOW!!!" << endl;
  return 0;
}
