#include <bits/stdc++.h>
#define MAXN 500000
using namespace std;

int n, m, k;
int num[MAXN+5];
int dsu[MAXN+5];
int sze[MAXN+5];

int find(int a) {
  if (dsu[a] == a) return a;
  dsu[a] = find(dsu[a]);
  return dsu[a];
}

void Union(int a, int b) {
  int A = find(a), B = find(b);
  if (A != B) {
    dsu[A] = B;
    sze[B] += sze[A];
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    dsu[i] = i;
    sze[i] = 1;
  }
  for (int i = 0; i < m; i++) {
    cin >> k;
    for (int j = 0; j < k; j++) {
      cin >> num[j];
      if (j) Union(num[j-1], num[j]);
    }
  }
  for (int i = 1; i <= n; i++) {
    find(i);
    cout << sze[dsu[i]] << " ";
  }
  cout << endl;
}
