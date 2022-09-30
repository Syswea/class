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
int C[100][100] = {};
int mod = 998244353;
void solve () {
    int n; cin >> n;
    int a = 0, b = 0;
    a = C[n - 1][n / 2];
    a = (a + C[n - 3][n / 2 - 2]) % mod;
    a = (a - 1 + mod) % mod;
    b = ((C[n][n / 2] - a - 1) % mod + mod) % mod;
    cout << "cout : " << a << ' ' << b << ' ' << 1 << endl;
    return ;
}
signed main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    for (int i = 0; i <= 60; i ++ )
        for (int j = 0; j <= i; j ++ )
            if (j == 0 || i == j) C[i][j] = 1;
            else C[i][j] = C[i - 1][j] + C[i - 1][j - 1] % mod;
    
    int tt; cin >> tt;
    while (tt -- )
        solve();
    return 0;
}