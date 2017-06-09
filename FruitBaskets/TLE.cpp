#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, arr[50];

int main() {
    cin >> N;
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    unsigned long long res = 0;
    unsigned long long k = ((unsigned long long) 1) << N;
    for (unsigned long long i = 1; i < k; i++) {
        int sum = 0;
        for (int j = 0; j < N; j++) {
            unsigned long long m = ((unsigned long long) 1) << j;
            if (i & m) {
                sum += arr[j];
            }
        }
        if (sum >= 200) res += (unsigned long long) sum;
    }
    printf("%lld\n", res);
}