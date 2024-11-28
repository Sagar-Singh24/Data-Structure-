#include<stdio.h>
#include<stdlib.h>
    struct Node{
        int data;
        struct Node* left;
        struct Node* right;
    };
    struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else 
    {
        if (data <= root->data) {
            root->left = insertNode(root->left, data);
        } 
        else 
        {
            root->right = insertNode(root->right, data);
        }
    }
    printf("\n%d Inserted in tree",data);
    return root;

    struct Node* searchNode(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return searchNode(root->left, key);
    }
    return searchNode(root->right, key);
    }
}
int main() 
{
    struct Node* root = NULL;
    root = insertNode(root, 20);
    root = insertNode(root, 15);
    root = insertNode(root, 13);
    root = insertNode(root, 7);
    root = insertNode(root, 11);

    int searchKey = 5;
    struct Node* foundNode = searchNode(root, searchKey);
    if (foundNode != NULL) {
        printf("%d found in the tree.\n", searchKey);
    } else {
        printf("%d not found in the tree.\n", searchKey);
    }
    return 0;
}