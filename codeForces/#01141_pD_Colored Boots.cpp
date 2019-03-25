#include <bits/stdc++.h>
using namespace std;

int n, ans;
string a, b;
vector <int> appr[27], bppr[27];

int main() {
  cin >> n >> a >> b;
  for (int i = 0; i < n; i++) {
    if (a[i] != '?') appr[a[i]-'a'].push_back(i);
    else appr[26].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    if (b[i] != '?') bppr[b[i]-'a'].push_back(i);
    else bppr[26].push_back(i);
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < min(appr[i].size(), bppr[i].size()); j++) {
      ans++; 
    }
  }
  for (int j = 0; j < appr[26].size() + bppr[26].size(); j++) {
    ans++; 
  }
  ans = min(ans, n);
  cout << ans << endl;
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < min(appr[i].size(), bppr[i].size()); j++) {
      cout << appr[i][j]+1 << " " << bppr[i][j]+1 << endl;
      a[appr[i][j]] = '.';
      b[bppr[i][j]] = '.';
    }
  }
  for (int i = 0, j = 0; i < n && j < bppr[26].size(); i++) {
    if (a[i] != '?' && a[i] != '.') {
      cout << i+1 << " " << bppr[26][j]+1 << endl;
      a[i] = '.';
      b[bppr[26][j]] = '.';
      j++;
    }
  }
  for (int i = 0, j = 0; i < n && j < appr[26].size(); i++) {
    if (b[i] != '.') {
      cout << appr[26][j]+1 << " " << i+1 << endl;
      j++;
    }
  }
  return 0;
}
