#include <iostream>

using namespace std;


int rec(int j, int k, string &str, string &wel, int memo[][20]) {
    if (memo[j][k] != -1) return memo[j][k];
    if (k == wel.size()) return 1;
    int res = 0;
    for (int i = j; i < str.size(); i++) {
        if (str.size() - i < wel.size() - k) break;
        if (str.at(i) == wel.at(k)) {
            int l = rec(i+1, k+1, str, wel, memo);
            res += l;
        }
    }
    memo[j][k] = res % 10000;
    return res % 10000;
}

int main() {
    int T;
    string str;
    string wel = "welcome to code jam";
    cin >> T;
    cin.ignore();
    int memo[501][20];
    for (int ca = 1; ca <= T; ca++) {
        for (int i = 0; i < 501; i++)
            for (int j = 0; j < 20;j++)
                memo[i][j] = -1;
        getline(cin, str);
        int res = rec(0, 0, str, wel, memo);
        printf("Case #%d: %04d\n", ca, res);
    }
}