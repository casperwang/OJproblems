#include <bits/stdc++.h>
#define MAXN 200000
using namespace std;

struct opn{
  int a, b, op;
  opn(){}
  opn(int a, int b, int op) : a(a), b(b), op(op) {}
};

int n, k, p;
int num[MAXN+5], appr[MAXN+5];
vector <opn> ans;

void DFS(int now) {
  if (now && num[now-1] != num[now]) {
    if (num[now-1] < num[now]) {
      ans.push_back(opn(now-1, now, 1));
    } else {
      ans.push_back(opn(now-1, now, 2));
    }
    num[now-1] = num[now];
    DFS(now-1);
  }
  if (now < n-1 && num[now+1] != num[now]) {
    if (num[now+1] < num[now]) {
      ans.push_back(opn(now+1, now, 1));
    } else {
      ans.push_back(opn(now+1, now, 2));
    }
    num[now+1] = num[now];
    DFS(now+1);
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num[i];
    appr[num[i]]++;
    if (appr[num[i]] > k) {
      k = appr[num[i]];
      p = num[i];
    }
  }
  for (int i = 0; i < n; i++) {
    if (num[i] == p) DFS(i);
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].op << " " << ans[i].a+1 << " " << ans[i].b+1 << endl; 
  }
  return 0;
} 
