#include <bits/stdc++.h>
#define MAXN 150000
using namespace std;

int n;
int a, b;
pair <int, int> pos[MAXN+5];

class DSU{
  public:
    int dsu[MAXN+5];
    int find(int a) {
      if (dsu[a] == a) return a;
      return dsu[a] = find(dsu[a]);
    }
} L, R;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    L.dsu[i] = i;
    R.dsu[i] = i;
  } 
  for (int i = 0; i+1 < n; i++) {
    cin >> a >> b;
    pos[R.find(a)].second = L.find(b);
    pos[L.find(b)].first  = R.find(a);
    L.dsu[L.find(b)] = L.dsu[R.find(b)] = L.find(a);
    R.dsu[L.find(a)] = R.dsu[R.find(a)] = R.find(b);
  }
  for (int i = 1; i <= n; i++) {
    if (pos[i].first == 0) {
      int k = i;
      for (int j = 0; j < n; j++) {
        cout << k << " ";
        k = pos[k].second;
      }
      cout << endl;
      return 0;
    }
  }
}
