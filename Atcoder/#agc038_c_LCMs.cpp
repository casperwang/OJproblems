#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(false), cin.tie(0)
#define MAXC 1000000
#define MAXN 200000
#define int long long
#define pb push_back
using namespace std;

const int p = 998244353;
int n, a, ans, sum;
int num[MAXC+5];
int w[MAXC+5];
int inv[MAXC+5];

void init(){
    inv[0] = inv[1] = 1;
    for (int i = 2; i <= MAXC; i++) {
        inv[i] = ((p - p/i) * inv[p % i]) % p;
    }
}

int cal(int a) {
    int v = 0;
    for (int i = a; i <= MAXC; i += a)
        v = (v + num[i] * i) % p;
    return ((v * v) % p * w[a]) % p;
}

signed main() {
    Hina;
    init();
    for (int i = 1; i <= MAXC; i++) {
        w[i] = (w[i] + inv[i]) % p;
        for (int j = i+i; j <= MAXC; j+=i) {
            w[j] = (w[j] - w[i] + p) % p;
        }
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        num[a]++, sum = (sum + a) % p;
    }
    for (int i = 1; i <= MAXC; i++) {
        ans = (ans + cal(i)) % p;
    }
    cout << ((ans - sum + p) * inv[2]) % p << endl;
}