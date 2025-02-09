#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ����ջ�ṹ
typedef struct {
    char *data;
    int size;
    int top;
} Stack;

// ��ʼ��ջ
void initStack(Stack *stack, int maxSize) {
    stack->data = (char *)malloc(sizeof(char) * maxSize);
    stack->size = maxSize;
    stack->top = -1;
}

// ��ջ
void push(Stack *stack, char c) {
    if (stack->top < stack->size - 1) {
        stack->data[++stack->top] = c;
    }
}

// ��ջ
char pop(Stack *stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top--];
    }
    return '\0';  // ���ַ���ʾջ�ѿ�
}

// �ж������Ƿ����
bool isBalanced(char *expression) {
    Stack stack;
    initStack(&stack, 100); // ѡ���㹻���ջ����

    for (int i = 0; expression[i] != '\0'; i++) {
        char currentChar = expression[i];
        if (currentChar == '(' || currentChar == '[' || currentChar == '{') {
            push(&stack, currentChar);
        } else if (currentChar == ')' || currentChar == ']' || currentChar == '}') {
            char poppedChar = pop(&stack);
            if ((currentChar == ')' && poppedChar != '(') ||
                (currentChar == ']' && poppedChar != '[') ||
                (currentChar == '}' && poppedChar != '{')) {
                free(stack.data);
                return false; // ���Ų�ƥ��
            }
        }
    }

    // �������Ŷ�Ӧ���Ѿ���ƥ��
    free(stack.data);
    return stack.top == -1;
}

int main() {
    char expression[100]; // ��������ı��ʽ������ 100 ���ַ�
    scanf("%s", expression);
    if (isBalanced(expression)) {
        printf("�������\n");
    } else {
        printf("���Ų����\n");
    }

    return 0;
}
