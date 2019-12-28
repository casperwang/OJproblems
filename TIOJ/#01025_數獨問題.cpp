#include <bits/stdc++.h>
using namespace std;

int arr[9][9];
int cnt;

void DFS(int x, int y) {
	bool tf[10];
	for (int i = 1; i <= 9; i++) tf[i] = 1;
	for (int i = 0; i < 9; i++) tf[arr[x][i]] = 0;
	for (int i = 0; i < 9; i++) tf[arr[i][y]] = 0;
	for (int i = x/3*3; i < x/3*3+3; i++)
		for (int j = y/3*3; j < y/3*3+3; j++)
			tf[arr[i][j]] = 0;
	for (int i = 1; i <= 9; i++) {
		if (!tf[i]) continue;
		arr[x][y] = i;
		for (int j = x; j < 9 && tf[i]; j++) {
			for (int k = 0; k < 9 && tf[i]; k++) {
				if (!arr[j][k]) DFS(j, k), tf[i] = 0;
			}
		}
		if (!tf[i]) continue;
		cnt++;
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 9; k++) {
				cout << arr[j][k] << " \n"[k==8];
			}
		}
		cout << '\n';
	}
	arr[x][y] = 0;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (!arr[i][j]) {
				DFS(i, j);
				cout << "there are a total of "<<cnt<<" solution(s).\n";
				return 0;
			}
		}
	}
}