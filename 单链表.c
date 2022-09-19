#include <stdio.h>
#include <stdlib.h>

typedef int Datatype;
struct Node;
typedef struct Node *PNode;
struct Node {
    Datatype info;
    PNode link;
};
typedef struct Node *LinkList;

/*
带头节点就是 llink -> link 不存储值
不带头节点就是 llink -> link 存储值
*/

LinkList createNullList_link () {
    LinkList llink = (LinkList)malloc (sizeof (struct Node));
    if (llink != NULL) llink -> link = NULL;
    else printf ("Create Wrong\n");
    return llink;
}

int isNullList_link (LinkList llink) {
    return (llink -> link == NULL);
}

PNode locate_link (LinkList llink, Datatype x) {
    PNode p;
    if (llink == NULL) return NULL;
    p = llink -> link;
    while (p != NULL && p -> info != x) p = p -> link;
    return p;
}

PNode locatePre_link (LinkList llink, Datatype x) {
    PNode p;
    if (llink == NULL) return NULL;
    p = llink;
    while (p -> link -> link != NULL && p -> link -> info != x) p = p -> link;
    if (p -> link -> info != x) return NULL;
    else return p;
}

int insertPost_link (PNode p, Datatype x) {
    PNode q = (PNode)malloc (sizeof (PNode));
    if (q == NULL) {
        printf ("Insert Create Wrong\n");
        return 0;
    }
    q -> info = x, q -> link = p -> link, p -> link = q;
    return 1;
}

int deletV_link (LinkList llink, Datatype x) {
    PNode p = locatePre_link(llink, x);
    if (p == NULL) {
        printf ("No Data\n");
        return 0;
    }
    PNode q = p -> link;
    p -> link = q -> link;
    free(q);
    return 1;
}

int deletP_link (LinkList llink, PNode x) {
    PNode p = locatePre_link (llink, x -> info);
    if (p == NULL) {
        printf ("No Data\n");
        return 0;
    }
    p -> link = x -> link;
    free(x);
    return 1;
}

int main () {
    return 0;
}