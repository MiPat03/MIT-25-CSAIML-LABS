#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int key;
	struct node *left;
    struct node *right;
};

struct node* newNode(int item){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

struct node* insert(struct node* node,int key){
	if(node == NULL)
		return newNode(key);
	if(key < node->key)
		node->left= insert(node->left,key);
	else if(key > node->key)
		node->right = insert(node->right,key);
	return node;
}

int SearchNode(int i,struct node* node){
    if (node == NULL){
        printf("\nValue does not exist in tree!\n");
        return 1;
    }
    else if((node)->key == i){
        printf("\nValue found!\n");
        return 0;
    }
    else if(i > (node)->key)
        SearchNode(i,node->right);
    else
        SearchNode(i,node->left);
}

void inorder(struct node* root){
	if(root != NULL){
		inorder(root->left);
		printf("%d \t",root->key);
		inorder(root->right);
	}
}

void preorder(struct node* root){
	if(root != NULL){
		printf("%d \t",root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct node* root){
	if(root != NULL){
		postorder(root->left);
		postorder(root->right);
	    printf("%d \t",root->key);
	}
}

int main(){
struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    int val;
    printf("Enter element to be searched: ");
    scanf("%d",&val);
    int x = SearchNode(val,root);
    if(x==1)
        insert(root, val);

    printf("Inorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);

return 0;
}
