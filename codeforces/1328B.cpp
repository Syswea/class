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
    int l, r;
    l = 2, r = n;
    while (l < r) {
        int p = l + r + 1 >> 1;
        int stu = (1 + p - 2) * (p - 2) / 2 + 1;
        if (stu <= k) l = p;
        else r = p - 1;
    }
    int fir = l;
    l = 1, r = n - 1;
    while (l < r) {
        int p = l + r + 1 >> 1;
        int stu = (1 + fir - 2) * (fir - 2) / 2 + p;
        if (stu <= k) l = p;
        else r = p - 1;
    }
    int sec = l;
    for (int i = n; i >= 1; i -- ) {
        if (i == fir || i == sec) cout << 'b' ;
        else cout << 'a';
    }
    cout << endl;
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