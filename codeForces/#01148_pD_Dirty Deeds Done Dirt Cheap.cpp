#include <bits/stdc++.h>
#define MAXN 300000
using namespace std;

struct num{
  int a, b;
};

int n;
num arr[MAXN+5];
map <int, int> inc, decr;

signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i].a >> arr[i].b;
    if (arr[i].a > arr[i].b) {
      decr[arr[i].b] = i;
    } else {
      inc[arr[i].a] = i;
    }
  }
  cout << max(decr.size(), inc.size()) << endl;
  if (decr.size() > inc.size()) {
    for (int i = 1; i <= n*2; i++) {
      if (decr[i]) cout << decr[i] << " "; 
    }
    cout << endl;
  } else {
    for (int i = n*2; i >= 1; i--) {
      if (inc[i]) cout << inc[i] << " "; 
    }
    cout << endl;
  }
  return 0;
}
