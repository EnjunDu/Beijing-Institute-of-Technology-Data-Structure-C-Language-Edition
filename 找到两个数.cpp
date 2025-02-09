#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int value;
	int index;
}Hash;

int* twoSum(int* nums,int numsSize,int target,int* returnSize){
	Hash* hashTable=(Hash*)malloc(numsSize*sizeof(Hash));
	int* result=(int*)malloc(2*sizeof(int));
	*returnSize=2;
	
	//遍历数组
	for(int i=0;i<=numsSize;i++){
		int complement=target - nums[i];
			
		//检查该数字是否在哈希表中
		for(int j=0;j<i;j++){
			if(hashTable[j].value==complement){
				result[0]=hashTable[j].index;
				result[1]=i;
				free(hashTable);
				return result;
			}
		}
			hashTable[i].value=nums[i];
			hashTable[i].index=i;
	}
	//未找到解
	free(hashTable);
	return NULL;
}

int main(){
	int numsSize,target;
	scanf("%d",&numsSize);
	int* nums=(int*)malloc(numsSize*sizeof(int));
	for(int i=0;i<numsSize;i++){
		scanf("%d",&nums[i]);
	}
	scanf("%d",&target);
	
	int returnSize;
	int* result=twoSum(nums,numsSize,target,&returnSize);
	if(result!=NULL){
		for(int i=0;i<returnSize;i++){
			if(i==returnSize-1){
				printf("%d\n",result[i]);
				exit(0);
			}
			printf("%d ",result[i]);
		}
	}
	return 0;
}
