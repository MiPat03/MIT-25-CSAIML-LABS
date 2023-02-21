#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int key;
    struct node *left;
    struct node *right;
};

struct node* newNode(int item){
    struct node* temp = (struct node*)malloc(sizeof(struct node))
    temp->key;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, int key){
    if(node == NULL)
        return newNode(key);
    if(key < node->key)
        node->left = insert(node->left, key);
    else if(key > node->right, key)
        node->right = insert(node->right, key);
    return node;
}

int SearchNode(int i, struct node* node){
    if(node == NULL){
        printf("\nValue doesnot exist in the tree!\n");
        return 1;
    }

}