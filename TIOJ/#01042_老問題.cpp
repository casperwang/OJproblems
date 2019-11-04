#include <bits/stdc++.h>
#define MAXN 100
#define Hina ios_base::sync_with_stdio(0), cin.tie(0)
#define int long long
#define INF (int)1e18
using namespace std;

int n, ans;
int W[MAXN+5][MAXN+5];
int mat[MAXN+5];
int Lx[MAXN+5], Ly[MAXN+5], slack[MAXN+5]; 
bool S[MAXN+5], T[MAXN+5];

void tension(int &a, const int b){ 
	if (b < a) a = b; 
}

bool match(int u){ 
	S[u] = 1; 
	for (int v = 0; v < n; ++v){ 
		if (T[v]) continue; 
		int t = Lx[u] + Ly[v] - W[u][v]; 
		if (!t){ 
			T[v] = 1; 
			if (mat[v] == -1 || match(mat[v])) { 
    		mat[v] = u;
    		return 1; 
			}
		} else tension(slack[v], t); 
	}
	return 0; 
}

void update(){ 
	int d = INF; 
  for (int i = 0; i < n; ++i) 
    if (!T[i]) tension(d, slack[i]); 
  for (int i = 0; i < n; ++i){ 
    if (S[i]) Lx[i] -= d; 
    if (T[i]) Ly[i] += d; 
  } 
}

void KM() { 
  for (int i = 0; i < n; ++i){ 
    Lx[i] = Ly[i] = 0; mat[i] = -1; 
    for (int j = 0; j < n; ++j) Lx[i] = max(Lx[i], W[i][j]); 
  } 
  for (int i = 0; i < n; ++i){ 
    fill(slack, slack+n, INF); 
    while (1){ 
      for (int j = 0; j < n; ++j) S[j] = T[j] = 0; 
      if (match(i)) break; 
      else update(); 
    } 
  } 
}

signed main() {
	Hina;
	while (cin >> n) {
		if (!n) return 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> W[i][j];
				W[i][j] = max(W[i][j], (int)0);
			}
		}
		KM();
		ans = 0;
		for (int i = 0; i < n; i++) {
			assert(mat[i] >= 0);
			ans += W[mat[i]][i];
		}
		cout << ans << "\n";
	}
	return 0;
}