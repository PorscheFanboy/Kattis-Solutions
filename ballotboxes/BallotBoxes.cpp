#include <iostream>

using namespace std;

int N, B, arr[500000];

int helper(int k) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += (arr[i] + k - 1) / k; 
        if (sum > B) return 0;
    }
    return 1;
}

int bsearch(int j, int k) {
    int mid = (k+j) / 2;
    if (j == mid) return k;
    if (!helper(mid)) return bsearch(mid, k);
    else return bsearch(j, mid);
}

int main() {
    while (1) {
        scanf("%d %d", &N, &B);
        if (N == -1) break;
        int max = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d", arr+i);
            if (arr[i] > max) max = arr[i];
        }
        printf("%d\n", bsearch(1, max));
        cin.ignore();
    }
}