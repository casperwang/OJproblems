//Diving for Gold: 0/1 knapsack
#include <iostream>
#include <vector>
#define N 50000
using namespace std;

int t, w, n; // time limit, constant, number of treature
int d[N+5], v[N+5]; // depth, quantity of gold
int knapsack[N+5];
bool tf;

int main(){
	while (cin >> t >> w >> n) {
        if (tf) cout << endl;
        tf = 1;
		vector <int> treasures[N+5]; //items in the knapsack
        for (int i = 0; i <= t; i++) knapsack[i] = 0;
		for (int i = 0; i < n; i++) {
			cin >> d[i] >> v[i];
			for (int j = t; j >= 3*w*d[i]; j--) {
				if (knapsack[j-3*w*d[i]] + v[i] > knapsack[j]) {
                    knapsack[j] = knapsack[j-3*w*d[i]] + v[i];
					treasures[j].clear();
					for (int k = 0; k < treasures[j-3*w*d[i]].size(); k++) {
                        treasures[j].push_back(treasures[j-3*w*d[i]][k]);
					}
					treasures[j].push_back(i);
				}
			}
		}
		cout << knapsack[t] << endl;
		cout << treasures[t].size() << endl;
		for (int i = 0; i < treasures[t].size(); i++) {
            cout << d[treasures[t][i]] << ' ' << v[treasures[t][i]] << endl;
        }
	}
}

