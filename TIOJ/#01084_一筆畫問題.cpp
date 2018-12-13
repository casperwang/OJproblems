#include <iostream>
#include <stack>
#define N 1024
using namespace std;

int m, a, b;
int path[N+5][N+5];
int appr[N+5];
stack <int> ans;
stack <int> tmp;

void run(int a) {
    for (int i = 1; i <= N; i++) {
        if (path[a][i] > 0) {
            ans.push(i);
            path[a][i]--;
            path[i][a]--;
            run(i);
            return;
        }
    }
    tmp.push(a);
    ans.pop();
    if (ans.size()) run(ans.top());
    return;
}

int main() {
    while (cin >> m) {
        if (!m) return 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                path[i][j] = 0;
            }
            appr[i] = 0;
        }
        while (ans.size()) ans.pop();
        while (tmp.size()) tmp.pop();
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            path[a][b]++;
            path[b][a]++;
            appr[a]++;
            appr[b]++;
        }
        for (int i = 1; i <= N; i++) {
            if (appr[i] % 2) {
                ans.push(i);
                run(i);
                break;
            }
        }
        if (!tmp.size()) {
            for (int i = 1; i <= N; i++) {
                if (appr[i]) {
                    ans.push(i);
                    run(i);
                    break;
                }
            }
        }
        while (tmp.size()) {
            cout << tmp.top() << endl;
            tmp.pop();
        }
        cout << endl;
    }
    return 0;
}
