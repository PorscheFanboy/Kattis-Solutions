#include <iostream>

using namespace std;

long T, n, x, y, w, h;

int rec(long x, long y, long N) {
    if (N == 1) {
        return 1;
    }
    else if (x > (N/2-1) && y > (N/2-1)) {
        return -rec(x-N/2, y-N/2, N/2);
    }
    else {
        return rec(x % (N/2), y % (N/2), N/2); 
    }
}


int main() {
    cin >> T;
    while (T--) {
        cin >> n >> x >> y >> w >> h;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                printf("%d ", rec(x+j, y+i, n)); 
            }
            cout << endl;
        }
        if (T > 0) cout << endl;
    }
}