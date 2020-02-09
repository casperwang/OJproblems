#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#define pis pair<int,string>
#define ff first
#define ss second
using namespace std;

int C, X, T, t;
int result;
string s;
unordered_set <string> vis;

bool if_win(string now, char c) {
	if (now[0] == c && now[1] == c && now[2] == c)
		return 1;
	if (now[3] == c && now[4] == c && now[5] == c)
		return 1;
	if (now[6] == c && now[7] == c && now[8] == c)
		return 1;
	if (now[0] == c && now[3] == c && now[6] == c)
		return 1;
	if (now[1] == c && now[4] == c && now[7] == c)
		return 1;
	if (now[2] == c && now[5] == c && now[8] == c)
		return 1;
	if (now[0] == c && now[4] == c && now[8] == c)
		return 1;
	if (now[2] == c && now[4] == c && now[6] == c)
		return 1;
	return 0;
}

int who_win(string now) {
	if (if_win(now, 'O')) return  1;
	if (if_win(now, 'X')) return -1;
	return 0;
}

void DFS(string now, int t) {
	vis.insert(now);
	result = who_win(now);
	if (result ==  1) C++;
	if (result == -1) X++;
	if (!result) {
		bool tf = 0;
		for (int i = 0; i < 9; i++) {
			if (now[i] == '-') {
				tf = 1;
				if (t % 2 == 0) {
					now[i] = 'O';
					if (!vis.count(now)) DFS(now, t+1);
				} else {
					now[i] = 'X';
					if (!vis.count(now)) DFS(now, t+1);
				}
				now[i] = '-';
			}
		}
		if (!tf) T++;
	}
	return;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> s;
	for (int i = 0; i < 9; i++)
		if (s[i] != '-') t++;
	DFS(s, t);
	cout << C+X+T << " " << C << " " << X << " " << T << "\n";
	return 0;
}