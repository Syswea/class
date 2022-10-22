#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main () {
    ios::sync_with_stdio (false);
    cin.tie (nullptr);
    int N; cin >> N;
    vector<pair<double, pair<int, string>>> v(N);
    for (int i = 0; i < N; i ++ ) {
        cin >> v[i].second.second;
        v[i].second.first = i;
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        v[i].first = a * 90 + (b + c) * 9 + (d * 1);
        v[i].first *= -1;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i ++ ) cout << v[i].second.second << '\n' ;
}