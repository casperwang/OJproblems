#include <bits/stdc++.h>
using namespace std;

string n;
long long int p[11];

long long int DFS(int now) {
  if (now == n.length()) return 1;
  return max((n[now]-'0') * DFS(now+1), max((n[now]-'1'), (int)(now == 0)) * p[n.length()-now-1]);
}

int main() {
  p[0] = 1;
  for (int i = 1; i <= 10; i++) {
    p[i] = p[i-1] * 9;
  }
  cin >> n;
  cout << DFS(0) << endl;
}
