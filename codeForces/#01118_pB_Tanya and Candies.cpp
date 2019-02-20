#include <bits/stdc++.h>
#define MAXN 200000+10
using namespace std;
long long int n, ans;
long long int num[MAXN];
long long int pre[MAXN];
long long int suf[MAXN];
int main(){
  cin >> n;
  for (int i = 2; i <= n+1; i++) {
    cin >> num[i];
    pre[i] = num[i];
    pre[i] += pre[i-2];
  }
  for (int i = n+1; i >= 2; i--) {
    suf[i] = num[i];
    suf[i] += suf[i+2];
  }
  for (int i = 2; i <= n+1; i++) {
    if (pre[i-1] + suf[i+2] == pre[i-2] + suf[i+1]) ans++;
  }
  cout << ans << endl;
	return 0;
}
