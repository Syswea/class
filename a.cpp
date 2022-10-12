#include <bits/stdc++.h>
using namespace std;

const int N = 310;

int n;
int A[N], f[N][N];

int main () {
    cin >> n;
    
    memset(f, 0x3f, sizeof f);
    
    for (int i = 1; i <= n; i ++ ) {
        cin >> A[i];
        f[i][i] = A[i];
    }
    
    for (int k = 2; k <= n; k ++ ) {
        for (int i = 1; i + k - 1 <= n; i ++ ) {
            cout << i << ":  " ;
            for (int j = i; j < i + k - 1; j ++ ) {
                f[i][i + k - 1] = min(f[i][i + k - 1], f[i][j] + f[j + 1][i + k - 1]);
                cout << j << ' ' ;
            }
            cout << endl;
            cout << "pos:  " << i << ' ' << i + k - 1 << ' ' << f[i][i + k - 1] << endl;
        }
    }
    // cout << f[1][n] << endl;
    cout << "f[i][j]:  \n" ;
    for (int i = 1; i <= n; i ++ ) {
        for (int j = i; j <= n; j ++ )
            cout << f[i][j] << ' ' ;
        cout << endl;
    }
    ;;
    return 0;
}