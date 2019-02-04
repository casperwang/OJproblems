#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 1000
using namespace std;

int t;
string s;

int main() {
    scanf("%d",&t);
    for (int i = 0; i < t; i++) {
        cin >> s;
        sort(s.begin(), s.end());
        if (s[0] == s[s.length()-1]) cout << -1 << endl;
        else cout << s << endl;
    }
    return 0;
}
