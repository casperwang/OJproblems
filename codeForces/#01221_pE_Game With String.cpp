#include <bits/stdc++.h>
#define MAXN 300000
#define int long long
using namespace std;

int q, a, b;
int f, k, p, m;
bool tf;
string s;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> q;
  for (int i = 0; i < q; i++) {
  	k = p = m = 0;
  	tf = 1;
  	cin >> a >> b >> s;
  	s = s + 'X';
  	for (int j = 0; j < s.length(); j++) {
  		if (s[j] == '.' && (!j || s[j-1] == 'X')) f = j;
  		if (s[j] == 'X' && ( j && s[j-1] == '.')) {
  			if (j-f >= 2*b) p++, k++, m=max(m,j-f);
  			else if (j-f >= a) k++;
  			else if (j-f >= b) tf = 0;
  		}
  	}
  	if (p >= 2) tf = 0;
  	if (p == 1) {
  	  if (m-a > 2*b-1+2*b-1) tf = 0;
  	  else if (m-a >= 2*a) {
  	  	if (k%2==0 && m-a <= 2*b-1+b-1 && a<2*b) k++;
  	  	else if (k%2 && m-a <= 2*b-1+2*b-1 && a<2*b) k+=2;
  	  	else tf = 0;
  	  } else if (m-a >= a) {
  	  	if (k%2==0 && m-a <= 2*b-1+b-1 && a<2*b) k++;
  	  	else if (k%2 && m-a <= b-1+b-1) k+=0;
  	  	else tf = 0;
  	  } else if (m-a < a && m-a > b-1+b-1) tf = 0;
  	  if (m < a) tf = 0;
  	}
  	//cout << tf << " " << k << endl;
  	if (tf && k%2) cout << "YES" << endl;
  	else cout << "NO" << endl;
  }
  return 0;
}