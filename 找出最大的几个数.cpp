#include <stdio.h>

int main(){
	while(1){
		int a,n,m,num[100]={0},temp;
		a=scanf("%d %d",&n,&m);
		if(m>n){
			printf("ERROR\n");
			continue;
		}
		if(a!=2){
			break;
		}
		for(int i=0;i<n;i++){
			scanf("%d",&num[i]);
		}
		for(int i=0;i<n-1;i++){
			for(int j=0;j<n-i-1;j++){
				if(num[j]>num[j+1]){
					temp=num[j];
					num[j]=num[j+1];
					num[j+1]=temp;
				}
			}
		}
		for(int i=n-1;i>n-m-1;i--){
			if(i==n-m){
				printf("%d\n",num[i]);
				break;
			}
			printf("%d ",num[i]);
		}
	}
	return 0;
}
