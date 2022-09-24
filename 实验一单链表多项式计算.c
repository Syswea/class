#include <stdlib.h>
#include <stdio.h>

typedef struct Node * PNode;

struct Node {
    int coef;
    int exp;
    PNode nt;
};

void inserthead(PNode res, int coef, int exp) {
    PNode p = (PNode) malloc(sizeof (struct Node));
    p -> nt = NULL;
    p -> coef = coef;
    p -> exp = exp;
    p -> nt = res -> nt;
    res -> nt = p;
}


void inserttail(PNode res, int coef, int exp) {
    PNode p = (PNode) malloc(sizeof (struct Node));
    p -> nt = NULL;
    p -> coef = coef;
    p -> exp = exp;

    PNode k = res;
    while (k -> nt != NULL) k = k -> nt;
    k -> nt = p;
}

PNode creatpoly(int n) {
    PNode res = (PNode)malloc(sizeof (struct Node));
    res -> nt = NULL;
    int coef, exp;
    for (int i = 0; i < n; i ++ ) {
        scanf ("%d%d", &coef, &exp);
        inserttail(res, coef, exp);
    }
    return res;
}

PNode add(PNode A, PNode B) {
    PNode res = (PNode) malloc(sizeof(struct Node));
    res -> nt = NULL;
    PNode a = A -> nt, b = B -> nt;
    while (a != NULL && b != NULL) {
        if (a -> exp < b -> exp) {
            inserttail(res, a -> coef, a -> exp);
            a = a -> nt;
        }
        else if (a -> exp > b -> exp) {
            inserttail(res, b -> coef, b -> exp);
            b = b -> nt;
        }
        else {
            int coef = a -> coef + b -> coef;
            int exp = a -> exp;
            a = a -> nt, b = b -> nt;
            if (coef) inserttail(res, coef, exp);
        }
    }
    while (a != NULL) {
        inserttail(res, a -> coef, a -> exp);
        a = a -> nt;
    }
    while (b != NULL) {
        inserttail(res, b -> coef, b -> exp);
        b = b -> nt;
    }
    return res;
}

PNode del(PNode A, PNode B) {
    PNode res = (PNode) malloc(sizeof(struct Node));
    res -> nt = NULL;
    PNode a = A -> nt, b = B -> nt;
    while (a != NULL && b != NULL) {
        if (a -> exp < b -> exp) {
            inserttail(res, a -> coef, a -> exp);
            a = a -> nt;
        }
        else if (a -> exp > b -> exp) {
            inserttail(res, 0 - (b -> coef), b -> exp);
            b = b -> nt;
        }
        else {
            int coef = a -> coef - b -> coef;
            int exp = a -> exp;
            a = a -> nt, b = b -> nt;
            if (coef) inserttail(res, coef, exp);
        }
    }
    while (a != NULL) {
        inserttail(res, a -> coef, a -> exp);
        a = a -> nt;
    }
    while (b != NULL) {
        inserttail(res, 0 - (b -> coef), b -> exp);
        b = b -> nt;
    }
    return res;
}

PNode find(PNode A, int exp) {
    PNode p = A -> nt;
    while (p != NULL && p -> exp != exp) p = p -> nt;
    return p;
}

PNode mul(PNode A, PNode B) {
    PNode res = (PNode) malloc(sizeof(struct Node));
    res -> nt = NULL;
    PNode a = A -> nt;
    while (a != NULL) {
        PNode b = B -> nt;
        while (b != NULL) {
            PNode p = find(res, a -> exp + b -> exp);
            if (p == NULL) inserttail(res, (a -> coef) * (b -> coef), a -> exp + b -> exp);
            else p -> coef += (a -> coef) * (b -> coef);
            b = b -> nt;
        }
        a = a -> nt;
    }
    PNode p = res;
    while (p -> nt != NULL) {
        PNode q = p -> nt;
        if (q -> coef == 0) {
            p -> nt = q -> nt;
        }
        p = p -> nt;
    }
    return res;
}

void pr (PNode res) {
    if (res == NULL) {
        printf ("0");
        return ;
    }
    PNode p = res -> nt;
    printf("%dx^%d", p -> coef, p -> exp);
    p = p -> nt;
    while (p != NULL) {
        if (p -> coef > 0) printf("+");
        printf ("%dx^%d", p -> coef, p -> exp);
        p = p -> nt;
    }
    puts("");
    return ;
}      

int main () {
    PNode A, B;
    int cntA, cntB;
    scanf ("%d", &cntA);
    A = creatpoly(cntA);
    scanf("%d", &cntB);
    B = creatpoly(cntB);
    pr(A);
    pr(B);
    // pr(add(A, B));
    // pr(del(A, B));
    // pr(mul(A, B));
    return 0;
}