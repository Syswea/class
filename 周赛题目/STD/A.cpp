#include <bits/stdc++.h>
using namespace std;
#define int long long
void Sol () {
    int N, M; cin >> N >> M;
    vector<int> Edg[N + 1];
    for (int i = 1; i <= M; i ++ ) {
        int u, v; cin >> u >> v;
        Edg[u].push_back(v);
    }
    int S, T; cin >> S >> T;
    vector<int> St(N + 1, 0), Dist(N + 1, 0);
    function<void()> Dijkstra = [&] () {
        Dist[S] = -1;
        for (int i = 1; i < N; i ++ ) {
            int t = -1;
            for (int j = 1; j <= N; j ++ )
                if (St[j] == 0 && (t == -1 || Dist[t] > Dist[j]))
                    t = j;
            for (int v: Edg[t])
                Dist[v] = min (Dist[v], Dist[t] - 1);
            St[t] = 1;
        }
        return (St[T]? -Dist[T]: -1);
    }; Dijkstra ();
    cout << Dist[T] << '\n' ;
}
signed main () {
    ios::sync_with_stdio (false);
    cin.tie (nullptr);
    // int _; cin >> _;
    // while (_ -- )
        Sol ();
}
