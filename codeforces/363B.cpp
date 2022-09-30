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
    vector<int> A(n + 1, 0);
    for (int i = 1; i <= n; i ++ ) {
        cin >> A[i];
        A[i] += A[i - 1];
    }
    int pos = 1;
    for (int i = 1; i + k - 1 <= n; i ++ ) {
        int j = i + k - 1;
        if (A[pos + k - 1] - A[pos - 1] > A[j] - A[i - 1])
            pos = i;
    }
    cout << pos << endl;
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