//Number Maze: shortest path(Dijkstra)
#include <iostream>
#include <queue>
#define N 999
#define inf 1073741824
using namespace std;

struct pos{
	int x, y, w;
};

class cmp{
public:
	bool operator() (const pos &a, const pos &b) {
		return a.w > b.w;
	}
};

int t, n, m;
int maze[N+5][N+5]; //weight
int path[N+5][N+5]; //shortest path
bool visited[N+5][N+5];
priority_queue <pos, vector<pos>, cmp> next_step;

void relaxing(int x, int y) {
	if (y-1 >= 0) {
		path[x][y-1] = min(path[x][y-1], path[x][y]+maze[x][y-1]);
		pos p; p.x = x; p.y = y-1; p.w = path[x][y-1];
		next_step.push(p);
	}
	if (y+1 < m) {
		path[x][y+1] = min(path[x][y+1], path[x][y]+maze[x][y+1]);
		pos p; p.x = x; p.y = y+1; p.w = path[x][y+1];
		next_step.push(p);
	}
	if (x-1 >= 0) {
		path[x-1][y] = min(path[x-1][y], path[x][y]+maze[x-1][y]);
		pos p; p.x = x-1; p.y = y; p.w = path[x-1][y];
		next_step.push(p);
	}
	if (x+1 < n) {
		path[x+1][y] = min(path[x+1][y], path[x][y]+maze[x+1][y]);
		pos p; p.x = x+1; p.y = y; p.w = path[x+1][y];
		next_step.push(p);
	}
	return;
}

int main() {
	cin >> t;
	for (int q = 0; q < t; q++) {
		while (next_step.size()) next_step.pop();
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> maze[i][j];
				path[i][j] = inf;
				visited[i][j] = 0;
			}
		}
		path[0][0] = maze[0][0];
		relaxing(0, 0);
		visited[0][0] = 1;
		while (!visited[n-1][m-1]) {
			while (visited[next_step.top().x][next_step.top().y]) next_step.pop();
			pos p = next_step.top();
			visited[next_step.top().x][next_step.top().y] = 1;
			relaxing(next_step.top().x, next_step.top().y);
		}
		cout << path[n-1][m-1] << endl;
	}
	return 0;
}
