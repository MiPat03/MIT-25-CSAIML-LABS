#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    int height;
    struct node* left;
    struct node* right;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct node* n) {
    if (n == NULL) {
        return 0;
    }
    return n->height;
}

int get_balance(struct node* n) {
    if (n == NULL) {
        return 0;
    }
    return height(n->left) - height(n->right);
}

struct node* new_node(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct node* right_rotate(struct node* y) {
    struct node* x = y->left;
    struct node* t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct node* left_rotate(struct node* x) {
    struct node* y = x->right;
    struct node* t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

struct node* insert_node(struct node* root, int data) {
    struct node* node = new_node(data);

    if (root == NULL) {
        return node;
    }

    struct node* parent = NULL;
    struct node* current = root;

    while (current != NULL) {
        parent = current;

        if (data < current->data) {
            current = current->left;
        } else if (data > current->data) {
            current = current->right;
        } else {
            free(node);
            return root;
        }
    }

    if (data < parent->data) {
        parent->left = node;
    } else {
        parent->right = node;
    }

    int balance = get_balance(parent);

    if (balance > 1 && data < parent->left->data) {
        return right_rotate(parent);
    }
    if (balance < -1 && data > parent->right->data) {
        return left_rotate(parent);
    }
    if (balance > 1 && data > parent->left->data) {
        parent->left = left_rotate(parent->left);
        return right_rotate(parent);
    }
    if (balance < -1 && data < parent->right->data) {
        parent->right = right_rotate(parent->right);
        return left_rotate(parent);
    }

    return root;
}


void inorder_traversal(struct node* root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

int main() {
    struct node* root = NULL;
    int num_elements, element;

    printf("Enter the number of elements to be inserted: ");
    scanf("%d", &num_elements);

    printf("Enter %d elements to be inserted:\n", num_elements);
    for (int i = 0; i < num_elements; i++) {
        scanf("%d", &element);
        root = insert_node(root, element);
    }

    printf("Inorder traversal of the AVL tree is: ");
    inorder_traversal(root);
    printf("\n");
}