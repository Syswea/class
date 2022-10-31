#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int info;
    struct Stack * link;
};
typedef struct Stack* lStack;

lStack init () {
    lStack l = (lStack) malloc (sizeof (struct Stack));
    if (l == NULL) {
        printf ("can not creat\n");
        return NULL;
    }
    l -> link = NULL;
    return l;
}

int pop (lStack l) {
    if (l -> link == NULL) {
        printf ("is empty\n");
        return 0;
    }
    l -> link = l -> link -> link;
    return 1;
}
    
int push (lStack l, int x) {
    lStack k = (lStack) malloc (sizeof (struct Stack));
    if (k == NULL) {
        printf ("can not creat\n");
        return 0;
    }
    k -> info = x;
    k -> link = NULL;
    k -> link = l -> link;
    l -> link = k;
    return 1;
}

int isempty (lStack l) {
    return l -> link == NULL;
}

int top (lStack l) {
    if (isempty(l)) {
        printf ("not data\n");
        return -1;
    }
    return l -> link -> info;
}

int main () {
    lStack sta = init ();
    push(sta, 1);
    push(sta, 2);
    printf ("%d\n", top(sta));
    pop(sta);
    printf ("%d\n", top(sta));
    pop(sta);
    printf ("%d\n", top(sta));
    pop(sta);
    return 0;
}