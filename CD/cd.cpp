#include <iostream>
#include <set>

using namespace std;

int main() {
    int N, M, x;
    set<int> aSet;
    while(1) {
        aSet.clear();
        scanf("%d %d\n", &N, &M);
        if (!N) break;
        while(N--) {
            scanf("%d\n", &x);
            aSet.insert(x);
        }
        int count = 0;
        while(M--) {
            scanf("%d\n", &x);
            if (aSet.find(x) != aSet.end()) {
                count++;
            }
        }
        printf("%d\n", count);
    }
}