#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define int long long
#define min(a,b) a<b?a:b
using namespace std;

const int MAXN = 10000000;
const int INF = 1e18;
int t, n, k, l;
int ans;
int a[MAXN+1];
int pre[MAXN+1];
int suf[MAXN+1];

inline char readchar() {
    static const size_t bufsize = 65536;
    static char buf[bufsize];
    static char *p = buf, *end = buf;
    if (p == end) end = buf + fread_unlocked(buf, 1, bufsize, stdin), p = buf;
    return *p++;
}

inline void const Read(int & p) {
	p = 0;
	//int tmp = 0;
	char c = readchar();
	//tmp = !(c^'-');
	while (c < '0' || c > '9') {
		c = readchar();
	}
	while (c >= '0' && c <= '9')
		p = (p<<3)+(p<<1)+(c^48), c = readchar();
	//p = tmp?-p:p;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	Read(t);
	while (t--) {
		Read(n), Read(k), Read(l);
		for (register int i = 1; i <= n; i++)
			Read(a[i]);
		for (register int i = 1; i <= n; i++) {
			pre[i] = a[i] << 1;
			if (i-k >= 1) pre[i] += pre[i-k];
		}
		for (register int i = n; i >= 1; i--) {
			suf[i] = (l - a[i]) << 1;
			if (i+k <= n) suf[i] += suf[i+k];
		}
		ans = INF;
		for (register int i = 0; i <= n; i++)
			ans = min(ans, pre[i] + suf[i+1]);
		for (register int i = 1; i+k-1 <= n; i++)
			ans = min(ans, pre[i-1] + l + suf[i+k]);
		cout << ans << "\n";
	}
}