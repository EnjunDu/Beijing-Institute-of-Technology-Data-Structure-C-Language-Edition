#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
};

int Number(char *tree, int* index) {
    int number = 0;
    // 当遇到数字字符时，将其转换为整数，并累加到number中
    while (tree[*index] >= '0' && tree[*index] <= '9') {
        number = number * 10 + (tree[*index] - '0');
        (*index)++;
    }
    // 当遇到非数字字符时，结束循环，返回number
    return number;
}

struct TreeNode* BuildTree(char* tree, int* index) {
    if (tree[*index] == '\0' || tree[*index] == '#') {
        (*index)++;
        return NULL;
    }

    // 读取数字
    int num = Number(tree, index);

    // 创建节点
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->data = num;

    // 跳过可能的空格
    while (tree[*index] == ' ') {
        (*index)++;
    }

    // 构建左子树
    root->left = BuildTree(tree, index);

    // 跳过可能的空格
    while (tree[*index] == ' ') {
        (*index)++;
    }

    // 构建右子树
    root->right = BuildTree(tree, index);

    // 跳过可能的空格
    while (tree[*index] == ' ') {
        (*index)++;
    }

    return root;
}
//中序遍历
void midbianli(struct TreeNode* root){
	if (root!=NULL){
		midbianli(root->left);
		printf("%d ",root->data);
		midbianli(root->right);
	}
}

//后序遍历
void lastbianli(struct TreeNode* root){
	if(root!=NULL){
		lastbianli(root->left);
		lastbianli(root->right);
		printf("%d ",root->data);
	}
}

//层次遍历
void levelorderbianli(struct TreeNode* root){
	if (root==NULL) return;
	
	struct TreeNode* queue[1000];
	int a=0,b=0;
	queue[b]=root;
	b++;
	
	while(a<b){
		struct TreeNode* temp=queue[a];
		a++;
		printf("%d ",temp->data);
		
		if(temp->left!=NULL){
			queue[b]=temp->left;
			b++;
		}
		if(temp->right!=NULL){
			queue[b]=temp->right;
			b++;
		}
	}
}

int main(){
	char tree[1000];
 	scanf("%[^\n]", tree);
	int index=0;
	//处理前序序列生成二叉树
	struct TreeNode* root=BuildTree(tree,&index);
	
	//中序遍历
	printf("中序遍历为：");
	midbianli(root);
	printf("\n");
	
	//后序遍历
	printf("后序遍历为：");
	lastbianli(root);
	printf("\n");
	
	printf("层次遍历为：");
	levelorderbianli(root);
	printf("\n");
	
	return 0;
	
}
