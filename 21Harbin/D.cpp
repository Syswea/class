#include <bits/stdc++.h>
using namespace std;
#define int long long

string S, T;
void Solve (string s, string t) {
    if (s.size() < S.size()) S = s, T = t;
    for (char x: s) for (char y: t) {
        if (x != y) continue;
        string _s = s, _t = t;
        s.erase(s.find(x));
        t.erase(t.find(y));
        int a = stoi(s), b = stoi(t);
        int c = stoi(_s), d = stoi(_t);
        if (a * d == c * d) Solve (s, t);
        s = _s, t = _t;
    }
}

signed main () {
    ios::sync_with_stdio (false);
    cin.tie (nullptr);
    int _; cin >> _;
    while (_ -- ) {
        cin >> S >> T;
        Solve (S, T);
        cout << S << ' ' << T << '\n' ;
    }
    return 0;
}