#include <iostream>
#include <cstdio>
#include <map>
#define N 1000
using namespace std;

int n, m, a, b;
int path[N+5][N+5];

int main() {
    map <int, int> num;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if (num.count(a)) {
            a = num[a];
        } else {
            num[a] = num.size();
            a = num[a];
        }
        if (num.count(b)) {
            b = num[b];
        } else {
            num[b] = num.size();
            b = num[b];
        }
        if (path[a][b] || a == b) {
            cout << "Yes" << endl;
            return 0;
        }
        path[a][b] = 1;
        path[b][a] = 1;
    }
    cout << "yes" << endl;
    return 0;
}
