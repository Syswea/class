#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ver(n + 1);
    for (int i = 1; i <= m; i ++ ) {
        int a, b;
        cin >> a >> b;
        ver[a].push_back(b);
        ver[b].push_back(a);
    }

    int flag = 1;
    vector<int> color(n + 1, 0);
    function<int(int, int)> dfs = [&](int u, int v) {
        color[u] = v;
        for (int i = 0; i < (int)ver[u].size(); i ++ ) {
            int j = ver[u][i];
            if (color[j] == 0) {
                if (dfs(j, 3 - v) == 0) return 0;
            }
            else if (color[j] == v) return 0;
        }
        return 1;
    };
    for (int i = 1; i <= n; i ++ ) {
        if (color[i] == 0) {
            if (dfs(i, 1) == 0) {
                flag = 0;
                break;
            }
        }
    }

    cout << (flag? "Yes": "No") << endl;
    return 0;
}
