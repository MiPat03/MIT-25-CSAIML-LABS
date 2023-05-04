#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *create(){
	node *p;
	int x;
	// printf("Enter data: ");
	scanf("%d",&x);
	if(x==-1)
		return NULL;
	p = (node*)malloc(sizeof(node));
	p->data = x;
	printf("Enter left  child of %d. ",x);
	p->left = create();
	printf("Enter right child of %d. ",x);
	p->right = create();
	return p;
}

int count = 0;

int num_nodes(node *p){
	if(!p){
		count++;
		return 0;
	}
	count++;
	int leftCount = num_nodes(p->left);
	int rightCount = num_nodes(p->right);

	return 1 + leftCount + rightCount;
}

int main(){
	int n_nodes;
	node *root;
	printf("Enter root: ");
	root = create();
	n_nodes = num_nodes(root);
	printf("\nNumber of nodes: %d",n_nodes);
	printf("\nOpcount: %d\n",count);
}