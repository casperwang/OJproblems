#include <bits/stdc++.h>
#define Hinaamano ios_base::sync_with_stdio(false),cin.tie(0)
#define int long long
#define MOD 1000000007
#define MAXN 1000
using namespace std;
 
int h, w, a, ans;
int W[MAXN+5], H[MAXN+5];
bool arr[MAXN+5][MAXN+5], narr[MAXN+5][MAXN+5];
bool tf = 1;
 
signed main() {
    Hinaamano;
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        cin >> a;
        W[i] = a;
        for (int j = 0; j < a; j++) arr[i][j] = 1;
    }
    for (int i = 0; i < w; i++) {
        cin >> a;
        H[i] = a;
        if (!a && arr[0][i] == 1) tf = 0;
        for (int j = 0; j < a; j++) {
            if (arr[j][i] == 0 && (!i || arr[j][i-1])) {
                tf = 0;
            }
            narr[j][i] = 1;
        if (a < h && arr[a][i] == 1) tf = 0;
        }
    }
    ans = 1;
    for (int i = 0; i < h; i++) {
        for (int j = W[i]+1; j < w; j++) {
            if (i > H[j]) {
                ans = (ans*2)%MOD;
            }
        }
    }
    if (!tf) {
        cout << 0 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}