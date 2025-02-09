#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertSorted(struct Node** head, int x) {
    struct Node* newNode = createNode(x);

    if (*head == NULL || x <= (*head)->data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL && current->next->data < x) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(",");
        } else {
            printf("\n");
        }
        current = current->next;
    }
}

int main() {
    struct Node* head = NULL;
    char input[100];
    int x;
    
    printf("");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        // 处理输入错误
        fprintf(stderr, "读取输入时出错。\n");
        return 1;
    }

    char* token = strtok(input, ",");
    while (token != NULL) {
        int number = atoi(token);
        insertSorted(&head, number);
        token = strtok(NULL, ",");
    }

    printf("");
    if (scanf("%d", &x) != 1) {
        // 处理输入错误
        fprintf(stderr, "读取整数输入时出错。\n");
        return 1;
    }
    insertSorted(&head, x);

    display(head);

    // 释放链表内存
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
