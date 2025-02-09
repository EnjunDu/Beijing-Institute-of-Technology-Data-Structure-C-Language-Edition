#include <stdio.h>
#include <string.h>

int main(){
	char a1[100],a2[100];
		 gets(a1);
		 gets(a2);
    
    if(strcmp(a1,a2)==0){
		printf("equal\n");
	}
	else{
		printf("not equal\n");
	}
	return 0;
}
