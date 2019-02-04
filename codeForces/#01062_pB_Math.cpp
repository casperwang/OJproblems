#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#define N 2000000
using namespace std;

long long int n, ans, step, m;
bool tf;
bool not_primes[N+5];
vector <int> primes;

int main() {
    for (int i = 2; i <= N; i++) {
        if (!not_primes[i]) {
            primes.push_back(i);
            if (i > sqrt(N)) continue;
            for (long long int j = i*i; j <= N; j += i) {
                not_primes[j] = 1;
            }
        }
    }
    scanf("%ld", &n);
    ans = 1;
    for (int i = 0; primes[i] <= n; i++) {
        long long int tmp = 0;
        if (n % primes[i] == 0) ans *= primes[i];
        while (n % primes[i] == 0) {
            tmp++;
            n /= primes[i];
        }
        if (m > 0 && tmp > m) tf = 1;
        m = max(m, tmp);
        if (tmp && tmp != m) tf = 1;
    }
    if (ceil(log2(m))-floor(log2(m)) > 0.1) tf = 1;
    if (m > 1) cout << ans << " " << ceil(log2(m))+tf << endl;
    else cout << ans << " " << 0 << endl;
    return 0;
}
