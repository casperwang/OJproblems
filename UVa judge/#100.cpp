#include <iostream>

using namespace std;
long long int a, b, c, ans;
int f(int num, int j) {
    if (num == 1) {
        c = j;
        return 0;
    }
    if (num % 2 == 1) {
        f(num * 3 + 1, j+1);
    } else {
        f(num / 2, j+1);
    }
}
int main()
{
    while(cin >> a >> b) {
        ans = 0;
        cout << a << " " << b << " ";
        if (a > b) {
            swap(a, b);
        }
        for (int i = a; i <= b; i++) {
            f(i, 0);
            if (c > ans) {
                ans = c;
            }
        }
        cout << ans+1 << endl;
    }
    return 0;
}
