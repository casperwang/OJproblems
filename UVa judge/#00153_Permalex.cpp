#include <bits/stdc++.h>
using namespace std;
string a;
long long int abc[26], num[30], ans, n;
int main(){
  while (cin >> a) {
    __int128 sum;
    if (a == "#") return 0;
    n = a.length();
    ans = 0;
    for (int i = 0; i < n; i++) {
      abc[a[i]-'a']++;
    }
    for (int i = 0; i < n; i++) {
      abc[a[i]-'a']--;
      for (int p = 0; p < a[i]-'a'; p++) {
        if (!abc[p]) continue;
        abc[p]--;
        abc[a[i]-'a']++;
        sum = 1;
        for (int j = 2; j < n-i; j++) sum *= j;
        for (int j = 0; j < 26; j++) {
          if (abc[j] > 1) {
            for (int k = abc[j]; k > 1; k--) sum /= k;
          }
        }
        ans += (long long int)sum;
        abc[a[i]-'a']--;
        abc[p]++;
      }
    }
    for (int i = 1; i < 10-log10(ans+1); i++) {
      cout << " ";
    }
    cout << ans+1 << endl;
  }
	return 0;
}
