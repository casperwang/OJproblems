#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;
map <int, int> appr;
int num[6] = {4, 8, 15, 16, 23, 42};
int ans[6];

int main() {
  appr[4] = appr[8] = appr[15] = appr[16] = appr[23] = appr[42] = 1;
  cout << "? 1 2" << endl;
  cin >> a;
  cout << "? 2 3" << endl;
  cin >> b;
  cout << "? 4 5" << endl;
  cin >> c;
  cout << "? 5 6" << endl;
  cin >> d;
  for (int i = 0; i < 6; i++) {
    if (a % num[i] == 0 && b % num[i] == 0 && appr[a / num[i]] && appr[b / num[i]] && a / num[i] != num[i] && b / num[i] != num[i]) {
      ans[0] = a / num[i];
      ans[1] = num[i];
      ans[2] = b / num[i];
    }
    if (c % num[i] == 0 && d % num[i] == 0 && appr[c / num[i]] && appr[d / num[i]] && c / num[i] != num[i] && d / num[i] != num[i]) {
      ans[3] = c / num[i];
      ans[4] = num[i];
      ans[5] = d / num[i];
    }
  }
  cout << "!";
  for (int i = 0; i < 6; i++) {
    cout << " " << ans[i];
  }
  cout << endl;
}
