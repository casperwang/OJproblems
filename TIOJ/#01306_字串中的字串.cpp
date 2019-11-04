#include <bits/stdc++.h>
#define MAXN 10000
using namespace std;

int f[MAXN+5];
string P, T;
int t, n;
int lenA, lenB;

int KMP(string a, string b) {
	lenA = a.length(), lenB = b.length();
	int sum = 0;
  f[0] = -1, f[1] = 0;
  for (int i = 1, j = 0; i < lenB-1; f[++i] = ++j) {
  	if (b[i] == b[j]) f[i] = f[j];
    while (j >= 0 && b[i] != b[j]) j = f[j];
  }
  for (int i = 0, j = 0; i - j + lenB <= lenA; i++, j++) {
  	while (j >= 0 && b[j] != a[i]) j = f[j];
	  if (j == lenB-1) sum++, j = f[j]-1, i--;
  }
  return sum;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> T >> n;
		for (int j = 0; j < n; j++) {
			cin >> P;
			cout << KMP(T, P) << "\n";
		}
	}
}