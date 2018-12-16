#include <iostream>
#include <cstdio>
#include <vector>
#define N 300000
using namespace std;

int t, n, m, a, b;
long long int ans;
vector <int> path[N+5];
bool visited[N+5];
int vertices[N+5];
long long int tmp_0[N+5], tmp_1[N+5];
bool tf;

void checking(int now, int counter) {
    visited[now] = 1;
    for (int i = 0; i < path[now].size(); i++) {
        if (!visited[path[now][i]]) {
            vertices[path[now][i]] = (vertices[now]+1)%2+counter;
            checking(path[now][i], counter);
        } else if (vertices[path[now][i]] == vertices[now]) {
            tf = 0;
            return;
        }
    }
    if (path[now].size() == 0) vertices[now] = -1;
    return;
}

int main() {
    scanf("%d",&t);
    for (int  i = 0; i < t; i++) {
        scanf("%d%d",&n,&m);
        tf = 1;
        ans = 0;
        for (int i = 1; i <= n; i++) {
            path[i].clear();
            visited[i] = 0;
            vertices[i] = -1;
        }
        for (int i = 0; i < m; i++) {
            scanf("%d%d",&a,&b);
            path[a].push_back(b);
            path[b].push_back(a);
        }
        int counter = 0;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                vertices[i] = counter;
                checking(i, counter);
                if (vertices[i] != -1) counter += 2;
            }
        }
        if (tf) {
            ans = 1;
            for (int i = 0; i < counter; i+=2) {
                tmp_0[i/2] = 1;
                tmp_1[i/2] = 1;
            }
            for (int i = 1; i <= n; i++) {
                if (vertices[i] % 2 == 0) tmp_0[vertices[i]/2] = (tmp_0[vertices[i]/2] * 2) % 998244353;
                if (vertices[i] % 2 == 1) tmp_1[vertices[i]/2] = (tmp_1[vertices[i]/2] * 2) % 998244353;
            }
            for (int i = 0; i < counter; i+=2) {
                ans = (ans * (tmp_0[i/2] + tmp_1[i/2])) % 998244353;
            }
            for (int i = 1; i <= n; i++) {
                if (vertices[i] == -1) ans = (ans * 3) % 998244353;
            }
            cout << ans << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}
