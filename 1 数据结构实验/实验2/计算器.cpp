#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
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


//���ȼ��ȽϺ���
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
            return 0;  // �����ŵ����ȼ�
        case '{':
        case '}':
            return -1;  // �����ŵ����ȼ�
        default:
            return 0;
	}	   
}

//�����Ӽ��˳����㺯��
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
	    	printf("����ƥ�䣬��������\n");
 	    }
 	    else {
		         printf("���Ų����,����������\n");
		         exit(0);
 	    }
	// ������ջ
    int value[100];
    int valueTop = -1;
 
    // ������ջ
    char operatorStack[100];
    int operatorTop = -1;
    
 	// �������ʽ
 	for (int i = 0; expression[i] != '\0'; ++i) {
    // ��������֣�������ת������ջ
       if (isdigit(expression[i])) {
	      int operand = 0;
	   	   while (isdigit(expression[i])) 
	   {
	    operand = operand * 10 + (expression[i] - '0');
	    ++i;
	        }
	    --i; // ��Ϊforѭ���л�����
	    value[++valueTop] = operand;
	        } 
	else if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
		 // ����������ţ�ֱ����ջ
     	 operatorStack[++operatorTop] = expression[i];
     } 
    else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
    // ����������ţ�ִ��ջ������ֱ��������Ӧ��������
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
    // ����������
       --operatorTop;
    } else 
	{
    // ������������ִ��ջ������ֱ��ջ����������ȼ�С�ڵ�ǰ�����
       while (operatorTop >= 0 && Priority(operatorStack[operatorTop]) >= Priority(expression[i])) {
     	  int temp2 = value[valueTop--];
     	  int temp1 = value[valueTop--];
    	  char temp_operater = operatorStack[operatorTop--];
    	  value[++valueTop] = temporary_result(temp_operater, temp1, temp2);
    }
    // ��ǰ�������ջ
    operatorStack[++operatorTop] = expression[i];
    }
    }

    // ִ��ʣ�������
    while (operatorTop >= 0) {
     	  int temp2 = value[valueTop--];
     	  int temp1 = value[valueTop--];
    	  char temp_operater = operatorStack[operatorTop--];
    	  value[++valueTop] = temporary_result(temp_operater, temp1, temp2);
    }

    // ������ʽ��ֵ��������
    int result =value[0];
	int len=strlen(expression);
	expression[len-1]='\0';
	printf("%s",expression);
	printf(" = ");
	printf("%d\n",result);

    return 0;
}
