#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int N, arr[50];
bool pick[50];

void subs(int k, int at, long long &tot) {
    if (k == 0) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            if (pick[i]) sum += arr[i];
        }
        if (sum < 200) {
            tot -= sum;
        }
    }
    else if (N-at-k == 0) {
        pick[at] = true;
        subs(k-1, at+1, tot);
        pick[at] = false;
    }
    else {
        pick[at] = true;
        subs(k-1, at+1, tot);
        pick[at] = false;
        subs(k, at+1, tot);
    }
}

int main() {
    cin >> N;
    memset(arr, 0, sizeof(arr));
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    long long total = sum * pow(2, N-1);

    for (int i = 1; i <= 3; i++) {
        subs(i, 0, total);
    }
    printf("%lld\n", total);
}