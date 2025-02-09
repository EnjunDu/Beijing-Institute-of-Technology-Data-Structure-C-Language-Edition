#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
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


//优先级比较函数
int Priority(char a){
	switch (a) {
		case '^':
			return 3;
		case '*':
			return 2;
		case '/':
			return 2;
		case '+':
			return 1;
		case '-':
			return 1;
        case '[':
        case ']':
            return 0;  // 中括号的优先级
        case '{':
        case '}':
            return -1;  // 大括号的优先级
        default:
            return 0;
	}	   
}

//基础加减乘除运算函数
int temporary_result(char a,int b,int c){
	switch (a) {
	case '+':
		return b+c;
	case '-':
		return b-c;
	case '*':
		return b*c;
	case '/':
		return b/c;
	case '^':
		return pow(b,c);
	default:
		return 0;
	}
}

int main() {
	char expression[100];
	char na[100];
 	fgets(expression, sizeof(expression), stdin);
 	strcpy(na,expression);
 	    if (isBalanced(na)) {
	    	printf("括号匹配，继续进行\n");
 	    }
 	    else {
		         printf("括号不配对,请重新输入\n");
		         exit(0);
 	    }
	// 操作数栈
    int value[100];
    int valueTop = -1;
 
    // 操作符栈
    char operatorStack[100];
    int operatorTop = -1;
    
 	// 遍历表达式
 	for (int i = 0; expression[i] != '\0'; ++i) {
    // 如果是数字，将数字转换并入栈
       if (isdigit(expression[i])) {
	      int operand = 0;
	   	   while (isdigit(expression[i])) 
	   {
	    operand = operand * 10 + (expression[i] - '0');
	    ++i;
	        }
	    --i; // 因为for循环中会自增
	    value[++valueTop] = operand;
	        } 
	else if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
		 // 如果是左括号，直接入栈
     	 operatorStack[++operatorTop] = expression[i];
     } 
    else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
    // 如果是右括号，执行栈内运算直到遇到对应的左括号
  	  char leftBracket;
   	   if (expression[i] == ')') leftBracket = '(';
   	    else if (expression[i] == ']') leftBracket = '[';
   		 else leftBracket = '{';
    
    while (operatorTop >= 0 && operatorStack[operatorTop] != leftBracket) 
	{
     	  int temp2 = value[valueTop--];
     	  int temp1 = value[valueTop--];
    	  char temp_operater = operatorStack[operatorTop--];
    	  value[++valueTop] = temporary_result(temp_operater, temp1, temp2);
    }
    // 弹出左括号
       --operatorTop;
    } else 
	{
    // 如果是运算符，执行栈内运算直到栈顶运算符优先级小于当前运算符
       while (operatorTop >= 0 && Priority(operatorStack[operatorTop]) >= Priority(expression[i])) {
     	  int temp2 = value[valueTop--];
     	  int temp1 = value[valueTop--];
    	  char temp_operater = operatorStack[operatorTop--];
    	  value[++valueTop] = temporary_result(temp_operater, temp1, temp2);
    }
    // 当前运算符入栈
    operatorStack[++operatorTop] = expression[i];
    }
    }

    // 执行剩余的运算
    while (operatorTop >= 0) {
     	  int temp2 = value[valueTop--];
     	  int temp1 = value[valueTop--];
    	  char temp_operater = operatorStack[operatorTop--];
    	  value[++valueTop] = temporary_result(temp_operater, temp1, temp2);
    }

    // 计算表达式的值并输出结果
    int result =value[0];
	int len=strlen(expression);
	expression[len-1]='\0';
	printf("%s",expression);
	printf(" = ");
	printf("%d\n",result);

    return 0;
}
