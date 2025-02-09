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

// �ݹ麯������������������ͳ��Ҷ�ӽ����������
void preorderTraversal(struct TreeNode* root, int depth, int* leafCount, int* maxDepth) {
    if (root != NULL) {
        // ͳ��Ҷ�ӽ�����
        if (root->left == NULL && root->right == NULL) {
            (*leafCount)++;
        }

        // �������
        if (depth > *maxDepth) {
            *maxDepth = depth;
        }

        // �ݹ������������
        preorderTraversal(root->left, depth + 1, leafCount, maxDepth);
        preorderTraversal(root->right, depth + 1, leafCount, maxDepth);
    }
}

int main() {
    // ʾ�������������
    char preorderSequence1[1000];
    fgets(preorderSequence1,sizeof(preorderSequence1),stdin);

    // ����������������ͳ��
    int index1 = 0;
    struct TreeNode* root1 = buildTree(preorderSequence1, &index1);

    // ͳ��Ҷ�ӽ����������
    int leafCount1 = 0, maxDepth1 = 0;

    // ����������������ͳ��
    preorderTraversal(root1, 1, &leafCount1, &maxDepth1);
    printf("leafs=%d\n", leafCount1);
    printf("Depth=%d\n", maxDepth1);

    return 0;
}
