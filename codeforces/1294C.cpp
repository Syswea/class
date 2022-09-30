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
    int k; cin >> k;
    for (int i = 2; i <= k / i; i ++ ) {
        if (k % i != 0) continue;
        for (int j = i + 1; j <= k / i / j; j ++ ) {
            if (k / i % j != 0 || k / i / j == i || k / i / j == j) continue;
            cout << "YES" << endl;
            cout << i << ' ' << j << ' ' << k / i / j << endl;
            return ;
        }
    }
    cout << "NO" << endl;
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