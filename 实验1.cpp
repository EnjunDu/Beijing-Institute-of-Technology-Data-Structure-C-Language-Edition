#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}NODE;

NODE* creat(int m){
	NODE *head=NULL;
	NODE *p=NULL;
	NODE *q=NULL;
	
	head =(NODE*)malloc(sizeof(NODE));
	head->data=1;
	p=head;
	for(int i=2;i<=m;i++){
		q=(NODE*)malloc(sizeof(NODE));
		q->data=i;
		p->next=q;
		p=q;
	}
	p->next=head;
	return head;
}
void josephus_circle(NODE* head, int s, int n) {
	NODE *pre=head;
	NODE *p=NULL;
	
	for(int i=1;i<s;i++){
		pre=pre->next;
	}
	
	while(pre->next!=pre){
		for(int i=1;i<n;i++){
		p=pre;
		pre=pre->next;	
		}
		printf("%d ",pre->data);
		p->next=pre->next;
		free(pre);
		pre=p->next;
	}
	printf("%d\n",pre->data);
	free(pre);
}

int main(){
	
	int m,s,n;
// 读入m
ff:	printf("请输入整数m：\n");
 	if (scanf("%d", &m) == 1){
	 if(m<=0){
	 	printf("m输入错误——你应该输入大于零的自然数\n");
	 	goto ff;
	 }	
	 }
// 读入s
ss: printf("请输入整数s\n");
	if(scanf("%d", &s) == 1){
		if(s<1||s>m){
			printf("s输入错误，请输入在1~m间的整数s\n");
			goto ss;
		}
	}
// 读入n
nn:printf("请输入整数n\n");
	if(scanf("%d", &n) == 1){
		if(n<1||n>m){
			printf("n输入错误，请输入在1~m间的整数n\n");
			goto nn;
		}
	}
    NODE *head =creat(m);
    josephus_circle(head,s,n);
    return 0;
}
