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
    int n; cin >> n;
    int cnt[10] = {};
    for (int i = 0; i < n; i ++ ) {
        int k; cin >> k;
        cnt[k] ++ ;
    }
    int ans = 0;
    ans += cnt[4], cnt[4] = 0;
    if (cnt[3] > cnt[1]) ans += cnt[3], cnt[3] = cnt[1] = 0;
    else ans += cnt[3], cnt[1] -= cnt[3], cnt[3] = 0;
    ans += cnt[2] / 2, cnt[2] %= 2;
    if (cnt[2] > 0) ans += 1, cnt[1] -= 2;
    if (cnt[1] > 0) ans += (cnt[1] + 3) / 4;
    cout << ans << endl;
    return ;
}
signed main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    // int tt; cin >> tt;
    // while (tt -- )
        solve();
    return 0;
}