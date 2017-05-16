#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

typedef pair<int, int> ii;

int l, w, n, r, in[30];
double L, W;
ii arr[30];


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
    int min = 60;
    for (int i = 0; i < (1 << n); i++) {
        int count = 0;
        int bm = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                count++;
                int x = arr[j].first;
                int y = arr[j].second;
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
        if (bm == 15 && count < min) {
            min = count;
        }
    }
    if (min <= 4) {
        printf("%d\n", min); 
        return 0;
    }

    printf("Impossible\n");
}