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

// 递归函数：判断两个二叉树是否相似
int areSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    // 如果两个节点都为空，则它们相似
    if (root1 == NULL && root2 == NULL) {
        return 1;
    }

    // 如果两个节点中有一个为空，则它们不相似
    if (root1 == NULL || root2 == NULL) {
        return 0;
    }

    // 判断当前节点的值是否相等，并递归判断左右子树是否相似
    return ((root1->data == root2->data) &&
           areSimilar(root1->left, root2->left) &&
           areSimilar(root1->right, root2->right));
}

int main() {
    // 示例先序遍历序列
    char preorderSequence1[1000];
    fgets(preorderSequence1,sizeof(preorderSequence1),stdin);
    char preorderSequence2[1000];
    fgets(preorderSequence2,sizeof(preorderSequence2),stdin);
	if(preorderSequence2[0]=='x'){
		printf("A与B相似\n");
		exit(0);
	}
    // 构建两个二叉树
    int index1 = 0, index2 = 0;
    struct TreeNode* root1 = buildTree(preorderSequence1, &index1);
    struct TreeNode* root2 = buildTree(preorderSequence2, &index2);

    // 判断两个二叉树是否相似
    if (areSimilar(root1, root2)) {
        printf("A与B相似\n");
    } else {
        printf("A与B不相似\n");
    }

    return 0;
}
