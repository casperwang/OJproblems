#include <bits/stdc++.h>
#define MAXN 100000+5
using namespace std;

long long int n, num[MAXN], mex[MAXN], pos[MAXN];
long long int SG[MAXN];
string ans;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
    pos[num[i]] = i;
  }
  for (int i = n; i > 0; i--) {
    for (int j = i; pos[i]+j <= n; j += i) {
      if (num[pos[i]+j] > i) mex[SG[pos[i]+j]] = i;
    }
    for (int j = i; pos[i]-j > 0; j += i) {
      if (num[pos[i]-j] > i) mex[SG[pos[i]-j]] = i;
    }
    int j;
    for (j = 0; mex[j] == i; j++) {}
    SG[pos[i]] = j;
  }
  for (int i = 1; i <= n; i++) {
    if (SG[i]) ans += 'A';
    else ans += 'B';
  }
  cout << ans << endl;
  return 0;
}
