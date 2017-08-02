#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, l, w;
    pair<double, double> *arr_ii = new pair<double, double>[10000];
    while (cin >> n >> l >> w) {
        for (int i = 0; i < n; i++) {
            int a, b;
            scanf("%d %d\n", &a, &b);
            arr_ii[i] = make_pair((double) a, (double) b);
        }
        double current = 0.0;
        int count = 0;
        while (current < (double) l) {
            double next = current;
            int ind = 0;
            for (int i = 0; i < n; i++) {
                double x = sqrt(pow(arr_ii[i].second,2)-(pow(((double) w),2)/4.0));
                if (arr_ii[i].first - x > current) continue;
                if (arr_ii[i].first + x > next) {
                    ind = 1;
                    next = arr_ii[i].first + x;
                }
            }
            if (!ind) goto impossible;
            current = next;
            count++;
        }
        printf("%d\n", count);
        continue;
        impossible:
            printf("-1\n");
    }
}