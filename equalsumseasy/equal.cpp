#include <iostream>
#include <cstring>

using namespace std;

int T, arr[20], N, memo[2100000];

int main() {
    cin >> T;
    for (int ca = 1; ca <= T; ca++) {
        printf("Case #%d:\n", ca);
        scanf("%d", &N);
        for (int i = 0; i < 20; i++) {
            scanf("%d", arr+i);
        }
        memset(memo, 0, sizeof(memo));
        int k = 1 << 20;
        for(int subset = 1; subset < k; subset++) {
            int sum = 0;
            for (int i = 0; i < 20; i++) {
                if ((subset & (1 << i)) != 0) {
                    sum += arr[i];
                }
            }
            int m = memo[sum];
            if (m != 0) {
                for (int i = 0; i < 20; i++) {
                    if ((subset & (1 << i)) != 0) {
                        printf("%d ", arr[i]);
                    }
                }
                printf("\n");
                for (int i = 0; i < 20; i++) {
                    if ((m & (1 << i)) != 0) {
                        printf("%d ", arr[i]);
                    }
                }
                printf("\n");
                break;
            }
            else {
                memo[sum] = subset;
            }
            if (subset == k-1) {
                printf("Impossible\n");
            }

        }
    }

}