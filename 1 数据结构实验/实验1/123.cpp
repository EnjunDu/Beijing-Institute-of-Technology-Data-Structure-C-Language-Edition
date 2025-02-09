#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
    int data;
    struct node* next;
} NODE;

NODE* create(int m) {
    NODE* head = NULL;
    NODE* p = NULL;
    NODE* q = NULL;

    head = (NODE*)malloc(sizeof(NODE));
    head->data = 1;
    p = head;
    for (int i = 2; i <= m; i++) {
        q = (NODE*)malloc(sizeof(NODE));
        q->data = i;
        p->next = q;
        p = q;
    }
    p->next = head;
    return head;
}

void josephus_circle(NODE* head, int s, int n) {
    NODE* pre = head;
    NODE* p = NULL;

    for (int i = 1; i < s; i++) {
        pre = pre->next;
    }

    while (pre->next != pre) {
        for (int i = 1; i < n; i++) {
            p = pre;
            pre = pre->next;
        }
        printf("%d ", pre->data);
        p->next = pre->next;
        free(pre);
        pre = p->next;
    }
    printf("%d\n", pre->data);
    free(pre);
}

int main() {
    int m, s, n;
    
    // 读入m，确保m是整数
    do {
        printf("请输入整数m：\n");
    } while (scanf("%d", &m) != 1 || m <= 0);

    // 读入s，确保s是整数且在1~m间
    do {
        printf("请输入整数s：\n");
    } while (scanf("%d", &s) != 1 || s < 1 || s > m);

    // 读入n，确保n是整数且在1~m间
    do {
        printf("请输入整数n：\n");
    } while (scanf("%d", &n) != 1 || n < 1 || n > m);

    NODE* head = create(m);
    josephus_circle(head, s, n);
    return 0;
}
