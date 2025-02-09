#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义栈结构
typedef struct {
    char *data;
    int size;
    int top;
} Stack;

// 初始化栈
void initStack(Stack *stack, int maxSize) {
    stack->data = (char *)malloc(sizeof(char) * maxSize);
    stack->size = maxSize;
    stack->top = -1;
}

// 入栈
void push(Stack *stack, char c) {
    if (stack->top < stack->size - 1) {
        stack->data[++stack->top] = c;
    }
}

// 出栈
char pop(Stack *stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top--];
    }
    return '\0';  // 空字符表示栈已空
}

// 判断括号是否配对
bool isBalanced(char *expression) {
    Stack stack;
    initStack(&stack, 100); // 选择足够大的栈容量

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
                return false; // 括号不匹配
            }
        }
    }

    // 所有括号都应该已经被匹配
    free(stack.data);
    return stack.top == -1;
}

int main() {
    char expression[100]; // 假设输入的表达式不超过 100 个字符
    scanf("%s", expression);
    if (isBalanced(expression)) {
        printf("括号配对\n");
    } else {
        printf("括号不配对\n");
    }

    return 0;
}
