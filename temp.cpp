#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node *L;

int main() {
    L head = NULL;
    L temp = NULL;
    int numbers[100];
    int count = 0;
    int b;
    while (count < 100) {
        if (scanf("%d", &numbers[count]) == 1) {
            count++;
        } else {
            break;
        }
    }
    scanf("%d", &b);
    for (int i = 0; i < count; i++) {
        L newNode = (L)malloc(sizeof(struct node));
        newNode->data = numbers[i];
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
        temp = head;
        L previous = NULL;
		if(numbers[0]==b){
  		printf("该结点没有前驱结点\n");
  		exit(0);
		}
        while (temp != NULL) {
            if (temp->data == b) {
                if (previous != NULL) {
                    // 删除直接前驱结点
                    previous->next = temp->next;
                    free(temp); // 释放被删除结点的内存
                    break;
                }
            }
            previous = temp;
            temp = temp->next;
        }

    // 输出删除前驱结点后的链表
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}
