#include <bits/stdc++.h>
#define pb push_back
#define MAXN 100000
using namespace std;

int n;
string a, b, ans;

signed main() {
    cin >> n;
    cin >> a >> b;
    if (a[0] == b[0] && a[0] != a[1] && b[0] != b[1]) {
        for (int i = 0; i < n; i++) {
            if (a[0] != 'a') ans += 'a';
            if (a[0] != 'b') ans += 'b';
            if (a[0] != 'c') ans += 'c';
        }
        for (int i = 0; i < n; i++) {
            ans += a[0];
        }
    } else if (a[1] == b[1] && a[0] != a[1] && b[0] != b[1]) {
        for (int i = 0; i < n; i++) {
            ans += a[1];
        }
        for (int i = 0; i < n; i++) {
            if (a[1] != 'a') ans += 'a';
            if (a[1] != 'b') ans += 'b';
            if (a[1] != 'c') ans += 'c';
        }
    } else if (a[0] == b[1] && b[0] == a[1] && a[0] != a[1] && b[0] != b[1]) {
        for (int i = 0; i < n; i++) {
            ans += a[0];
        }
        for (int i = 0; i < n; i++) {
            if (a[0]!='a'&&a[1]!='a') ans += 'a';
            if (a[0]!='b'&&a[1]!='b') ans += 'b';
            if (a[0]!='c'&&a[1]!='c') ans += 'c';
        }
        for (int i = 0; i < n; i++) {
            ans += a[1];
        }
    } else {
        if (a=="ab"||b=="ab"||a=="bc"||b=="bc"||a=="ca"||b=="ca") {
            for (int i = 0; i < n; i++) {
                ans += "cba";
            }
        } else {
            for (int i = 0; i < n; i++) {
                ans += "abc";
            }
        }
    }
    cout << "YES" << endl << ans << endl;
}