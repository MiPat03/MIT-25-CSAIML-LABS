#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *left, *right;
    int height;
} NODE;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(NODE *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int balanceFactor(NODE *node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

NODE* create(NODE *bnode, int x) {
    NODE *getnode;
    if (bnode == NULL) {
        bnode = (NODE*) malloc(sizeof(NODE));
        bnode->info = x;
        bnode->left = bnode->right = NULL;
        bnode->height = 1;
    } else if (x > bnode->info)
        bnode->right = create(bnode->right, x);
    else if (x < bnode->info)
        bnode->left = create(bnode->left, x);
    else {
        printf("Duplicate node\n");
        exit(0);
    }
    bnode->height = 1 + max(height(bnode->left), height(bnode->right));
    return(bnode);
}

void inorder(NODE *ptr) {
    if (ptr != NULL) {
        inorder(ptr->left);
        printf("%d(%d) ", ptr->info, balanceFactor(ptr));
        inorder(ptr->right);
    }
}

int main() {
    int n, x, ch, i;
    NODE *root;
    root = NULL;

    while(1) {
        printf("******************** Output ********************\n\n");
        printf("----------- Menu -----------\n");
        printf(" 1. Insert\n 2. Inorder traversal with balance factor\n 3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("Enter node (do not enter duplicate nodes): ");
                scanf("%d", &x);
                root = create(root, x);
                break;
            case 2:
                printf("\nInorder traversal with balance factor:\n");
                inorder(root);
                printf("\n\n*********************************************\n");
                break;
            case 3:
                exit(0);
        }
    }
    return 0;
}
