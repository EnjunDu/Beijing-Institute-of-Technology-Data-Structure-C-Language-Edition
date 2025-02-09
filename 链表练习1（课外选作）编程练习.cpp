#include <stdio.h>
#include <stdlib.h>

// ��������ڵ�ṹ
struct Node {
    int data;
    struct Node* next;
};

// �������ڲ���һ���½ڵ㵽����
void insertNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// ��������ɾ������x��С��y��Ԫ��
void deleteRange(struct Node** head, int x, int y) {
    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current != NULL) {
        if (current->data > x && current->data < y) {
            if (prev == NULL) {
                *head = current->next; // ���Ҫɾ���Ľڵ���ͷ�ڵ�
            } else {
                prev->next = current->next;
            }

            // �ͷű�ɾ���ڵ�Ŀռ�
            free(current);
            current = prev; // ���¼�鵱ǰλ��
        }

        prev = current;
        current = current->next;
    }
}

// �������ڴ�ӡ��������
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

    // ��������Ԫ�أ���-1��������
    int value;
    while (1) {
        scanf("%d", &value);
        if (value == -1) {
            break;
        }
        insertNode(&list, value);
    }
    scanf("%d %d", &x, &y);

    // ɾ������x��С��y��Ԫ��
    deleteRange(&list, x, y);
    printList(list);

    // �ͷ�����ڵ��ڴ�
    while (list != NULL) {
        struct Node* temp = list;
        list = list->next;
        free(temp);
    }

    return 0;
}
