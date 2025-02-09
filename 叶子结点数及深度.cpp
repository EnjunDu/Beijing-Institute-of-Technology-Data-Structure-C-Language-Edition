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

// 递归函数：先序遍历输出，并统计叶子结点个数和深度
void preorderTraversal(struct TreeNode* root, int depth, int* leafCount, int* maxDepth) {
    if (root != NULL) {
        // 统计叶子结点个数
        if (root->left == NULL && root->right == NULL) {
            (*leafCount)++;
        }

        // 更新深度
        if (depth > *maxDepth) {
            *maxDepth = depth;
        }

        // 递归遍历左右子树
        preorderTraversal(root->left, depth + 1, leafCount, maxDepth);
        preorderTraversal(root->right, depth + 1, leafCount, maxDepth);
    }
}

int main() {
    // 示例先序遍历序列
    char preorderSequence1[1000];
    fgets(preorderSequence1,sizeof(preorderSequence1),stdin);

    // 构建二叉树并进行统计
    int index1 = 0;
    struct TreeNode* root1 = buildTree(preorderSequence1, &index1);

    // 统计叶子结点个数和深度
    int leafCount1 = 0, maxDepth1 = 0;

    // 输出先序遍历并进行统计
    preorderTraversal(root1, 1, &leafCount1, &maxDepth1);
    printf("leafs=%d\n", leafCount1);
    printf("Depth=%d\n", maxDepth1);

    return 0;
}
