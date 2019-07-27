#include <bits/stdc++.h>
#define int long long
#define MAXN 2000
#define MAXM 1000000
#define MOD 998244353
using namespace std;

int n, m;
int num[MAXM+5];
int dp[MAXN+5][MAXN+5];
int mmin[MAXN+5], mmax[MAXN+5];
vector <int> arr;

int f(int l, int r) {
  if (l > r) return 1;
  if (l == r && mmin[arr[l]] == mmax[arr[l]]) return 1;
  else if (l == r) return 0;
  if (dp[l][r]) return dp[l][r];
  int m = MAXN;
  for (int i = l; i <= r; i++) {
    if (mmin[arr[i]] < l || mmax[arr[i]] > r) return 0;
    if (arr[i] < m) {
      m = arr[i];
    }
  }
  int L = f(l, mmin[m]-1);
  for (int i = l; i < mmin[m]; i++) {
    L += f(l, i) * f(i+1, mmin[m]-1);
    L %= MOD; 
  }
  int R = f(mmax[m]+1, r);
  for (int i = mmax[m]+1; i <= r; i++) {
    R += f(mmax[m]+1, i) * f(i+1, r);
    R %= MOD;
  }
  int sum = (L*R)%MOD;
  int p = mmin[m]+1;
  for (int i = mmin[m]+1; i <= mmax[m]; i++) {
    if (arr[i] == m) {
      sum *= f(p, i-1);
      sum %= MOD;
      p = i+1;
    }
  }
  dp[l][r] = sum;
  return sum;
}
signed main() {
  cin >> n >> m;
  arr.push_back(-1);
  for (int i = 1; i <= m; i++) {
    cin >> num[i];
    if (num[i] != num[i-1]) arr.push_back(num[i]);
    if (arr.size() > 2*n+2) {
      cout << 0 << endl;
      return 0;
    }
  }
  for (int i = 1; i < arr.size(); i++) {
    //cout << arr[i] << " ";
    if (!mmin[arr[i]]) mmin[arr[i]] = i;
    mmax[arr[i]] = i;
  }
  //cout << endl;
  cout << f(1, arr.size()-1) << endl;
  return 0;
}
