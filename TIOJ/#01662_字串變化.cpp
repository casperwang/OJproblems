#include <bits/stdc++.h>
#define Hina ios_base::sync_with_stdio(0), cin.tie(0);
using namespace std;

string s, a;

signed main() {
    while (getline(cin, s)) {
        a = "";
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] >= 'A' && s[i] <= 'Z')
                a = a + (char)(s[i]-'A'+'a');
            else if (s[i] >= 'a' && s[i] <= 'z')
                a = a + (char)(s[i]-'a'+'A');
            else 
                a = a + ' ';
        }
        cout << a << endl;
    }
    return 0;
}