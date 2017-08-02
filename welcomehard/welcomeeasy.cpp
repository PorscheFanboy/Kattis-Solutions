#include <iostream>

using namespace std;

long long memo[505][20];

long long rec(int j, int k, string &str, string &wel) {
    if (memo[j][k] != -1) return memo[j][k];
    if (k == wel.size()) return 1;
    long long res = 0;
    for (int i = j; i < str.size(); i++) {
        if (str.size() - i < wel.size() - k) break;
        if (str.at(i) == wel.at(k)) {
            long long l = rec(i+1, k+1, str, wel);
            res += l;
        }
    }
    memo[j][k] = res;
    return res;
}

int main() {
    int T;
    string str;
    string wel = "welcome to code jam";
    cin >> T;
    cin.ignore();
    for (int ca = 1; ca <= T; ca++) {
        for (int i = 0; i < 505; i++)
            for (int j = 0; j < 20;j++)
                memo[i][j] = -1;
        cout << "Case #" << ca << ": ";
        getline(cin, str);
        long long res = rec(0, 0, str, wel);
        string rString = to_string(res);
        if (rString.size() >= 4) {
            for (int i = 0; i < rString.size(); i++) {
                if (rString.size() - i <= 4) cout << rString.at(i);
            }
        }
        else if (rString.size() == 3) cout << "0" << rString;
        else if (rString.size() == 2) cout << "00" << rString;
        else if (rString.size() == 1) cout << "000" << rString;
        cout << "\n";
    }
}