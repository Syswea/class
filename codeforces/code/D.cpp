#include <bits/stdc++.h>
using namespace std;
#define int long long
#define x first
#define y second
typedef pair<int, int> pii;
int fp(int a, int n) {int res = 0; while (n) {if (n & 1) res = res * a; a = a * a; n >>= 1;} return res;}
inline int read() {
    #ifndef gc
    #define gc() c=getchar()
    int x = 0, f = 0; char c; gc();
    for (; !isdigit(c); gc()) if (c == '-') f = 1;
    for (; isdigit(c); gc()) x = (x << 1) + (x << 3) + (c ^ '0');
    return f ? ~ x + 1: x;
    #endif
}
void solve () {
    int n, k;
    cin >> n >> k;
    vector<int> fa(n + 1, 0);
    fa[1] = 0;
    for (int i = 2; i <= n; i ++ ) cin >> fa[i];
    
    vector<vector<int>> e(n + 1);
    for (int i = 2; i <= n; i ++ ) {
        int j = fa[i];
        e[j].push_back(i);
    }
    int dep[n + 1] = {}, sdep[n + 1] = {};
    function<void(int, int)> dfs = [&] (int f, int x) {
        if (x == 1) dep[x] = 0;
        else dep[x] = dep[f] + 1;
        for (int i = 0; i < e[x].size(); i ++ ) {
            int j = e[x][i];
            dfs(x, j);
        }
    };
    dfs(1, 1);
    int l, r;
    function<int(int, int)> chk = (int u, int x) {
        for (int i = 0; i < e[u].size(); i ++ ) {
            int j = e[u][i];
            chk(j, x);
        }
        
    };
    l = 1, r = n - 1;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (chk(1, mid) <= k) l = mid;
        else r = mid - 1;
    }
    
    return ;
}
signed main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt;
    while (tt -- )
        solve();
    return 0;
}