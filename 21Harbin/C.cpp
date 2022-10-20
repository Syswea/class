#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main () {

    int N; cin >> N;
    vector<int> Edg[N + 1], Col(N + 1, 0);
    for (int i = 1, u; i < N; i ++ ) cin >> u, Edg[u].push_back(i + 1);
    for (int i = 1; i <= N; i ++ ) cin >> Col[i];

    int St_Cnt = 0;
    vector<int> siz(N + 1, 0), St(N + 1, 0), Add(N + 1, 0), Mini(N + 1, 0);
    map<int, int> Dp[N + 1];
    function<void(int)> Find = [&] (int Par) {
        int Max_Son = 0;
        siz[Par] = 1;
        for (int u: Edg[Par]) {
            Find(u);
            siz[Par] += siz[u];
            if (siz[u] > siz[Max_Son]) Max_Son = u;
        }
        if (Max_Son == 0) St[Par] = ++ St_Cnt, Dp[St[Par]][Col[Par]] = 1, Mini[St[Par]] = 1;
        else {
            int kSt = St[Max_Son];
            St[Par] = kSt;
            Dp[kSt][0] = Mini[kSt];
            for (int v: Edg[Par]) {
                if (v == Max_Son) continue;
                int Val = Mini[St[v]] + Add[St[v]];
                for (auto T: Dp[St[v]]) {
                    int x = T.first, y = T.second;
                    if (x == 0) continue;
                    if (Dp[kSt].count(x))
                        Dp[kSt][x] = min(Dp[kSt][x], Dp[kSt][0] + 1),
                        Dp[kSt][x] += min(y - 1 + Add[St[v]], Val) - Val;
                    else Dp[kSt][x] = y + Add[St[v]] + Dp[kSt][0] - Val;
                    Mini[kSt] = min(Dp[kSt][x], Mini[kSt]);
                }
                Add[kSt] += Val;
            }
        }
    };
    Find (1);
    cout << Mini[St[1]] + Add[St[1]] << '\n' ;
    return 0;
}