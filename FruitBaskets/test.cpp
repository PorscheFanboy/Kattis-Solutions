#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, arr[50];
bool pick[50];

long long res;
long long table[50];


int main() {
    cin >> N;
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N, greater<int>());
    res = 0;

    for (int i = 0; i < 20; i++) {
        long long total = 0;
        long long k = ((long long) 1) << (i+1);
        for (long long j = 1; j < k; j++) {
            int sum = 0;
            for (int n = 0; n < i + 1; n++) {
                long long m = ((long long) 1) << n;
                if (j & m) {
                    sum += arr[N - n - 1];
                }
            }
            total += sum;
        }
        table[i] = total;
    }

    for (int i = 0; i < 20; i++) {
        printf("%lld\n", table[i]);
    }

}