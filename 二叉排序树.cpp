#include <stdio.h>
#include <stdlib.h>

//定义树节点
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

//中序遍历
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

// 删除节点
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // 当前节点就是要删除的节点
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // 如果有两个子节点，找到右子树的最小节点
        struct TreeNode* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }

        // 用右子树最小节点的值替换当前节点的值
        root->data = temp->data;

        // 删除右子树最小节点
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int main(){
	int n,deletnumber,num[100]={0};
	scanf("%d",&n);
	printf("原始数据：");
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
		printf("%d ",num[i]);
	}
	printf("\n");
	InsertionSort(num,n);
	scanf("%d",&deletnumber);
	int index=0;
	struct TreeNode* root = buildNode(num,0,n-1);

	//中序遍历
	printf("中序遍历结果：");
	inorderTraversal(root);
	printf("\n");
	for(int i=0;i<n;i++){
		if(num[i]==deletnumber){
			break;
		}
		if(i==n-1&&num[i]!=deletnumber){
			printf("删除结点后结果：没有%d结点。\n",deletnumber);
			exit(0);
		}
		}
	
	root = deleteNode(root,deletnumber);
	printf("删除结点后结果：");
	inorderTraversal(root);
	printf("\n");
	
	return 0;
}
