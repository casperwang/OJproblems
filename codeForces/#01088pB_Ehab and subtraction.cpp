#include <iostream>
#include <algorithm>
#define N 100000
using namespace std;

int n, k, num[N+5];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> num[i];
    sort(num, num+n);
    int now = 0;
    for (int i = 0; i < n && k > 0; i++) {
        if (num[i] - now > 0) {
            k--;
            cout << num[i]-now << endl;
            now = num[i];
        }
    }
    for (int i = 0; i < k; i++) {
        cout << 0 << endl;
    }
    return 0;
}
