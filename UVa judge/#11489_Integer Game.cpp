#include <bits/stdc++.h>
using namespace std;
int n, a[3], k;
string s;
int main() {
  scanf("%d",&n);
  for (int i = 0; i < n; i++) {
  	k = a[0] = a[1] = a[2] = 0;
  	cin >> s;
  	for (int j = 0; j < s.length(); j++) {
  	  k += s[j]-'0';
  	  a[(s[j]-'0')%3]++;
	}
	if (k % 3 == 1 && a[1]) a[0]++;
	if (k % 3 == 2 && a[2]) a[0]++;
	if (a[0] % 2 == 0) cout << "Case " <<  i+1 << ": T" << endl;
	else cout << "Case " <<  i+1 << ": S" << endl; 
  }
  return 0;
}
