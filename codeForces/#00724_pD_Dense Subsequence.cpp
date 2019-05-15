#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;

int n, k, tmp, now, m;
string s;
vector <char> ans;
int appr[26];
bool tf;

int main() {
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    appr[s[i]-'a']++;
  }
  while (!appr[k]) k++;
  for (int i = n; i < s.length(); i++) {
    appr[s[i] - 'a']++;
    appr[s[i-n]-'a']--;
    tmp = 0;
    while (!appr[tmp]) tmp++;
    k = max(k, tmp);
  }
  for (int i = 0; i < n; i++) {
    appr[s[i]-'a']++;
    if (s[i] < k+'a') {
      ans.push_back(s[i]);
      tf = 1;
      m = i;
    }
  }
  if (!tf) {
    ans.push_back((char)(k+'a'));
    now = n;
    while (s[now] != (char)(k+'a')) now--;
  }
  for (int i = n; i < s.length(); i++) {
    appr[s[i] - 'a']++;
    appr[s[i-n]-'a']--;
    if (s[i] < k+'a') {
      ans.push_back(s[i]);
      m = i;
    }
    if (i - now >= n && i - m >= n) {
      ans.push_back((char)(k+'a'));
      now = i;
      while (s[now] != (char)(k+'a')) now--;
    }
  }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i];
  }
  cout << endl;
}
