#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} L;

int main() {
    L *head = NULL;
    L *p = NULL;
    L *q = NULL;

    p = (L *)malloc(sizeof(L));
    p->data = 0;
    p->next = NULL;
    head = p;

for (q = head; q != NULL;) {
    int a;
    if (scanf("%d", &a) == 1) {
        p = (L *)malloc(sizeof(L));
        p->data = a;
        p->next = NULL;
        q->next = p;
        q = q->next;
    } else {
        break;
    }
}
    int op;
    scanf("%d", &op);
	q = head;
 while (q->next != NULL) {
    if (q->next->next == NULL) {
        p = q->next;
        q->next = NULL;
        free(p);
        break;
    }
    q = q->next;
}

    if (head->next->data == op) {
        printf("该结点没有前驱结点\n");
        exit(0);
    } else {
        q = head->next;
        while (q->next != NULL) {
            if (q->next->next->data == op) {
                p = q->next;
                q->next = p->next;
                free(p);
                break;
            }
            q = q->next;
        }
        if (q->next == NULL) {
            printf("该结点没有前驱结点\n");
            exit(0);
        }
    }

    q = head->next;
    while (q->next != NULL) {
        int w = q->data;
        printf("%d ", w);
        q = q->next;
    }
    int sb = q->data;
    printf("%d\n", sb);

    return 0;
}
