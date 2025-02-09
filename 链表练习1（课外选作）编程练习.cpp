#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
struct Node {
    int data;
    struct Node* next;
};

// 函数用于插入一个新节点到链表
void insertNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// 函数用于删除大于x且小于y的元素
void deleteRange(struct Node** head, int x, int y) {
    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current != NULL) {
        if (current->data > x && current->data < y) {
            if (prev == NULL) {
                *head = current->next; // 如果要删除的节点是头节点
            } else {
                prev->next = current->next;
            }

            // 释放被删除节点的空间
            free(current);
            current = prev; // 重新检查当前位置
        }

        prev = current;
        current = current->next;
    }
}

// 函数用于打印链表内容
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* list = NULL;
    int x, y;

    // 输入链表元素，以-1结束输入
    int value;
    while (1) {
        scanf("%d", &value);
        if (value == -1) {
            break;
        }
        insertNode(&list, value);
    }
    scanf("%d %d", &x, &y);

    // 删除大于x且小于y的元素
    deleteRange(&list, x, y);
    printList(list);

    // 释放链表节点内存
    while (list != NULL) {
        struct Node* temp = list;
        list = list->next;
        free(temp);
    }

    return 0;
}
