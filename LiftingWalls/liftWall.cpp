#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

typedef pair<int, int> ii;

int l, w, n, r, in[30];
double L, W;
ii arr[30];

int rec(int j, int m) {
    if (m == 0) {
        int bm = 0;
        for (int i = 0; i < n; i++) {
            if (in[i]) {
                int x = arr[i].first;
                int y = arr[i].second;
                double dist;
                dist = sqrt(pow((L-x), 2) + pow(y, 2));
                if (dist <= r) bm |= (1 << 0);
                dist = sqrt(pow(-L-x, 2) + pow(y, 2)); 
                if (dist <= r) bm |= (1 << 1);
                dist = sqrt(pow(x, 2) + pow(W-y, 2));
                if (dist <= r) bm |= (1 << 2);
                dist = sqrt(pow(x, 2) + pow(-W-y, 2));
                if (dist <= r) bm |= (1 << 3);
            }
        }

        if (bm == 15) return 1;
        else return 0;
    }
    for (int i = j; i <= n-m; i++) {
        // if (i > j+1) in[i-1] = 0;
        in[i] = 1; 
        if (rec(i+1, m-1)) return 1;
        in[i] = 0;
    }
    return 0;
}

int main() {
    scanf("%d %d %d %d", &l, &w, &n, &r);
    L = ((double) l) / 2.0;
    W = ((double) w) / 2.0;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        ii p = make_pair(x, y);
        arr[i] = p;
    }
    memset(in, 0, sizeof(in));
    for (int i = 1; i <= 4; i++) {
        if (rec(0, i)) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("Impossible\n");
}