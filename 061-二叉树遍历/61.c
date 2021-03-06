#include <stdio.h>
#include <stdlib.h> // malloc

typedef struct bitnode{
    char data;
    struct bitnode *lchild, *rchild;
} bitnode, *BiTree;

void createbitree(BiTree *t, int *n){
    char x;
    BiTree q;

    *n = *n + 1;
    printf(" Input  %d  DATA: ", *n);
    x = getchar();
    if (x != '\n') getchar(); // 吃掉 \n
    if (x == '^') return;

    q = (BiTree)malloc(sizeof(bitnode));
    q->data = x;
    q->lchild = NULL;
    q->rchild = NULL;
    *t = q;

    printf("This Address is:%o,Data is:%c, Left Pointer is:%o,Right Pointer is:  %o\n", q, q->data, q->lchild, q->rchild);

    createbitree(&q->lchild, n);
    createbitree(&q->rchild, n);
}

void visit(BiTree e) {
    printf("  Address:  %o,  Data:  %c,  Left Pointer:  %o,  Right Pointer:  %o\n", e, e->data, e->lchild, e->rchild);
}

void preordertraverse(BiTree t) {
    if (t) {
        visit(t);
        preordertraverse(t->lchild);
        preordertraverse(t->rchild);
    }
}

void countleaf(BiTree t, int *c) {
    if (t != NULL) {
        if (t->lchild == NULL && t->rchild == NULL) {
            *c = *c + 1;
        }
        countleaf(t->lchild, c);
        countleaf(t->rchild, c);
    }
}

int treehigh(BiTree t) {
    int lh, rh, h;
    if (t == NULL) {
        h = 0;
    } else {
        lh = treehigh(t->lchild);
        rh = treehigh(t->rchild);
        h = (lh > rh ? lh : rh) + 1;
    }

    return h;
}

int main() {
    BiTree t;
    int count = 0;
    int n = 0;
    // clrscr();
    printf("Please initialize the TREE!\n");
    createbitree(&t, &n);

    printf("\n This is TREE Struct:\n");
    preordertraverse(t);

    countleaf(t, &count);
    printf(" This TREE has %d leaves.", count);

    printf("\n High of The TREE is: %d\n", treehigh(t));
    
    return 0;
}
