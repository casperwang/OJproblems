#include <bits/stdc++.h>
#define MAXN 1000
#define int long long
#define pb push_back
using namespace std;

string s1, s2;
int n;
vector <int> dif1, dif2;

signed main() {
  cin >> n;
  cin >> s1 >> s2;
  for (int i = 0; i < n; i++) {
  	if (s1[i] == 'a' && s2[i] == 'b') dif1.pb(i+1);
  	if (s1[i] == 'b' && s2[i] == 'a') dif2.pb(i+1);
  }
  if ((dif1.size() + dif2.size()) % 2 == 1) {
  	cout << -1 << endl;
  } else {
  	cout << (dif1.size()+dif2.size())/2 + dif1.size()%2 << endl;
  	for (int i = 0; i < dif1.size()/2; i++) {
  		cout << dif1[i*2] << " " << dif1[i*2+1] << endl;
  	}
  	for (int i = 0; i < dif2.size()/2; i++) {
  		cout << dif2[i*2] << " " << dif2[i*2+1] << endl;
  	}
  	if (dif1.size()%2) {
  		cout << dif1[dif1.size()-1] << " " << dif1[dif1.size()-1] << endl;
  		cout << dif1[dif1.size()-1] << " " << dif2[dif2.size()-1] << endl;
  	}
  }
  return 0;
}