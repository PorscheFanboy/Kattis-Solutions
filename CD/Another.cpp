#include <iostream>
#include <cstring>

using namespace std;

int Jack[1000001], Jill[1000001];

int main() {
    int N, M;
    while(1) {
        scanf("%d %d\n", &N, &M);
        if (!N) break;
        memset(Jack, 0, sizeof(Jack));
        memset(Jill, 0, sizeof(Jill));
        for(int i = 0; i < N; i++) {
            scanf("%d\n", Jack+i);
        }
        for(int i = 0; i < M; i++) {
            scanf("%d\n", Jill+i);
        }
        int i = 0;
        int j = 0;
        int count = 0;
        while(i < N && j < M) {
            if (Jack[i] == Jill[j]) {
                count++;
                i++;
                j++;
            }
            else if (Jack[i] < Jill[j]) {
                i++;
            }
            else if (Jack[i] > Jill[j]) {
                j++;
            }
        }
        printf("%d\n", count);
    }

}