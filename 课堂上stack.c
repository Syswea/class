#include <stdlib.h>
#include <stdio.h>

typedef struct Node * PNode;
struct Node {
    int x;
    PNode nt;
};

PNode new () {
    PNode p = (PNode) malloc (sizeof (struct (Node));
    return p;
}


typedef struct stack_l * pstack_l;
struct stack_l {
    int cnt;
    PNode a;
    int isempty () {
        return (cnt <= 0);
    }
    void push (int x) {
        a;
}

pstack_l create (int m) {
    return psl;
}


typedef struct stack_seq sstack;
struct stack_seq {
    int n;
    int * a;
    void create (int k) {
        a = (int *) malloc(sizeof (int) * n);
        if (a == NULL) {
            printf ("out of space\n");
        }
        else {
            n = k;
            for (int i = 0; i < n; i ++ )
                scanf ("%d", a + i);
        }
    };
    int isempty () {
        return (n <= 0);
    }
    void push (int x) {
        a[n ++ ] = x;
    }
    void pop () {
        n -- ;
    }
    int top () {
        return a[n - 1];
    }
    int size () {
        return n;
    }
};

int main () {
    return 0;
}
