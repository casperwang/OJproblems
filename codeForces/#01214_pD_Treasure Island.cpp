#include <bits/stdc++.h>
#define MAXN 1000000
#define int long long
using namespace std;

int n, m, ans = 2;
string arr[MAXN+5];
vector <short> cnt[MAXN+5];
int p[MAXN+5];

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == '.')
        cnt[i].push_back((i?cnt[i-1][j]:0)+(j?cnt[i][j-1]:0));
      else 
        cnt[i].push_back(0);
      if (i == 0 && j == 0) cnt[0][0] = 1;
      cnt[i][j] = (cnt[i][j] > 0);
    }
  }
  for (int i = n-1; i >= 0; i--) {
    cnt[n-1][m-1] = 2;
    for (int j = m-1; j >= 0; j--) {
      if (arr[i][j] == '.' && cnt[i][j] == 1) {
        cnt[i][j] += (((i+1<n)?(cnt[i+1][j]>1):0)+((j+1<m)?(cnt[i][j+1]>1):0) > 0); 
      }
      if (cnt[i][j] == 2) p[i+j]++;
    }
  }
  for (int i = 1; i < m+n-2; i++) {
    if (p[i] == 0) {
      ans = 0;
      break;
    } else if (p[i] == 1) {
      ans = 1;
    }
  }
  cout << ans << endl;
} 

