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
	 		//���ֵС�� key�ֽ�ֵ ���� 
		 arr[first]=arr[last];
		 while(first<last&&arr[first]<key){
		 	first++;
		 }
	 		//���ֵ����key�ֽ�ֵ ���� 
		 arr[last]=arr[first];
	 }
	 arr[first]=key;
 	//�ݹ����Ҳ��ֽ��п��� 
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
	//��������
	InsertionSort(arr1,10);
	printf("��������Ϊ��");
	print(arr1,10);
	//��������
	printf("��������Ϊ:");
	QuickSort(arr2,0,10);
	print(arr2,10);
	//ѡ������
	printf("ѡ������Ϊ��");
	SelectionSort(arr3,10);
	print(arr3,10);
	
	return 0;
	
}
