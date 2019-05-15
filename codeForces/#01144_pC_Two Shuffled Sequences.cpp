#include <bits/stdc++.h>
#define MAXN 200000
using namespace std;

int n;
int num[MAXN+5], appr[MAXN+5];
vector <int> inc, de;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num[i];
    appr[num[i]]++;
    if (appr[num[i]] > 2) {
      cout << "NO" << endl;
      return 0;
    }
  }
  sort(num, num+n);
  cout << "YES" << endl; 
  for (int i = 0; i < n; i += appr[num[i]]) {
    inc.push_back(num[i]);
  }
  for (int i = n-1; i >= 0; i--) {
    if (appr[num[i]] == 2) {
      de.push_back(num[i]);
      appr[num[i]]--;
    }
  }
  cout << inc.size() << endl;
  for (int i = 0; i < inc.size(); i++) {
    cout << inc[i] << " ";
  }
  cout << endl;
  cout << de.size() << endl;
  for (int i = 0; i < de.size(); i++) {
    cout << de[i] << " ";
  }
  return 0;
} 
