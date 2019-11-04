#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0), cin.tie(0)
#define int long long
#define MAXN 100000
#define pb push_back
using namespace std;

struct pts{
	int x, y;
	bool operator < (pts a) {
		if (x != a.x) return x < a.x;
		return y < a.y;
	}
	bool operator == (pts a){
		return x == a.x && y == a.y;
	}
	pts(int x, int y): x(x), y(y){}
	pts() {}
};

int cross(pts o, pts a, pts b) {
	return (a.x-o.x)*(b.y-o.y) - (a.y-o.y)*(b.x-o.x);
}

int n, now, ans;
int x, y;
pts arr[MAXN+5];
pts ucon[MAXN+5], dcon[MAXN+5];

signed main() {
	//Hina;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		arr[i] = pts(x, y);
	}
	sort(arr, arr+n);
	now = 0;
	for (int i = 0; i < n; i++) {
		while (now >= 2 && cross(ucon[now-2], ucon[now-1], arr[i]) < 0)
			now--;
		ucon[now++] = arr[i];
	}
	ans = now;
	now = 0;
	for (int i = 0; i < n; i++) {
		while (now >= 2 && cross(dcon[now-2], dcon[now-1], arr[i]) > 0)
			now--;
		dcon[now++] = arr[i];
	}
	ans += now;
	cout << ans-2 << endl;
	return 0;
}