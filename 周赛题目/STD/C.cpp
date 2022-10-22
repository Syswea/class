#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main () {
    ios::sync_with_stdio (false);
    cin.tie (nullptr);
    int N; cin >> N;
    vector<int> Edg[N + 1];
    for (int i = 1; i < N; i ++ ) {
        int u; cin >> u;
        Edg[u].push_back(i + 1);
    }
    vector<int> A(N + 1);
    for (int i = 1; i <= N; i ++ ) cin >> A[i];

    vector<int> Calc(40);
    Calc[0] = 1;
    for (int i = 1; i <= 30; i ++ ) Calc[i] = Calc[i - 1] * 2;

    vector<int> Dp(N + 1, 1e7 + 10), Dep(N + 1, 0);
    int Sta[N + 1] = {}, top = 0;
    function<void(int, int)> Solve = [&] (int u, int p) {
        Sta[++ top] = u;
        Dep[u] = Dep[p] + 1;
        for (int v: Edg[u]) Solve (v, u);
        if (Edg[u].empty()) Dp[u] = 0;
        top -- ;
        for (int i = 0; i < 30 && top - i > 0; i ++ ) {
            int j = top - i;
            Dp[j] = min (Dp[j], Dp[u] + Calc[Dep[j] - Dep[u] - 1] * A[u]);
        }
    }; Solve (1, 0);
    cout << Dp[1] << '\n' ;
}
