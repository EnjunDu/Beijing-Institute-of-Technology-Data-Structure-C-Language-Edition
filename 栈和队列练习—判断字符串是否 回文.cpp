#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node *next;
} Node;
typedef struct node1 {
    char data;
    struct node1 *next;
} Node1;

int main() {
    Node *head = NULL;
    Node *p = NULL;
    Node *q = NULL;

    p = (Node *)malloc(sizeof(Node));
    p->data = '\0';
    p->next = NULL;
    head = p;

    Node1 *head1 = NULL;
    Node1 *p1 = NULL;
    Node1 *q1 = NULL;

    p1 = (Node1 *)malloc(sizeof(Node1));
    p1->data = '\0';
    p1->next = NULL;
    head1 = p1;

    char a[100] = {'\0'};
    scanf("%s", a);

    int n;
    for (int i = 0; a[i] != '\0'; i++) {
        p->next = (Node *)malloc(sizeof(Node));
        p = p->next;
        p->data = a[i];
        p->next = NULL;
        n=i;
    }
    for (int i=n; a[i] != '\0'; i--) {
        p1->next = (Node1 *)malloc(sizeof(Node1));
        p1 = p1->next;
        p1->data = a[i];
        p1->next = NULL;
    }

    int choose = 1;
    p = head->next; // Skip the dummy node
    p1 = head1->next; // Skip the dummy node

    while (p != NULL && p1 != NULL) {
        if (p1->data != p->data) {
            choose = 0;
            break;
        }
        p = p->next;
        p1 = p1->next;
    }

    if (choose == 1) {
        printf("是回文\n");
    } else {
        printf("不是回文\n");
    }
    return 0;
}
