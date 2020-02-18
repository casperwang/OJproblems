#include <bits/stdc++.h>
using namespace std;

int n, cnt;

void print(int now, int s, int t) {
	if (now == 1) {
		if ((s^t) == 2) {
			cout << "#" << ++cnt << " : move the dish from #" << s << " to #" << 2 << "\n";
			cout << "#" << ++cnt << " : move the dish from #" << 2 << " to #" << t << "\n";
		} else {
		 	cout << "#" << ++cnt << " : move the dish from #" << s << " to #" << t << "\n";
		}
		return;
	}
	if ((s^t) == 2) {
		print(now-1, s, 2);
		print(now-1, 2, t);
		cout << "#" << ++cnt << " : move the dish from #" << s << " to #" << 2 << "\n";
		print(now-1, t, 2);
		print(now-1, 2, s);
		cout << "#" << ++cnt << " : move the dish from #" << 2 << " to #" << t << "\n";
		print(now-1, s, 2);
		print(now-1, 2, t);
	} else {
		print(now-1, s, s^t);
	 	cout << "#" << ++cnt << " : move the dish from #" << s << " to #" << t << "\n";
		print(now-1, s^t, t);
	}
}

signed main() {
	//ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	print(n, 1, 3);
}