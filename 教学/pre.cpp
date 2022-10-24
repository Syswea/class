//https://www.luogu.com.cn/problem/P6568
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main () {
    int N, K;
    cin >> N >> K;
    int S[N + 1] = {}, A[N + 1] = {};
    for (int i = 1; i <= N; i ++ ) cin >> A[i];
    for (int i = 1; i <= N; i ++ ) S[i] = S[i - 1] + A[i];
    int Ans = 0;
    for (int i = 1; i <= N; i ++ )
        Ans = max (Ans, S[i] - S[max (i - K - 1, 0ll)]);
    cout << Ans << '\n' ;
    return 0;
}