#include <iostream>
#include <string>

using namespace std;

int N, m, pile1, pile2;
string str;

int main() {
    scanf("%d", &N);
    while(1) {
        while(N--) {
            cin >> str;
            scanf("%d", &m);
            if (str == "DROP") {
                printf("DROP 2 %d\n", m);
                pile2 += m;

            }
            else {
                if (pile1 > 0) {
                    if (m <= pile1) {
                        printf("TAKE 1 %d\n", m);
                        pile1 -= m;
                    }
                    else {
                        printf("TAKE 1 %d\n", pile1);
                        m -= pile1;
                        printf("MOVE 2->1 %d\n", pile2);
                        pile1 = pile2;
                        pile2 = 0;
                        printf("TAKE 1 %d\n", m);
                        pile1 -= m;
                    }

                }
                else {
                    printf("MOVE 2->1 %d\n", pile2);
                    pile1 += pile2;
                    pile2 = 0;
                    printf("TAKE 1 %d\n", m);
                    pile1 -= m;
                }

            }
        } 
        pile1 = 0;
        pile2 = 0;
        scanf("%d", &N);
        if (!N) break;
        printf("\n");
    }
}