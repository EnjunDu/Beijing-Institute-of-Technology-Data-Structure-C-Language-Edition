#include <stdio.h>
#include <stdlib.h>

typedef struct node1 {
    int data;
    struct node1* next;
} Q1;

typedef struct node2 {
    int data;
    struct node2* next;
} Q2;

int main() {
    Q1* head1 = NULL;
    Q1* p1 = NULL;
    Q1* q1 = NULL;
    Q2* head2 = NULL;
    Q2* p2 = NULL;
    Q2* q2 = NULL;
    p1 = (Q1*)malloc(sizeof(Q1));
    p2 = (Q2*)malloc(sizeof(Q2));
    p1->data = 0;
    p1->next = NULL;
    p2->data = 0;
    p2->next = NULL;
    head1 = p1;
    head2 = p2;
    int num = 0, n[100];
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        scanf("%d", &n[i]);
    }
    for (int i = 0; i < num; i++) {
        if (n[i] % 2 == 1) {
            p1->next = (Q1*)malloc(sizeof(Q1));
            p1 = p1->next;
            p1->data = n[i];
            p1->next = NULL;
        } else {
            p2->next = (Q2*)malloc(sizeof(Q2));
            p2 = p2->next;
            p2->data = n[i];
            p2->next = NULL;
        }
    }
    for (q1 = head1->next, q2 = head2->next; q1 != NULL && q2 != NULL;) {
        int a, b;
        a = q1->data;
        b = q2->data;
        printf("%d %d\n", a, b);
        q1 = q1->next;
        q2 = q2->next;
    }

    return 0;
}
