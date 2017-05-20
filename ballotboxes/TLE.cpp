#include <iostream>

using namespace std;

int N, B, arr[500000];

int helper(int k) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int x = (arr[i] + k - 1) / k; 
        sum += x;
        if (sum > B) return 0;
    }
    return 1;

}

int main() {
    while (1) {
        cin >> N >> B;
        if (N == -1) break;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        for (int i = 1; i < 5000000; i++) {
            int b = helper(i);
            if (b) {
                cout << i << endl;
                break;
            }
        }


        cin.ignore();
    }
}

