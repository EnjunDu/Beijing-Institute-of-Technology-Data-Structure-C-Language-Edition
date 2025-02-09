#include<stdio.h>

void printnum(int num[10]){
	for(int i=0;i<9;i++){
		printf("%d ",num[i]);
	}
	printf("%d\n",num[9]);
}

int main(){
	int num[10]={5,3,8,4,2,1,7,6,9,10};
	printnum(num);
	for(int i=0;i<9;i++){
		for(int j=0;j<9-i;j++){
			if(num[j]>num[j+1]){
				int temp=num[j];
				num[j]=num[j+1];
				num[j+1]=temp;
				printnum(num);
			}
		}
	}
	
	return 0;
}
