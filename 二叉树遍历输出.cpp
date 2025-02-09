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

// �ݹ麯��������������
void preorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// �ݹ麯��������������
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%c ", root->data);
        inorderTraversal(root->right);
    }
}

// �ݹ麯��������������
void postorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%c ", root->data);
    }
}

int main() {
    // ʾ�������������
    char preorderSequence[100];
    fgets(preorderSequence,sizeof(preorderSequence),stdin);

    // ����������
    int index = 0;
    struct TreeNode* root = buildTree(preorderSequence, &index);

    // ����������
    printf("ǰ����������");
    preorderTraversal(root);
    printf("\n");

    // ����������
    printf("������������");
    inorderTraversal(root);
    printf("\n");

    // ����������
    printf("������������");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
