#include <bits/stdc++.h>
using namespace std;

struct stack {
    int cnt;
    int *a;
    stack(int n) {
        a = (int*) malloc(sizeof (int) * n);
        cnt = 0;
    }
    void push (int x) {
        a[++ cnt] = x;
    }
    void pop () {
        cnt -- ;
    }
    int top () {
        return a[cnt];
    }
};

int main () {
    return 0;
}