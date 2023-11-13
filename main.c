#include <stdio.h>
#include <stdlib.h>

// 간단한 트리 노드 정의
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// 트리에 노드 추가
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// 전위 순회 출력
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int values[] = {10, 5, 20, 8, 15, 25};

    // 트리에 노드 추가
    for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
        root = insert(root, values[i]);
    }

    // 전위 순회 출력
    printf("전위 순회 결과: ");
    preorderTraversal(root);

    return 0;
}
