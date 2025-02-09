#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
};

int Number(char *tree, int* index) {
    int number = 0;
    // �����������ַ�ʱ������ת��Ϊ���������ۼӵ�number��
    while (tree[*index] >= '0' && tree[*index] <= '9') {
        number = number * 10 + (tree[*index] - '0');
        (*index)++;
    }
    // �������������ַ�ʱ������ѭ��������number
    return number;
}

struct TreeNode* BuildTree(char* tree, int* index) {
    if (tree[*index] == '\0' || tree[*index] == '#') {
        (*index)++;
        return NULL;
    }

    // ��ȡ����
    int num = Number(tree, index);

    // �����ڵ�
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->data = num;

    // �������ܵĿո�
    while (tree[*index] == ' ') {
        (*index)++;
    }

    // ����������
    root->left = BuildTree(tree, index);

    // �������ܵĿո�
    while (tree[*index] == ' ') {
        (*index)++;
    }

    // ����������
    root->right = BuildTree(tree, index);

    // �������ܵĿո�
    while (tree[*index] == ' ') {
        (*index)++;
    }

    return root;
}
//�������
void midbianli(struct TreeNode* root){
	if (root!=NULL){
		midbianli(root->left);
		printf("%d ",root->data);
		midbianli(root->right);
	}
}

//�������
void lastbianli(struct TreeNode* root){
	if(root!=NULL){
		lastbianli(root->left);
		lastbianli(root->right);
		printf("%d ",root->data);
	}
}

//��α���
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
	//����ǰ���������ɶ�����
	struct TreeNode* root=BuildTree(tree,&index);
	
	//�������
	printf("�������Ϊ��");
	midbianli(root);
	printf("\n");
	
	//�������
	printf("�������Ϊ��");
	lastbianli(root);
	printf("\n");
	
	printf("��α���Ϊ��");
	levelorderbianli(root);
	printf("\n");
	
	return 0;
	
}
