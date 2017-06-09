#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, arr[50];
bool pick[50];

long long res;
long long table[30];

int thres;

void generate(int at) {
    if (at == N) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            if (pick[i]) {
                sum += arr[i];
            }
        }
        if(sum >= 200) res += sum;
    }
    else {
        pick[at] = true;
        int sum = 0;
        for (int i = 0; i <= at; i++) {
            if (pick[i]) sum += arr[i];
        }
        if (at >= thres && sum >= 200) {
            res += (((long long) sum) * (((long long) 1) << (N-at-1)) + table[N-at-2]);
        }
        else {
            generate(at+1);
        }

        pick[at] = false;
        sum -= arr[at];
        if (at >= thres && sum >= 200) {
            res += (((long long) sum) * (((long long) 1) << (N-at-1)) + table[N-at-2]);
        }
        else {
            generate(at+1);
        }

    }

}

int main() {
    cin >> N;
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N, greater<int>());
    res = 0;
    if (N < 23) {
        long long k = ((long long) 1) << N;
        for (long long i = 1; i < k; i++) {
            int sum = 0;
            for (int j = 0; j < N; j++) {
                long long m = ((long long) 1) << j;
                if (i & m) {
                    sum += arr[j];
                }
            }
            if (sum >= 200) res += (long long) sum;
        }
    }
    else {
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

        thres = N - 21;

        generate(0);
    }

    printf("%lld\n", res);
}