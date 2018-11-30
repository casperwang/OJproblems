//The Blocks Problem: implementation
#include <iostream>
#include <vector>
#define N 250
using namespace std;

int n, a, b;
int blocks[N+5];
string action;

int main(){
	while (cin >> n) {
        vector <int> pos[N+5];
        for (int i = 0; i < n; i++) {
            blocks[i] = i;
            pos[i].push_back(i);
        }
        while (cin >> action) {
            if (action == "quit") break;
            if (action == "move") {
                cin >> a >> action >> b;
                if (a != b && blocks[a] != blocks[b] && action == "onto") {
                    int i, j;
                    for (i = 0; pos[blocks[a]][i] != a; i++){}
                    for (j = 0; pos[blocks[b]][j] != b; j++){}
                    while (pos[blocks[b]].size() != j+1) {
                        pos[pos[blocks[b]][pos[blocks[b]].size()-1]].push_back(pos[blocks[b]][pos[blocks[b]].size()-1]);
                        blocks[pos[blocks[b]][pos[blocks[b]].size()-1]] = pos[blocks[b]][pos[blocks[b]].size()-1];
                        pos[blocks[b]].pop_back();
                    }
                    while (pos[blocks[a]].size() != i+1) {
                        pos[pos[blocks[a]][pos[blocks[a]].size()-1]].push_back(pos[blocks[a]][pos[blocks[a]].size()-1]);
                        blocks[pos[blocks[a]][pos[blocks[a]].size()-1]] = pos[blocks[a]][pos[blocks[a]].size()-1];
                        pos[blocks[a]].pop_back();
                    }
                    pos[blocks[a]].pop_back();
                    pos[blocks[b]].push_back(a);
                    blocks[a] = blocks[b];
                } else if (a != b && blocks[a] != blocks[b] && action == "over") {
                    int i, j;
                    for (i = 0; pos[blocks[a]][i] != a; i++){}
                    while (pos[blocks[a]].size() != i+1) {
                        pos[pos[blocks[a]][pos[blocks[a]].size()-1]].push_back(pos[blocks[a]][pos[blocks[a]].size()-1]);
                        blocks[pos[blocks[a]][pos[blocks[a]].size()-1]] = pos[blocks[a]][pos[blocks[a]].size()-1];
                        pos[blocks[a]].pop_back();
                    }
                    pos[blocks[a]].pop_back();
                    pos[blocks[b]].push_back(a);
                    blocks[a] = blocks[b];
                }
            } else if (action == "pile") {
                cin >> a >> action >> b;
                if (a != b && blocks[a] != blocks[b] && action == "onto") {
                    int i, j;
                    for (i = 0; pos[blocks[a]][i] != a; i++){}
                    for (j = 0; pos[blocks[b]][j] != b; j++){}
                    while (pos[blocks[b]].size() != j+1) {
                        pos[pos[blocks[b]][pos[blocks[b]].size()-1]].push_back(pos[blocks[b]][pos[blocks[b]].size()-1]);
                        blocks[pos[blocks[b]][pos[blocks[b]].size()-1]] = pos[blocks[b]][pos[blocks[b]].size()-1];
                        pos[blocks[b]].pop_back();
                    }
                    int a_p = blocks[a];
                    for (int k = i; k < pos[a_p].size(); k++) {
                        pos[blocks[b]].push_back(pos[a_p][k]);
                        blocks[pos[a_p][k]] = blocks[b];
                    }
                    while (pos[a_p].size() != i) pos[a_p].pop_back();
                } else if (a != b && blocks[a] != blocks[b] && action == "over") {
                    int i;
                    for (i = 0; pos[blocks[a]][i] != a; i++){}
                    int a_p = blocks[a];
                    for (int k = i; k < pos[a_p].size(); k++) {
                        pos[blocks[b]].push_back(pos[a_p][k]);
                        blocks[pos[a_p][k]] = blocks[b];
                    }
                    while (pos[a_p].size() != i) pos[a_p].pop_back();
                }
            }
        }
        for (int i = 0; i < n; i++) {
            cout << i << ":";
            for (int j = 0; j < pos[i].size(); j++) {
                cout << " " << pos[i][j];
            }
            cout << endl;
        }
	}
}
