#include <bits/stdc++.h>
using namespace std;

int n, K;
int L, R, mid;
int redDepth, blueDepth, nowR, nowB;
string s, ans, output;

int main() {
  cin >> n >> s;
  L = 1, R = n/2;
  for (int i = 0; i < n; i++) ans += '0';
  while (R > L) {
    mid = (L + R) / 2;
    nowR = nowB = 0;
    redDepth = blueDepth = 0;
    for (int i = 0; i < n; i++) {
      if (nowR < mid && s[i] == '(') {
        nowR++;
        ans[i] = '0';
      } else if (nowB && s[i] == ')') {
        nowB--;
        ans[i] = '1';
      } else if (nowR && s[i] == ')') {
        nowR--;
        ans[i] = '0';
      } else if (s[i] == '(') {
        nowB++;
        ans[i] = '1';
      }
      redDepth = max(redDepth, nowR);
      blueDepth = max(blueDepth, nowB);
    }
    if (max(redDepth, blueDepth) > mid) L = mid+1;
    else R = mid;
  }
  K = 12412312;
  for (int j = max(0, mid-3); j <= min(mid+3, n/2); j++) {
    nowR = nowB = 0;
    redDepth = blueDepth = 0;
    for (int i = 0; i < n; i++) {
      if (nowR < j && s[i] == '(') {
        nowR++;
        ans[i] = '0';
      } else if (nowB && s[i] == ')') {
        nowB--;
        ans[i] = '1';
      } else if (nowR && s[i] == ')') {
        nowR--;
        ans[i] = '0';
      } else if (s[i] == '(') {
        nowB++;
        ans[i] = '1';
      }
      redDepth = max(redDepth, nowR);
      blueDepth = max(blueDepth, nowB);
    }
    if (max(redDepth, blueDepth) < K) {
      output = ans;
      K = max(redDepth, blueDepth);
    }
  }
  cout << output << endl;
}
