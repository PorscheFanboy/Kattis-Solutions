#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int n, primes[2000000];
string str;

int rec(int len) {
    for (int i = 2; i <= len; i++) {
        if (!primes[i]) continue;
        if (len % i != 0) continue;
        int l = len/i;
        int t = 0;

        for (int j = 0; j < l; j++) {
            if (t == 1) break;
            char c = str.at(j);
            for (int k = j+l; k < len; k+=l) {
                if (str.at(k) != c) {
                    t = 1;
                    break;
                }
            }
        }
        if (!t) return i * rec(l);
    }
    return 1;
}



int main() {
    memset(primes, 1, sizeof(primes));
    for (int i = 4; i < 2000000; i++) {
        for (int j = 2; j < sqrt(2) + 1; j++) {
            if (i % j == 0) {
                primes[i] = 0;
                break;
            }
        }
    }

    while(1) {
        cin >> str;
        if (!str.compare(".")) break;
        printf("%d\n", rec(str.length()));
    }
}