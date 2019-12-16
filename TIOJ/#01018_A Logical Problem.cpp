#include <bits/stdc++.h>
using namespace std;

int t, now, tf, k;
string s, p;
string ans[12];

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  stringstream tmp;
  cin >> t;
  getline(cin, s);
  for (int i = 0; i < t; i++) {
  	getline(cin, s);
  	now = tf = 0;
  	tmp.clear(), tmp << s;
  	for (int i = 0; i < 12; i++)
  		ans[i] = "";
  	ans[0] = "IF", ans[6] = "THEN";
  	ans[1] = ans[4] = ans[7] = ans[10] = "not";
  	while (true) {
  		tmp >> p;
  		if (tmp.fail()) break;
  		if (p == "IF") continue;
  		else if (p == "THEN") tf = 1, now = 0;
  		else if (p == "and") ans[6-tf*6+3] = "or", now = 1;
  		else if (p == "or") ans[6-tf*6+3] = "and", now = 1;
  		else if (p == "not") ans[6-tf*6+now*3+1] = "";
  		else ans[6-tf*6+now*3+2] = p;
  	}
  	for (int i = 0; i < 12; i++)
  		if (ans[i] == "not" && ans[i+1] == "") ans[i] = "";
  	for (int i = 0; i < 12; i++)
  		if (ans[i] != "") k = i;
  	for (int i = 0; i < 12; i++) {
  		if (ans[i] == "") continue;
  		cout << ans[i] << " \n"[i==k];
  	}
  }
}