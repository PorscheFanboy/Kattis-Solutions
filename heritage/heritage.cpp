#include <iostream>
#include <string>
#include <map>

using namespace std;

int N;
string W;
map<string, long long> aMap, dpMap;

long long dp(string str) {
    long long count = 0;
    if (str == "") return 1;
    for (int i = 1; i <= str.length(); i++) {
        string ss = "";
        string rr = "";
        for (int j = 0; j < i; j++) {
            ss.push_back(str.at(j));
        }
        for (int j = i; j < str.length(); j++) {
            rr.push_back(str.at(j));
        }
        if (aMap.find(ss) != aMap.end()) {
            if (dpMap.find(rr) != dpMap.end()) count += aMap[ss] * dpMap[rr];
            else count += aMap[ss] * dp(rr);
        }
    }
    dpMap[str] = count;
    return count;
}

int main() {
    scanf("%d", &N);
    cin >> W;
    while (N--) { 
        long long x;
        string str;
        cin >> str;
        cin >> x;
        aMap[str] = x;
    }
    long long ans = dp(W);
    printf("%lld\n", ans % 1000000007);


}