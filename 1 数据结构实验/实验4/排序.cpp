#include <stdio.h>

void print(int arr[10],int n){
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void InsertionSort(int arr[10],int n){
	int j,temp;
	for(int i=1;i<n;i++){
		j=i-1;
		int k=i;
		while(k>=0&&j>=0&&arr[k]<arr[j]){
			temp=arr[k];
			arr[k]=arr[j];
			arr[j]=temp;
			j--;
			k--;
		}
	}
}

void QuickSort(int arr[10],int l,int n){
	 if(l+1>n){
	 	return;
	 }
	 int first=l,last=n-1,key=arr[first];
	 while(first<last){
	 	while(first<last&&arr[last]>=key){
		 	last--;
		 }
	 		//如果值小于 key分界值 交换 
		 arr[first]=arr[last];
		 while(first<last&&arr[first]<key){
		 	first++;
		 }
	 		//如果值大于key分界值 交换 
		 arr[last]=arr[first];
	 }
	 arr[first]=key;
 	//递归左右部分进行快排 
	 QuickSort(arr,l,first);
	 QuickSort(arr,first+1,n);
}

void SelectionSort(int arr[10],int n){
	int temp,k;
	for(int i=0;i<10;i++){
		temp=i;
		for(int j=i;j<10;j++){
			if (arr[temp]>arr[j]){
				temp=j;
			}
		}
		k=arr[i];
		arr[i]=arr[temp];
		arr[temp]=k;
	  }
	}	

int main(){
	int arr1[10],arr2[10],arr3[10];
	for(int i=0;i<10;i++){
		scanf("%d",&arr1[i]);
		arr2[i]=arr1[i];
		arr3[i]=arr1[i];
		}
	//插入排序
	InsertionSort(arr1,10);
	printf("插入排序为：");
	print(arr1,10);
	//快速排序
	printf("快速排序为:");
	QuickSort(arr2,0,10);
	print(arr2,10);
	//选择排序
	printf("选择排序为：");
	SelectionSort(arr3,10);
	print(arr3,10);
	
	return 0;
	
}
