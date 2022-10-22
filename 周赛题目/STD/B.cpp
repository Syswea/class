#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main () {
    ios::sync_with_stdio (false);
    cin.tie (nullptr);
    string N; cin >> N;
    int K; cin >> K;
    vector<int> f;
    f.push_back(1);
    f.push_back(1);
    set<pair<int, int>> St;
    St.insert({1, 1});
    for (int i = 2; i <= 20000; i ++ ) {
        f.push_back((f[i - 1] + f[i - 2]) % K);
        if (St.find({f[i - 1], f[i]}) == St.end())
            St.insert({f[i - 1], f[i]});
        else break;
    }
    int res = 0;
    for (int i = 0; i < N.size(); i ++ )
        res *= 10, res = (res + N[i] - '0') % f.size();
    cout << f[res] << '\n' ;
}
