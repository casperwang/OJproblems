#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0), cin.tie(0)
#define pii pair<int,int>
#define gti greater< pii >
#define int long long
#define MAXN 1500000
#define ff first
#define ss second
using namespace std;

int n, Sa, Sb;
int mmax;
int a[MAXN+5], b[MAXN+5];
int pos[MAXN+5];
pair <int,int> ans[MAXN+5];
pair <int,int> A[MAXN+5], B[MAXN+5];
pair < pair<int,int>, int > appr[MAXN+5];

signed main() {
	Hina;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		appr[i] = {{a[i], b[i]}, i};
	}
	sort(appr, appr+n);
	for (int i = 0; i < n; i++) {
		pos[appr[i].ss] = i;
	}
	for (int i = 0; i < n; i++) {
		if (pos[i]-1 >= 0 && appr[pos[i]-1].ff == pii(a[i], b[i])) ans[i].ff = appr[pos[i]-1].ss;
		if (!(!Sa || a[i] >= A[0].ff))
			ans[i].ff = max(ans[i].ff, (int)A[lower_bound(A, A+Sa, pii(a[i],0), gti())-A-1].ss+1);
		if (!(!Sb || b[i] >= B[0].ff)) 
			ans[i].ff = max(ans[i].ff, (int)B[lower_bound(B, B+Sb, pii(b[i],0), gti())-B-1].ss+1);
		while (Sa > 0 && A[Sa-1].ff <= a[i]) Sa--;
		A[Sa++] = {a[i], i};
		while (Sb > 0 && B[Sb-1].ff <= b[i]) Sb--;
		B[Sb++] = {b[i], i};
		//cout << ans[i].ff << " \n"[i==n-1];
	}
	Sa = Sb = 0;
	for (int i = 0; i < n; i++) ans[i].ss = n-1;
	for (int i = n-1; i >= 0; i--) {
		if (pos[i]+1 < n && appr[pos[i]+1].ff == pii(a[i], b[i])) ans[i].ff = appr[pos[i]+1].ss;
		if (!(!Sa || a[i] >= A[0].ff))
			ans[i].ss = min(ans[i].ss, (int)A[lower_bound(A, A+Sa, pii(a[i],0), gti())-A-1].ss-1);
		if (!(!Sb || b[i] >= B[0].ff)) 
			ans[i].ss = min(ans[i].ss, (int)B[lower_bound(B, B+Sb, pii(b[i],0), gti())-B-1].ss+-1);
		while (Sa > 0 && A[Sa-1].ff <= a[i]) Sa--;
		A[Sa++] = {a[i], i};
		while (Sb > 0 && B[Sb-1].ff <= b[i]) Sb--;
		B[Sb++] = {b[i], i};
	}
	for (int i = 0; i < n; i++) {
		//cout << ans[i].ss << " \n"[i==n-1];
		mmax = max(ans[i].ss - ans[i].ff, mmax);
	}
	cout << mmax << endl;
	return 0;
}