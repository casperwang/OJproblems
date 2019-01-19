#include <iostream>
#define N 8
using namespace std;
int t, n, m, x, y;
char w[N+5][N+5];
string letters = "IEHOVA#";
int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
  	cin >> n >> m;
  	for (int a = 1; a <= n; a++) {
  	  for (int b = 1; b <= m; b++) {
  	  	cin >> w[a][b];
  	  	if (w[a][b] == '@') {
  	  	  x = a;
  	  	  y = b;
		}
	  }
	}
	for (int j = 0; j < 7; j++) {
	  if (j) cout << " ";
	  if (w[x-1][y] == letters[j]) {
	  	x--;
	  	cout << "forth";
	  } else if (w[x][y+1] == letters[j]) {
	  	y++;
	  	cout << "right";
	  } else if (w[x][y-1] == letters[j]) {
	  	y--;
	  	cout << "left";
	  }
	}
	cout << endl;
  }
}
