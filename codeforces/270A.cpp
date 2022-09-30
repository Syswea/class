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
set<int> ans;
void solve () {
    int angl; cin >> angl;
    if (ans.find(angl) != ans.end()) cout << "YES" << endl;
    else cout << "NO" << endl;
    return ;
}
signed main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    for (int i = 3; i <= 10000; i ++ ) {
        int tmp = 180 * (i - 2);
        if (tmp % i == 0) ans.insert(tmp / i);
    }
    int tt; cin >> tt;
    while (tt -- )
        solve();
    return 0;
}