#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}LA;

typedef struct wtf{
	int data;
	struct wtf *next;
}LB;

int main(){
	char c;
	int wewewe=0;
	LA *headA=NULL;
	LA *pa=NULL;
	LA *qa=NULL;
	LB *headB=NULL;
	LB *pb=NULL;
	LB *qb=NULL;
	pa=(node*)malloc(sizeof(LA));
	pa->data=0;
	pa->next=NULL;
	pb=(wtf*)malloc(sizeof(LB));
	pb->data=0;
	pb->next=NULL;
	headA=pa;
	headB=pb;
	for(qa=headA;qa!=NULL;){
		int a;
		if(scanf("%d",&a)==1){
			pa=(node*)malloc(sizeof(LA));
			pa->data=a;
			pa->next=NULL;
			qa->next=pa;
			qa=qa->next;
		}
		if((c=getchar())=='\n'){
			break;
		}
	}
	for(qb=headB;qb!=NULL;){
		int a;
		if(scanf("%d",&a)==1){
			pb=(wtf*)malloc(sizeof(LB));
			pb->data=a;
			pb->next=NULL;
			qb->next=pb;
			qb=qb->next;
		}
		if((c=getchar())=='\n'){
			break;
		}
	}
	for(qa=headA;qa->next!=NULL;){
		qa=qa->next;
		int op=qa->data;
		for(qb=headB;qb->next!=NULL;){
			qb=qb->next;
			int cnm=qb->data;
			if(op==cnm){
				printf("%d ",op);
				wewewe=1;
				break;
			}
		}
	}
	if(wewewe==0){
		printf("没有交集\n");
		exit(0);
	}
	printf("\n");
	return 0;
}
