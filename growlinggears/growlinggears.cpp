#include <iostream>

using namespace std;

int cases, n, a, b, c;

int main() {
    scanf("%d\n", &cases);
    while (cases--) {
        scanf("%d\n", &n);
        double max = 0.0;
        int gear = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d %d %d\n", &a, &b, &c);
            double x = (double) b / (2.0 * (double) a);
            double y = - ((double) a) * x * x + ((double) b) * x + ((double) c);
            if (y > max) {
                max = y;
                gear = i;
            }
        }
        printf("%d\n", gear);
    }

}