#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Structure to represent a node in the binary tree
typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to construct the binary tree recursively
Node* constructBinaryTree(char* traversal, int* index) {
    if (traversal[*index] == 'N') {
        (*index)++;
        return NULL;
    }

    Node* root = createNode(traversal[*index]);
    (*index)++;

    root->left = constructBinaryTree(traversal, index);
    root->right = constructBinaryTree(traversal, index);

    return root;
}

// Function to check if a string is palindrome
bool isPalindrome(char* str) {
    int len = strlen(str);
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        if (str[i] != str[j])
            return false;
    }
    return true;
}

// Function to count the number of palindromic paths in the binary tree
int countPalindromicPaths(Node* root, char* path, int level) {
    if (root == NULL)
        return 0;

    path[level] = root->data;
    path[level + 1] = '\0';

    int count = 0;
    if (root->left == NULL && root->right == NULL) {
        if (isPalindrome(path))
            count = 1;
    }

    count += countPalindromicPaths(root->left, path, level + 1);
    count += countPalindromicPaths(root->right, path, level + 1);

    return count;
}

int main() {
    int H;
    scanf("%d", &H);

    char traversal[1000];
    scanf("%s", traversal);

    int index = 0;
    Node* root = constructBinaryTree(traversal, &index);

    // Initialize the path array
    char path[17];
    path[0] = root->data;
    path[1] = '\0';

    // Count the number of palindromic paths
    int palindromicPaths = countPalindromicPaths(root, path, 0);

    printf("%d\n", palindromicPaths);

    return 0;
}
