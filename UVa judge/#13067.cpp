//Prime Kebab Menu: prime (math)
#include <iostream>
#include <vector>
#define N 10000000
using namespace std;

vector <int> primes;
bool is_prime[N+5];
long long int n, ans;

int main() {
	// creating prime number list
	for (int i = 2; i <= N; i++) {
		if (!is_prime[i]) primes.push_back(i);
		for (int j = 0; j < primes.size() && primes[j]*i < N; j++) {
			is_prime[primes[j]*i] = 1;
			if (!(i%primes[j])) break;
		}
	}
	while (cin >> n) {
		if (n == 1) return 0;
		ans = 0;
		//finding prime factor
		for (int i = 0; i < primes.size(); i++) {
			while (!(n%primes[i])) {
				ans++;
				n /= primes[i];
			}
		}
		if (n > 1) ans++;
		cout << ans << endl;
	}
	return 0;
}
