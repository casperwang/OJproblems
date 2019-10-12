#include <bits/stdc++.h>
#define pb push_back
#define MAXN 100000
using namespace std;

int n, k, ans;
int a, b;
bool vis[MAXN+5];
vector <int> path[MAXN+5];

int DFS(int now) {
    int tmp = 1;
    for (int i = 0; i < path[now].size(); i++) {
        if (!vis[path[now][i]]) {
            vis[path[now][i]] = 1;
            tmp += DFS(path[now][i]);
        }
    }
    return tmp;
}

signed main() {
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> a >> b;
        path[a].pb(b);
        path[b].pb(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            ans += DFS(i)-1;
        }
    }
    cout << k-ans << endl;
}