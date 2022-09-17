#include <bits/stdc++.h>
using namespace std;

const int N = 10010;
vector<int> ver(N);
vector<int> dp(N);

void solve (int k) {
    for (int i = 0; i < ver[k].size(); i ++ ) solve(ver[k][i]);
    int sum = 0;
    for (int i = 0; i < 1 << ver[k].size(); i ++ ) {
        int num = 1;
        for (int j = 0; j < ver[k].size(); j ++ )
            if (i >> j & 1) num *= dp[ver[k][j]];
        sum += num;
    }
    dp[k] = sum;
}

int main () {
    int n;
    cin >> n;
    for (int i = 1; i < n; i ++ ) {
        int x, y;
        cin >> x >> y;
        vec[x].push_back(y);
    }
    solve(1);
    cout << dp[1] << endl;
}