#include <iostream>

using namespace std;

int K, N, arr[10000];
double EPS = 1e-12;

int main() {
    scanf ("%d %d\n", &K, &N);
    int max = 0;
    for (int i = 0; i < K; i++) {
        scanf("%d", arr+i);
        if (arr[i] > max) max = arr[i];
    }
    double hi = (double) max;
    double lo = 0.0;
    int cuts = 0;
    int pieces = 0;
    while (hi - lo > EPS) {
        double mid = (hi + lo) / 2.0;
        cuts = 0;
        pieces = 0;
        for (int i = 0; i < K; i++) {
            int x = (int) (double (arr[i]) / mid);
            pieces += x;
            if (x == 1 && (double) arr[i] - mid < 1e-8) {

            }
            else if (x == 1) cuts += 1;
            else if ((double) arr[i] - (double) x * mid < 1e-7) {
                cuts += x - 1;
            }
            else {
                cuts += x;
            }
        }
        if (pieces >= N) {
            lo = mid - 1e-10;
            hi -= 1e-10;
        }
        else {
            hi = mid + 1e-10;
        }

    }
    printf("%d\n", cuts);
}