#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
 
string s;
int len, d, cnt, v, t;
stack <int> arr;
 
signed main() {
	Hina;
	while (cin >> s) {
		d = cnt = v = 0;
		len = s.length();
		for (int i = 0; i < len; i++) {
			if (s[i] == '(') {
				if (arr.size()) t = arr.top(), arr.pop();
				else t = 0;
				t++;
				arr.push(t);
				arr.push(0);
			} else if (s[i] == '*') {
				cnt++;
				if (arr.size()) t = arr.top(), arr.pop();
				else t = 0;
				t++;
				arr.push(t);
			} else {
				v = max(v, arr.top());
				arr.pop();
			}
			d = max(d, (int)arr.size());
		}
		cout << cnt << " " << d << " " << v << endl;
	}
	return 0;
}