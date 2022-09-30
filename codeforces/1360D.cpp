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
    int n, k; cin >> n >> k;
    // cout << "cout : " ;
    vector<int> f; f.reserve(sqrt(n));
    if (k >= n) {
        cout << 1 << endl;
        return ;
    }
    for (int i = 1; i <= n / i; i ++ )
        if (n % i == 0) {
            f.push_back(i);
            f.push_back(n / i);
        }
    sort(f.begin(), f.end());
    auto iter = upper_bound(f.begin(), f.end(), k);
    iter = prev(iter);
    cout << n / (*iter) << endl;
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