#include <iostream>
#include <stack>
#define N 200000
using namespace std;

int n, m, a, b;
int ancestor[N+5];
bool tf = 1;

void finding(int a) {
    stack <int> family;
    family.push(a);
    while (ancestor[family.top()] != family.top()) {
        family.push(ancestor[family.top()]);
    }
    int tmp = family.top();
    while (family.size()) {
        ancestor[family.top()] = tmp;
        family.pop();
    }
    return;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        ancestor[i] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        finding(a);
        finding(b);
        ancestor[ancestor[a]] = ancestor[b];
    }
    for (int i = 1; i <= n; i++) {
        finding(i);
        if (ancestor[i] != ancestor[1]) {
            cout << i << endl;
            tf = 0;
        }
    }
    if (tf) cout << "Connected" << endl;
    return 0;
}
