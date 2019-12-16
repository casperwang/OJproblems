#include <bits/stdc++.h>
using namespace std;

struct Edge { 
	int v;
	int flow;
	int C;
	int rev;
};
class Graph { 
	int V;
	vector <int> level, start;
	vector <vector<Edge> > adj; 
public: 
	Graph(int V) : V(V) { 
		adj.resize(V);
		start.resize(V, 0);
		level.resize(V, 0); 
	}
	void addEdge(int u,int v,int C) {
		Edge a{v, 0, C, (int)adj[v].size()};
		Edge b{u, 0, 0, (int)adj[u].size()};
		adj[u].push_back(a); 
		adj[v].push_back(b);
	}
	bool BFS(int s,int t); 
	int sendFlow(int s,int flow,int t); 
	int DinicMaxflow(int s,int t); 
};
bool Graph::BFS(int s,int t) { 
	for (int i = 0; i < V; i++) 
		level[i] = -1;
	level[s] = 0;
	queue<int> q; 
	q.push(s);
	while (!q.empty()) { 
		int u = q.front(); 
		q.pop(); 
		for (auto &e : adj[u]) { 
			if (level[e.v] < 0 && e.flow < e.C) {
				level[e.v] = level[u] + 1;
				q.push(e.v); 
			} 
		} 
	}
	return (level[t] >= 0); 
}
int Graph::sendFlow(int u,int flow,int t) {
	if (u == t) 
		return flow;
	for (; start[u] < adj[u].size(); start[u]++) {
		Edge &e = adj[u][start[u]];
		if (level[e.v] == level[u]+1 && e.flow < e.C) {
			int curr_flow = min(flow, e.C - e.flow);
			int temp_flow = sendFlow(e.v, curr_flow, t);
			if (temp_flow > 0) {
				e.flow += temp_flow;
				adj[e.v][e.rev].flow -= temp_flow; 
				return temp_flow;
			} 
		} 
	}
	return 0; 
} 
int Graph::DinicMaxflow(int s,int t) {
	if (s == t) 
		return -1;
	int total = 0;
	while (BFS(s, t) == true) {
		for(int i = 0; i < V; i++)
			start[i] = 0;
		while (int flow = sendFlow(s, INT_MAX, t))
			total += flow; 
	}
	return total; 
}

int n, k, t;
int a, b;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> n >> k) {
		if (!n && !k) return 0;
		t++, cout << "Case #" << t << ":";
		Graph g(n*2+2);
		for (int i = 1; i <= n; i++) {
			g.addEdge(0, i, 1);
			g.addEdge(n+i, n*2+1, 1);
		}
		for (int i = 0; i < k; i++) {
			cin >> a >> b;
			g.addEdge(a, n+b, 1);
		}
		cout << g.DinicMaxflow(0, 2*n+1) << '\n';
	}
}