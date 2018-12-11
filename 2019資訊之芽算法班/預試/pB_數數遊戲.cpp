#include <iostream>
using namespace std;

int t, n, m, p;
string s;
bool A[26] = {1,1,0,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0};

bool next_char(char a, int c, int i) {
    if (A[a+1-'a']) c--;
    if (i >= c && c >= 0 && (char)(a+1) != 'g') {
        p = c;
        return true;
    } else {
        return false;
    }
}

string next_string(string s) {
    int c = 0;
    int i;
    for (i = s.length()-1; i >= 0; i--) {
        if (A[s[i]-'a']) c++;
        while (s[i] < 'z' && !next_char(s[i], c, s.length()-1-i)) {
            s[i] = (char)(s[i]+1);
        }
        s[i] = (char)(s[i]+1);
        if (s[i] != 'z'+1) break;
    }
    int tmp = i+p+1;
    for (i++; i < tmp; i++) s[i] = 'a';
    for (; i < s.length(); i++) s[i] = 'c';
    return s;
}


int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> m >> s;
        p = -1;
        string ans = next_string(s);
        if (p != -1) cout << ans << endl;
        else cout << -1 << endl;
    }
}
