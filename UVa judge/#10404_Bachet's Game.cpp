#include <bits/stdc++.h>
#define MAXN 1000000+5 
using namespace std;
int n, a, item[10];
bool dp[MAXN];
int main() {
  while (cin >> n) {
  	cin >> a;
  	for (int i = 0; i < a; i++) {
  		cin >> item[i];
  		dp[item[i]] = 0;
	}
	for (int i = 1; i <= n; i++) {
		dp[i] = 0;
		for (int j = 0; j < a; j++) {
			if (i >= item[j]) dp[i] = max(!dp[i-item[j]], dp[i]);
		}
	}
	if (dp[n]) cout << "Stan wins" << endl;
	else cout << "Ollie wins" << endl;
  }
  return 0;
}
