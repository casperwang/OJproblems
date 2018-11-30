//ID Codes: string processing
#include <iostream>
#include <algorithm>
using namespace std;

string origin;
char a, alteration[10000];
int tmp;
bool alphabet[26];

int main(){
	while (cin >> origin) {
        if (origin == "#") return 0;
        bool tf = 0;
        int k = 0;
        for (int i = 0; i < 26; i++) alphabet[i] = 0;
        for (int i = origin.length()-1; i >= 0; i--) {
            for (int j = origin[i]-'a'+1; j < 26; j++) {
                if (alphabet[j]) {
                    tmp = i;
                    a = (char)('a'+j);
                    tf = 1;
                    for (int i = 0; i < k; i++) {
                        if (alteration[i] == a) {
                            alteration[i] = (char)('a'-1);
                            break;
                        }
                    }
                    break;
                }
            }
            alteration[k++] = origin[i];
            if (tf) break;
            alphabet[origin[i]-'a'] = 1;
        }
        sort(alteration, alteration+k);
        if (tf) {
            for (int i = 0; i < tmp; i++) cout << origin[i];
            cout << a;
            for (int i = tmp+1; i < origin.length(); i++) cout << alteration[i-tmp];
            cout << endl;
        } else {
            cout << "No Successor" << endl;
        }
	}
}

