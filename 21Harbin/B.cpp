#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; i ++ ) cin >> A[i];
    int Ans = 0;
    for (int k = 2; k <= 200; k ++ ) {
        vector<int> Mp(200, 0);
        vector<int> f(N + 1, 0);
        for (int i = 1; i <= N; i ++ ) {
            if (k <= A[i]) {
                f[i] = max(f[i], f[i - 1]);
                continue;
            }
            int Tmp = k - A[i];
            if (Mp[Tmp] != 0) {
                int j = Mp[Tmp];
                f[i] = max(f[i], f[j - 1] + 2);
            }
            f[i] = max(f[i], f[i - 1]);
            Mp[A[i]] = i;
        }
        Ans = max(Ans, f[N]);
        f = vector<int> (N + 1, 0);
        Mp.clear();
    }
    cout << Ans << '\n' ;
    return 0;
}
