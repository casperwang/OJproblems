#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

const int MAXN = 1000;
int t, w, b, n, m;
bool tf;
pii a[MAXN+5];

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
	//ios_base::sync_with_stdio(0), cin.tie(0);
	Read(t);
	while (t--) {
		tf = 0;
		Read(w), Read(b), Read(n);
		for (int i = 0; i < n; i++)
			Read(a[i].ff), Read(a[i].ss);
		Read(m);
		for (int i = 0; i < n && !tf; i++) {
			if (w - (m+a[i].ff) * (b+a[i].ss-1)/a[i].ss > 0)
				tf = 1;
			for (int j = 0; j < n && !tf; j++) {
				if (i == j)
					continue;
				if (w - ((m+a[i].ff) * b/a[i].ss + (m+a[j].ff) * ((b%a[i].ss+a[j].ss-1)/a[j].ss)) > 0)
					tf = 1;
			}
		}
		if (tf) cout << "Yes\n";
		else cout << "No\n";
	}
}