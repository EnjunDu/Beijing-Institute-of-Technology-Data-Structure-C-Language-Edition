#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int judge(char a[100],char b[100],int len,int n){
	char temp[100];
	if(n>=0&&n<=strlen(a)-len){
		int i=n,j=0;
		for(int w=0;w<len;w++){
			temp[j]=a[i];
			j++;
			i++;
		}
		temp[j]='\0';
	}
	if (strcmp(temp,b)==0){
		return 0;
	}
	else{
		return -1;
	}
}
int main(){
	char a1[100],a2[100];
	gets(a1);
	gets(a2);
	int len1=strlen(a1);
	int len2=strlen(a2);
	for(int i=0;i<len1;i++){
		int cnm=judge(a1,a2,len2,i);
		if (cnm==0){
			printf("%d\n",i+1);
			exit(0);
		}
	}
	return 0;
}
