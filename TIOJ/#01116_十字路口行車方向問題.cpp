#include <bits/stdc++.h>
using namespace std;

string s, a, b, c, d;

signed main() {
    while (cin >> s) {
        a = b = c = d = "";
        if (s[0]=='b') a = "X";
        else {
            if (s[3]!='a') a += 'A';
            if (s[1]!='a') a += 'B';
            if (s[2]!='a') a += 'C';
            if (!a.length())a = "Y";
        }
        if (s[1]=='b') b = "X";
        else {
            if (s[0]!='a') b += 'A';
            if (s[2]!='a') b += 'B';
            if (s[3]!='a') b += 'C';
            if (!b.length())b = "Y";
        }
        if (s[2]=='b') c = "X";
        else {
            if (s[1]!='a') c += 'A';
            if (s[3]!='a') c += 'B';
            if (s[0]!='a') c += 'C';
            if (!c.length())c = "Y";
        }
        if (s[3]=='b') d = "X";
        else {
            if (s[2]!='a') d += 'A';
            if (s[0]!='a') d += 'B';
            if (s[1]!='a') d += 'C';
            if (!d.length())d = "Y";
        }
        cout<<a<<", "<<b<<", "<<c<<", "<<d<<endl;
    }
}