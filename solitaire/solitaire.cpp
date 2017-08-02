#include <iostream>

using namespace std;

int N, arr[8589934592];
char board[5][9];

int main() {
    scanf("%d\n", &N);
    while(N--) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%c", &board[i][j]);
            }
            scanf("\n");
        }
        
        scanf("\n");
    }
}
