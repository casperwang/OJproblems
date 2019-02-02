#include <bits/stdc++.h>
#define N 1000
using namespace std;
int n, score[N+5], m;
string people[N+5], winner;
map <string, int> players;
map <string, int> can_win;
int main() {
  scanf("%d",&n);
  for (int i = 0; i < n; i++) {
  	cin >> people[i] >> score[i];
  	players[people[i]] += score[i];
  }
  for (auto i : players) {
  	m = max(m, i.second);
  }
  for (int i = 0; i < n; i++) {
  	can_win[people[i]] += score[i];
  	if (can_win[people[i]] >= m && players[people[i]] >= m) {
  	  winner = people[i];
  	  break;
	}
  }
  cout << winner << endl;
  return 0;
}
