#include <bits/stdc++.h>
using namespace std;

string s;
int a, ans;

signed main() {
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') a++;
        else if (a) a--, ans++;
    }
    cout << ans*2 << endl;
}