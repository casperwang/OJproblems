#include<bits/stdc++.h>
#define int long long
#define MAXN 100000
#define INF 18446744073709551615
using namespace std;

int n, ans;
int arr[MAXN+5];

signed main(){
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    if (i == 1) {
      ans += (arr[i])*(n-arr[i]+1);
      continue;
    }
    if (arr[i] > arr[i-1]) ans += (arr[i]-arr[i-1])*(n-arr[i]+1);
    else ans += (arr[i])*(arr[i-1]-arr[i]);
  }
  cout << ans << endl;
}
