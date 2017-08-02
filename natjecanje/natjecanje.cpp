#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int N, S, R;
    cin >> N >> S >> R;
    int arr[N], damaged[N], reserves[N];
    memset(arr, 0, sizeof(arr));
    memset(damaged, 0 , sizeof(damaged));
    memset(reserves, 0, sizeof(reserves));
    while (S--) {
        int i;
        cin >> i;
        damaged[i-1] = 1;
    }
    while (R--) {
        int i;
        cin >> i;
        reserves[i-1] = 1;
    }
    for (int i = 0; i < N; i++) {
        if (damaged[i] == 0 && reserves[i] == 1) arr[i] = 2;
        else if (damaged[i] == 0) arr[i] = 1;
        else if (damaged[i] == 1 && reserves[i] == 1) arr[i] = 1;
    }
    for (int i = 0; i < N; i++) {
        if (arr[i] == 2) {
            if (i == 0 && arr[1] == 0) arr[1] = 1;
            else if (i == N-1 && arr[N-2] == 0) arr[N-2] = 1;
            else {
                if (arr[i-1] == 0) arr[i-1] = 1;
                else if (arr[i+1] == 0) arr[i+1] = 1;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (!arr[i]) cnt++;
    }
    cout << cnt << endl;

}