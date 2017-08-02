#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, m, a, b, c;
vi dfs_num;
vector <vii> AdjList;

void dfs(int u) {
    for (int i = 0; i < (int) AdjList[u].size(); i++) {
        ii v = AdjList[u][i];
        // if (dfs_num[u] > v.second) dfs_num[u] = v.second;
        if (dfs_num[v.first] != -1) {
            if (dfs_num[v.first] > v.second) dfs_num[v.first] = v.second;
        }
        else {
            dfs_num[v.first] = v.second;
            dfs(v.first);
        }
    }
}

int main() {
    // freopen("c.txt", "r", stdin);
    cin >> n >> m;
    dfs_num.assign(n, -1);
    AdjList.assign(n, vii());
    while (m--) {
        scanf("%d %d %d", &a, &b, &c);
        AdjList[a].push_back(ii(b, c));
        AdjList[b].push_back(ii(a, c));
    }
    dfs_num[0] = 4000000000;
    dfs(0);

    int max = -1;
    for (int i : dfs_num) {
        if(i == -1) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        else if (i > max) max = i;
    }
    
    cout << max <<endl;
    return 0;
}