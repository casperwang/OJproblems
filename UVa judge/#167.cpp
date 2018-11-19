//The Sultan's Successors: 8 queens problem (Recursive)
#include <iostream>
#include <cmath> // for log10()
using namespace std;

int T, ans;
int weighting[8][8]; // the score of each position
int queens[8][8];   // whether Queen can place or not

void queenChange(int x, int y, int tf) {
	// mark the position that Queen can attack
	for (int a = 0; a < 8; a++) {
		queens[a][y] += tf;
		queens[x][a] += tf;
		if (x+a < 8 && y+a < 8) queens[x+a][y+a] += tf;
		if (x-a >= 0 && y-a >= 0) queens[x-a][y-a] += tf;
		if (x-a >= 0 && y+a < 8) queens[x-a][y+a] += tf;
		if (x+a < 8 && y-a >= 0) queens[x+a][y-a] += tf;
	}
}

void placingQueen(int x, int y, int queens[8][8], int tmp) {
	tmp += weighting[x][y]; // tmp: now score
	if (x == 7) {
		ans = max(ans, tmp);
		return;
	}
	queenChange(x, y, 1);
	for (int a = 0; a < 8; a++) {
		if (!queens[x+1][a]) placingQueen(x+1, a, queens, tmp); // DFS
	}
	queenChange(x, y, -1);
	return;
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		ans = 0;
		for (int a = 0; a < 8; a++) {
			for (int b = 0; b < 8; b++) {
				cin >> weighting[a][b];
				queens[a][b] = 0;
			}
		}
		for (int a = 0; a < 8; a++) {
			placingQueen(0, a, queens, 0);
		}
		for (int i = 1; i < 5-log10(ans); i++) cout << " ";
		cout << ans << endl; 
	}
	return 0;
}
