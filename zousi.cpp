#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio (false);
    cin.tie (nullptr);
    int N; cin >> N;
    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; i ++ ) cin >> v[i].first >> v[i].second;
    auto chk = [&] (int i, int j, int k, int t) {
        if (v[i] == v[j] || v[i] == v[k] || v[i] == v[t]
        || v[j] == v[k] || v[j] == v[t] || v[k] == v[t]) return false;
        int ax, ay, bx, by;
        ax = v[i].first - v[j].first;
        ay = v[i].second - v[j].second;
        bx = v[k].first - v[j].first;
        by = v[k].second - v[j].second;
        if (ax * by == bx * ay) return false;
        ax = v[k].first - v[t].first;
        ay = v[k].second - v[t].second;
        if (ax * by == bx * ay) return false;
        bx = v[i].first - v[t].first;
        by = v[i].second - v[t].second;
        if (ax * by == bx * ay) return false;
        ax = v[j].first - v[t].first;
        ay = v[j].second - v[t].second;
        if (ax * by == bx * ay) return false;
        return true;
    };
    int cnt = 0;
    for (int i = 0; i < N; i ++ )
        for (int j = i + 1; j < N; j ++ )
            for (int k = j + 1; k < N; k ++ )
                for (int t = k + 1; t < N; t ++ )
                    if (chk (i, j, k, t)) cnt ++ ;
    cout << cnt << '\n' ;
}