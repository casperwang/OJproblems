//Dominos 2: DFS
#include <iostream>
#include <cstdio>
#include <vector>
#define N 50000
using namespace std;

int T, n, m, l;
int a, b, p; // a->b, ->p
int ans;
vector <int> path[N+5];
bool visited[N+5];

void DFS(int p) {
    ans++;
    visited[p] = 1;
    for (int i = 0; i < path[p].size(); i++) {
        if (!visited[path[p][i]]) DFS(path[p][i]);
    }
}

int main() {
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        ans = 0;
        scanf("%d%d%d", &n, &m, &l);
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) path[j].clear();
            visited[j] = 0;
        }
        for (int j = 0; j < m; j++) {
            scanf("%d%d", &a, &b);
            path[a].push_back(b);
        }
        for (int j = 0; j < l; j++) {
            scanf("%d", &p);
            if (!visited[p]) DFS(p);
        }
        printf("%d\n", ans);
    }
    return 0;
}
