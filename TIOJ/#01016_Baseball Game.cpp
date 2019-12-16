#include <cstdio>
#define int unsigned short
using namespace std;

int now, k;
int a, b, c;
int score[2];
char s[300];

signed main() {
	while(scanf("%s", &s) != EOF) {
		now = 0;
		for (int i = 0; i < 18; i++) {
			k = a = b = c = 0;
			while (k < 3) {
				if (s[now] == 'K' || s[now] == 'O') k++;
				else if (s[now] == 'W') {
					a++;
					if (a > 1) a--, b++;
					if (b > 1) b--, c++;
					if (c > 1) c--, score[i&1]++;
				} else if (s[now] == 'S') {
					if (c) c--, score[i&1]++;
					if (b) b--, c++;
					if (a) a--, b++;
					a++;
				} else if (s[now] == 'D') {
					if (c) c--, score[i&1]++;
					if (b) b--, score[i&1]++;
					if (a) a--, c++;
					b++;
				} else if (s[now] == 'T') {
					if (c) c--, score[i&1]++;
					if (b) b--, score[i&1]++;
					if (a) a--, score[i&1]++;
					c++;
				} else if (s[now] == 'H') {
					if (c) c--, score[i&1]++;
					if (b) b--, score[i&1]++;
					if (a) a--, score[i&1]++;
					score[i&1]++;
				}
				now++;
			}
		}
		printf("%d %d\n", score[0], score[1]);
		score[0] = score[1] = 0;
	}
}