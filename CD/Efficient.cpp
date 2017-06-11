#include <iostream>
#include <cstring>

using namespace std;

bool arr[1000000002];


int main() {
    int N, M, x;
    while(1) {
        // int *arr = new int[1000000002];
        scanf("%d %d\n", &N, &M);
        if (!N) break;
        memset(arr, false, sizeof(arr));
        while(N--) {
            scanf("%d\n", &x);
            arr[x] = true;
        }
        int count = 0;
        while(M--) {
            scanf("%d\n", &x);
            if (arr[x]) {
                count++;
            }
        }
        printf("%d\n", count);
        // delete[] arr;
    }

}