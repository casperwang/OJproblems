#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int appr[26], tf;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    tf = 1;
    for (int j = 0; j < 26; j++) appr[j] = 0;
    for (int j = 0; j < s.length(); j++) {
      appr[s[j]-'a']++;
      if (appr[s[j]-'a'] > 1) tf = 0;
    }
    int j = 0;
    while (!appr[j]) j++;
    while (appr[j]) j++;
    for (; j < 26; j++) {
      if (appr[j]) tf = 0;
    }
    if (tf) cout << "Yes" << endl;
    else cout << "No" << endl; 
  }
  return 0;
} 
