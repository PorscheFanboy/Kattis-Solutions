#include <iostream>
#include <algorithm>

using namespace std;

int T, n, arr1[800], arr2[800];

int main() {
    // freopen("minScalarTest.txt", "r", stdin);
    cin >> T;
    for(int ca = 1; ca <= T; ca++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            scanf("%d", arr1+i);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", arr2+i);
        }
        sort(arr1, arr1+n, less<int>());
        sort(arr2, arr2+n, greater<int>());
        long long int pro = 0;
        for (int i = 0; i < n; i++) {
            pro += ((long long) arr1[i])* ((long long) arr2[i]);
        }
        printf("Case #%d: %lld\n", ca, pro);
    }
}