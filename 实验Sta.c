#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int *A;
    int top;
    int MaxNum;
};

typedef struct Stack* pStack;
pStack init (int cnt) {
    pStack sta;
    sta = (struct Stack*) malloc (sizeof (struct Stack));
    if (sta == NULL) {
        printf ("Can not Creat Stack\n");
        return NULL;
    }
    sta -> A = (int*) malloc (sizeof (int) * cnt);
    if (sta -> A == NULL) {
        printf ("Can not Creat Stack\n");
        return NULL;
    }
    sta -> MaxNum = cnt;
    sta -> top = -1;
    return sta;
}
int isEmpty (pStack sta) {
    return sta -> top == -1;
}
int push (pStack sta, int x) {
    if (sta -> top >= sta -> MaxNum) {
        printf ("is Full\n");
        return 0;
    }
    sta -> A[++ sta -> top] = x;
    return 1;
}
int pop (pStack sta) {
    if (sta -> top == -1) {
        printf ("is Empty\n");
        return 0;
    }
    sta -> top -- ;
    return 1;
}
int top (pStack sta) {
    return sta -> A[sta -> top];
}
void Solve1 () {
    printf ("let x 10-ary change into k-ary\n");
    int x, k; scanf("%d%d", &x, &k);
    pStack sta = init (100);
    int has[1000];
    for (int i = 0; i <= 9; i ++ )
        has[i] = i + '0';
    for (int i = 10; i < k; i ++ )
        has[i] = i - 10 + 'A';
    if (sta == NULL) return ;
    while (x) {
        push(sta, has[x % k]);
        x /= k;
    }
    while (!isEmpty(sta)) {
        printf ("%c", top(sta));
        pop(sta);
    }puts("");
}
void Solve2 () {
    char s[10000]; scanf ("%s", s);
    int A[127] = {};
    A['*'] = A['/'] = 2;
    A['+'] = A['-'] = 1;
    char ans[10000], cnt = 0;
    pStack sta = init (100);
    for (int i = 0; i < strlen(s); i ++ ) {
        while ('0' <= s[i] && s[i] <= '9')
            ans[cnt ++ ] = s[i ++ ];
        if (i >= strlen(s)) break;
        ans[cnt ++] = ' ';
        while (!isEmpty(sta) && A[top(sta)] >= A[s[i]]) {
            ans[cnt ++] = (char)top(sta);
            ans[cnt ++] = ' ';
            pop(sta);
        }
        push(sta, s[i]);
    }
    while (!isEmpty(sta)) {
        ans[cnt ++] = ' ';
        ans[cnt ++] = (char)top(sta);
        pop(sta);
    }
    ans[cnt] = '\0' ;
    printf ("%s\n", ans);
}
int main () {
    // Solve1 ();
    // Solve2 ();
    return 0;
}