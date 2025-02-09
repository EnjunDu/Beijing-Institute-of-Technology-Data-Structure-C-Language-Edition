#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// 创建新节点
struct TreeNode* createNode(char data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 递归函数：根据先序遍历序列构建二叉树
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

// 递归函数：先序遍历输出
void preorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// 递归函数：中序遍历输出
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%c ", root->data);
        inorderTraversal(root->right);
    }
}

// 递归函数：后序遍历输出
void postorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%c ", root->data);
    }
}

int main() {
    // 示例先序遍历序列
    char preorderSequence[100];
    fgets(preorderSequence,sizeof(preorderSequence),stdin);

    // 构建二叉树
    int index = 0;
    struct TreeNode* root = buildTree(preorderSequence, &index);

    // 输出先序遍历
    printf("前序遍历结果：");
    preorderTraversal(root);
    printf("\n");

    // 输出中序遍历
    printf("中序遍历结果：");
    inorderTraversal(root);
    printf("\n");

    // 输出后序遍历
    printf("后序遍历结果：");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
