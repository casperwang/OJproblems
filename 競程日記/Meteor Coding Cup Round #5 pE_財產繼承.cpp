//Meteor Coding Cup Round #5 - E: topological sort
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#define N 100000
using namespace std;

class cmp {
public:
    bool operator() (const int &a, const int &b) {
        return a > b;
    }
};

int n, k, c, first;
bool can_visit[N+5];
priority_queue <int, vector<int>, cmp> Next;
vector <int> ans;
vector <int> father[N+5];

void dfs(int now) {
    ans.push_back(now);
    Next.pop();
    for (int i = 0; i < father[now].size(); i++) {
        Next.push(father[now][i]);
    }
    if (Next.size()) dfs(Next.top());
    return;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) first =  first ^ i;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> c;
            father[i].push_back(c);
            first =  first ^ c;
        }
    }
    Next.push(first);
    dfs(first);
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << endl;
	return 0;
}

