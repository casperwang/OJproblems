//Sum of Different Primes: DP
#include <iostream>
#include <vector>
#define N 1120
using namespace std;

int combins[2*N][15]; // combinations of primes
bool is_prime[N+5];
vector <int> primes;
int n, k;

int main(){
	// get prime
	for (int i = 2; i <= N; i++) is_prime[i] = 1;
	for (int i = 2; i < N; i++) {
		if (is_prime[i]) {
			primes.push_back(i);
			for (int j = i*i; j <= N; j+=i) {
				is_prime[j] = 0;
			}
		}
	}
	// DP
	combins[0][0] = 1;
	for (int i = 0; i < primes.size(); i++) {
		for (int j = 13; j >= 0; j--) {
			for (int k = 0; k < N; k++) {
				if (combins[k][j]) {
					combins[k+primes[i]][j+1] += combins[k][j];
				}
			}
		}
	}
	while (cin >> n >> k) {
		if (!n && !k) return 0;
		cout << combins[n][k] << endl;
	}
}

