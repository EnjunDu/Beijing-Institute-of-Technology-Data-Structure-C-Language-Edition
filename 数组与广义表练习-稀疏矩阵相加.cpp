#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	int x;
	int y;
	int value;
	struct node * next;
}LA;

typedef struct Node{
	int x;
	int y;
	int value;
	struct Node * next;
}LB;

int main(){
	LA *headA=NULL;
	LB *headB=NULL;
	LA *pa=NULL;
	LA *qa=NULL;
	LB *pb=NULL;
	LB *qb=NULL;
	pa=(node*)malloc(sizeof(LA));
	pa->next=NULL;
	pb=(Node*)malloc(sizeof(LB));
	pb->next=NULL;
	headA=pa;
	headB=pb;
	char inputA[100];
 	scanf("%s",inputA);
	char* tokenA = strtok(inputA, ";");
    while (tokenA != NULL) {
        pa = (LA*)malloc(sizeof(LA));
        sscanf(tokenA, "%d,%d,%d", &pa->x, &pa->y, &pa->value);
        pa->next = headA;
        headA = pa;

        tokenA = strtok(NULL, ";");
    }
 
}
