#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(false), cin.tie(0)
#define MAXN 100000
#define pb push_back
#define int long long
using namespace std;
 
int n, m, q, k;
int a, b, c;
int dsu[MAXN+5];
bool tf = 1, p;
vector < pair<int,int> > arr;
 
int finding(int a) {
    return a == dsu[a] ? a : dsu[a] = finding(dsu[a]);
    if (dsu[a] != a) dsu[a] = finding(dsu[a]);
    return dsu[a];
}
 
signed main() {
    Hina;
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) dsu[i] = i;
    k = n;
    for (int i = 0; i < q; i++) {
        cin >> a >> b >> c;
        if (finding(a) != finding(b) && c == 0) {
            dsu[finding(a)] = finding(dsu[b]);
            k--;
        } else if (c) {
            arr.pb({a, b});
        }
        if (c) p = 1;
    }
    for (int i = 0; i < arr.size(); i++) {
        if (finding(arr[i].first) == finding(arr[i].second)) {
            tf = 0;
        }
    }
    if (m > n-k + k*(k-1)/2/* || (k<=2 && p)*/ || (m==n-1 && p)) tf = 0;
    if (tf) cout << "Yes" << endl;
    else cout << "No" << endl;
}