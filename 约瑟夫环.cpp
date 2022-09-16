#include <iostream>
using namespace std;
int main () {
    int n, m, k;
    cin >> n >> m >> k;
    int cnt = 0, alive = n;
    int vis[10000] = {};
    for (int i = 0; alive > k; i = (i + 1) % n) {
        if (vis[i] == 1) continue;
        cnt ++ ;
        if (cnt == m) {
            cnt = 0;
            vis[i] = 1;
            cout << i + 1 << ' ';
            alive -- ;
        }
    }cout << '\n';
    for (int i = 0; i < n; i ++ ) {
        if (vis[i] == 0) cout << i + 1 << ' ';
    }cout << '\n';
    return 0;
}