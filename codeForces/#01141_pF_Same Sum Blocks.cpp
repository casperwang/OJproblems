#include <bits/stdc++.h>
#define MAXN 1500+5
using namespace std;

struct Range{
  int l, r;
  Range() {}
  Range(int l, int r) : l(l), r(r) {}
};

bool cmp(const Range a, const Range b) {
  if (a.r != b.r) return a.r < b.r;
  else return a.l > b.l;
} 

long long int n, num[MAXN], pre[MAXN], m, tmp;
map <int, vector<Range>> p, ans;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
    pre[i] += pre[i-1] + num[i];
    for (int j = 0; j < i; j++) {
      p[pre[i] - pre[j]].push_back(Range(j+1, i));
    }
  }
  for (auto i : p) {
    sort(i.second.begin(), i.second.end(), cmp);
    int now = 0;
    for (int j = 0; j < i.second.size(); j++) {
      if (i.second[j].l > now) {
        ans[i.first].push_back(i.second[j]);
        now = i.second[j].r;
      }
    }
  }
  for (auto i : ans) {
    if (i.second.size() > tmp) {
      tmp = i.second.size();
      m = i.first;
    }
  }
  cout << tmp << endl;
  for (int i = 0; i < tmp; i++) {
    cout << ans[m][i].l << " " << ans[m][i].r << endl;
  } 
  return 0;
}
