#include <iostream>
#include <cstring>

using namespace std;

int n, board;
char arr[9000000];
char c;

int moveRight(int b, int i) {
    b &= ~(1 << i);
    b &= ~(1 << (i-1));
    b |= (1 << (i-2));
    return b;
}

int moveLeft(int b, int i) {
    b &= ~(1 << i);
    b &= ~(1 << (i+1));
    b |= (1 << (i+2));
    return b;
}


int dp(int b) {
    int m = 32;
    int mm = 0;
    int count = 0;
    for (int i = 22; i >= 0; i--) {
        if (!(b & (1 << i))) continue;
        if (i > 20) {
            if ((b & (1 << i-1)) && !(b & (1 << i-2))) {
                count++;
                int newBoard = moveRight(b, i);
                if ((int) arr[newBoard] != 0) mm = (int) arr[newBoard];
                else mm = dp(newBoard);
                arr[newBoard] = (char) mm;
                if (mm < m) m = mm;
            }
        }
        else if (i < 2) {
            if ((b & (1 << i+1)) && !(b & (1 << i+2))) {
                count++;
                int newBoard = moveLeft(b, i);
                if ((int) arr[newBoard] != 0) mm = (int) arr[newBoard];
                else mm = dp(newBoard);
                arr[newBoard] = (char) mm;
                if (mm < m) m = mm;
            }
        }
        else {
            if ((b & (1 << i-1)) && !(b & (1 << i-2))) {
                count++;
                int newBoard = moveRight(b, i);
                if ((int) arr[newBoard] != 0) mm = (int) arr[newBoard];
                else mm = dp(newBoard);
                arr[newBoard] = (char) mm;
                if (mm < m) m = mm;
            }
            if ((b & (1 << i+1)) && !(b & (1 << i+2))) {
                count++;
                int newBoard = moveLeft(b, i);
                if ((int) arr[newBoard] != 0) mm = (int) arr[newBoard];
                else mm = dp(newBoard);
                arr[newBoard] = (char) mm;
                if (mm < m) m = mm;
            }
        }
    }
    if (!count) {
        int ret = 0;
        for (int i = 0; i < 23; i++) {
            if (b & (1 << i)) ret++;
        }
        return ret;
    }
    else {
        return m;
    }
}

int main() {
    scanf("%d\n", &n);
    while(n--) {
        memset(arr, 0, sizeof(arr));
        board = 0;
        for(int i = 22; i >= 0; i--) {
            scanf("%c", &c);
            if (c == 'o') {
                board |= (1 << i); 
            }
        }
        printf("%d\n", dp(board));
        
        scanf("\n");
    }
}
