#include <bits/stdc++.h>
#define MAXN 1048576+5
using namespace std;

long long int n, a, s, ans;
long long int arr[2][MAXN];

int main(){
  cin >> n;
  arr[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    s ^= a;
    ans += arr[i%2][s];
    arr[i%2][s]++;
  }
  cout << ans << endl;
	return 0;
}
