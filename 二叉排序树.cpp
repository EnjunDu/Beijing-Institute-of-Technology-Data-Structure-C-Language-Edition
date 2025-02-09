#include <stdio.h>
#include <stdlib.h>

//�������ڵ�
struct TreeNode{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct TreeNode* createNode(int data){
	struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	newNode->data=data;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
};

struct TreeNode* buildNode(int preoder[],int start,int end){
	if(start>end){
		return NULL;
	}
	
	int mid=(start+end)/2;
	struct TreeNode*root =createNode(preoder[mid]);
	
	root->left=buildNode(preoder,start,mid-1);
	root->right=buildNode(preoder,mid+1,end);
	
	return root;
};

//�������
void inorderTraversal(struct TreeNode* root){
	if(root!=NULL){
		inorderTraversal(root->left);
		printf("%d  ",root->data);
		inorderTraversal(root->right);
	}
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

// ɾ���ڵ�
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // ��ǰ�ڵ����Ҫɾ���Ľڵ�
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // ����������ӽڵ㣬�ҵ�����������С�ڵ�
        struct TreeNode* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }

        // ����������С�ڵ��ֵ�滻��ǰ�ڵ��ֵ
        root->data = temp->data;

        // ɾ����������С�ڵ�
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int main(){
	int n,deletnumber,num[100]={0};
	scanf("%d",&n);
	printf("ԭʼ���ݣ�");
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
		printf("%d ",num[i]);
	}
	printf("\n");
	InsertionSort(num,n);
	scanf("%d",&deletnumber);
	int index=0;
	struct TreeNode* root = buildNode(num,0,n-1);

	//�������
	printf("������������");
	inorderTraversal(root);
	printf("\n");
	for(int i=0;i<n;i++){
		if(num[i]==deletnumber){
			break;
		}
		if(i==n-1&&num[i]!=deletnumber){
			printf("ɾ����������û��%d��㡣\n",deletnumber);
			exit(0);
		}
		}
	
	root = deleteNode(root,deletnumber);
	printf("ɾ����������");
	inorderTraversal(root);
	printf("\n");
	
	return 0;
}
