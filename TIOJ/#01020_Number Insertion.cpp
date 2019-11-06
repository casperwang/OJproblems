#include <bits/stdc++.h>
using namespace std;

int k, cnt;
vector <int> arr;
bool tf;

void DFS(int now, vector<int> tmp) {
	if (now == k+1) {
		if (!cnt) arr.resize(now);
		cnt++;
		tf = 1;
		for (int i = 0; i < now; i++) {
			if (tmp[i] > arr[i]) break;
			if (tmp[i] < arr[i]) {
				tf = 0;
				break;
			}
		}
		if (tf) for (int i = 0; i < now; i++) arr[i] = tmp[i];
		return;
	}
	for (int i = 1; i < now; i++) {
		if (now % (tmp[i]+tmp[i-1]) == 0) {
			tmp.insert(tmp.begin()+i, now);
			DFS(now+1, tmp);
			tmp.erase(tmp.begin()+i);
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> k;
	arr.insert(arr.begin(), 0);
	arr.insert(arr.begin()+1, 1);
	DFS(2, arr);
	cout << cnt << '\n';
	for (int i = 0; i <= k; i++) {
		cout << arr[i] << " \n"[i==k];
	}
	return 0;
}