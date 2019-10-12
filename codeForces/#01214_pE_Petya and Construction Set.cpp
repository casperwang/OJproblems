#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;
  
int n, d, k;
int mmin, mmax;
pair <int,int> dis[MAXN+5];
map <int, vector<int> > tree;
vector <int> tmp;
  
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  tmp.push_back(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> d;
    dis[i] = {d, i};
  }
  sort(dis+1, dis+1+n);
  for (int i = n; i >= 1; i--) {
    tmp[0] = dis[i].second*2-1;
    tree[n-i] = tmp;
  }
  k = 0;
  mmin = 0, mmax = n;
  for (int i = n; i >= 1; i--) {
    if (k-dis[i].first+1 >= mmin) {
      tree[k-dis[i].first+1].push_back(dis[i].second*2);
    } else if (k+dis[i].first  < mmax) {
      tree[k+dis[i].first-1].push_back(dis[i].second*2);
    } else if (k+dis[i].first == mmax) {
      tmp[0] = dis[i].second*2;
      tree[k+dis[i].first] = tmp;
      mmax++;
    }
    k++;
  }
  for (int i = 0; i < tree.size(); i++) {
    for (int j = 1; j < tree[i].size(); j++) {
      cout << tree[i][0] << " " << tree[i][j] << endl;
    }
    if (i) cout << tree[i][0] << " " << tree[i-1][0] << endl;
  }
} 

