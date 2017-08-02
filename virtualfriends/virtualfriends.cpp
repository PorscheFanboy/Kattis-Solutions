#include <vector>
#include <iostream>
#include <map>
#include <cstring>

using namespace std;

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct union_find {
    vector<int> parent;
    union_find(int n) {
        parent = vector<int>(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        } else {
            parent[x] = find(parent[x]);
            return parent[x];
        }
    }

    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }
};

int main() {
    use_io_optimizations();
    int N, M;
    string s1, s2;
    cin >> N;
    while (N--) {
        cin >> M;
        int cnt = 0;
        map<string, int> aMap;
        union_find *UF = new union_find(2*M);
        int arr[2*M];
        for (int i = 0; i < 2*M; i++) arr[i] = 1;
        while (M--) {
            cin >> s1 >> s2;
            if (aMap.find(s1) == aMap.end()) {
                aMap.insert(make_pair(s1, cnt));
                cnt++;
            }
            if (aMap.find(s2) == aMap.end()) {
                aMap.insert(make_pair(s2, cnt));
                cnt++;
            }
            int c1 = aMap[s1];
            int c2 = aMap[s2];
            int iS1 = UF->find(c1);
            int iS2 = UF->find(c2);
            if (iS1 == iS2) {
                cout << arr[iS1] << "\n";
                continue;
            }
            int total = arr[iS1] + arr[iS2];
            UF->unite(c2, c1);
            arr[UF->find(c1)] = total;
            cout << total << "\n";
        }
        delete UF;
    }
}