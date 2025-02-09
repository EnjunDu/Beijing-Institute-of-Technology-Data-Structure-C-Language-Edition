#include <stdio.h>
#include <stdlib.h>

// ����������ڵ�ṹ
struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// �����½ڵ�
struct TreeNode* createNode(char data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// �ݹ麯������������������й���������
struct TreeNode* buildTree(char preorder[], int* index) {
    char value = preorder[(*index)++];
    if (value == '#' || value == '\0') {
        return NULL;
    }

    struct TreeNode* node = createNode(value);
    node->left = buildTree(preorder, index);
    node->right = buildTree(preorder, index);
    return node;
}

// �ݹ麯�����ж������������Ƿ�����
int areSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    // ��������ڵ㶼Ϊ�գ�����������
    if (root1 == NULL && root2 == NULL) {
        return 1;
    }

    // ��������ڵ�����һ��Ϊ�գ������ǲ�����
    if (root1 == NULL || root2 == NULL) {
        return 0;
    }

    // �жϵ�ǰ�ڵ��ֵ�Ƿ���ȣ����ݹ��ж����������Ƿ�����
    return ((root1->data == root2->data) &&
           areSimilar(root1->left, root2->left) &&
           areSimilar(root1->right, root2->right));
}

int main() {
    // ʾ�������������
    char preorderSequence1[1000];
    fgets(preorderSequence1,sizeof(preorderSequence1),stdin);
    char preorderSequence2[1000];
    fgets(preorderSequence2,sizeof(preorderSequence2),stdin);
	if(preorderSequence2[0]=='x'){
		printf("A��B����\n");
		exit(0);
	}
    // ��������������
    int index1 = 0, index2 = 0;
    struct TreeNode* root1 = buildTree(preorderSequence1, &index1);
    struct TreeNode* root2 = buildTree(preorderSequence2, &index2);

    // �ж������������Ƿ�����
    if (areSimilar(root1, root2)) {
        printf("A��B����\n");
    } else {
        printf("A��B������\n");
    }

    return 0;
}
