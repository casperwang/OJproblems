#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;

struct qtn{
  int x, y, z, ans;
  qtn(){}
};

struct optn{
  int l, r, lvl;
  vector <int> q;
  optn() {}
  optn(int l, int r, int lvl) : l(l), r(r), lvl(lvl), q() {}
};

int N, M, Q;
int lvl;
int a, b;
int l, r;
int DSU[MAXN+5];
int SIZE[MAXN+5];
vector <qtn> query;
vector <pair<int, int>> edges;
queue <optn> todo;

int Find(int a) {
  if (DSU[a] == a) return a;
  DSU[a] = Find(DSU[a]);
  return DSU[a];
}

void Union(int a, int b) {
  int A = Find(a), B = Find(b);
  if (A != B) {
    SIZE[A] += SIZE[B];
    DSU[B] = A;
  }
  return;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  edges.push_back({0, 0});
  for (int i = 1; i <= M; i++) {
    cin >> a >> b;
    edges.push_back({a, b});
  }
  cin >> Q;
  query.push_back(qtn());
  optn p = optn(1, M, 1);
  for (int i = 1; i <= Q; i++) {
    query.push_back(qtn());
    cin >> query[i].x >> query[i].y >> query[i].z;
    p.q.push_back(i);
  }
  for (int i = 1; i <= N; i++) {
    DSU[i] = i;
    SIZE[i] = 1;
  }
  todo.push(p);
  while (todo.size()) {
    l = todo.front().l, r = todo.front().r;
    int len = todo.front().q.size();
    if (l == r) {
      Union(edges[l].first, edges[l].second);
      for (int j = 0; j < len; j++) {
        query[todo.front().q[j]].ans = r;
      }
      todo.pop();
      continue;
    }
    int i;
    for (i = l; i <= (l+r)/2; i++) {
      Union(edges[i].first, edges[i].second);
    }
    optn L, R;
    L = optn(l,   (l+r)/2, todo.front().lvl+1);
    R = optn((l+r)/2+1, r, todo.front().lvl+1);
    for (int j = 0; j < len; j++) {
      qtn tmp = query[todo.front().q[j]];
      if ((Find(tmp.x) != Find(tmp.y) && SIZE[DSU[tmp.x]] + SIZE[DSU[tmp.y]] >= tmp.z)
       || (Find(tmp.x) == Find(tmp.y) && SIZE[DSU[tmp.x]] >= tmp.z)) {
        L.q.push_back(todo.front().q[j]);
      } else {
        R.q.push_back(todo.front().q[j]);
      }
    }
    for (; i <= r; i++) {
      Union(edges[i].first, edges[i].second);
    }
    int tmp = todo.front().lvl;
    todo.pop();
    todo.push(L);
    todo.push(R);
    if (todo.size() && todo.front().lvl > tmp) {
      for (int j = 1; j <= N; j++) {
        DSU[j] = j;
        SIZE[j] = 1;
      }
    }
  }
  for (int i = 1; i <= Q; i++) {
    cout << query[i].ans << '\n';
  }
  return 0;
}
