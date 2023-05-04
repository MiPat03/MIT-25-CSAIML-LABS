#include<stdio.h>
#include<stdlib.h>

struct node{
	int vertex;
	struct node* next;
};

struct node* createNode(int);

struct Graph{
	int numVertices;
	struct node** adjLists;
};

struct node* createNode(){
	struct node* newNode = malloc(sizeof(struct node));
	newNode->vertex = v;
	newNode->next = NULL;
	return newNode;
}

struct Graph* createGraph(int vertices){
	struct Graph* graph = malloc(sizeof(struct Graph));
	graph->numVertices = vertices;
	graph->adjLists = malloc(vertices * sizeof(struct node*));
	int i;
	for (i = 0; i < vertices; i++)
		graph->adjLists[i] = NULL;
	return graph;
}

void addEdge(struct Graph* graph, int s, int d){
	struct node* newNode = createNode(d);
	newNode->next = graph->adjLists[s];
	graph->adjLists[s] = newNode;
	newNode = createNode(s);
	newNode->next = graph->adjLists[d];
	graph->adjLists[d] = newNode;
}

void printGraph(struct Graph* graph){
	int v;
	for (v = 0; v < graph->numVertices; v++) {
	    struct node* temp = graph->adjLists[v];
	    printf("\n %d: ", v);
	    while (temp) {
	    	printf(" -> %d ", temp->vertex);
	    	temp = temp->next;
	    }
    printf("\n");
    }
}

int main(){
	int v;
	printf("Enter the number of Vertices: ");
	scanf("%d",&v);

	int e;
	printf("Enter the number of Edges: ");
	scanf("%d",&e);

	int vertices[v];
	//adj_matrix
	int adj_mat[v][v];
	//adj_list
	struct Graph* graph = createGraph(v);
	for(int i=0; i<v; i++){
		for(int j=0; j<v; j++){
			adj_mat[i][j] = 0;
		}
	}

	for(int i=0; i<v; i++){
		printf("Enter vertex %d: ",i);
		scanf("%d",&vertices[i]);
	}

	int isEdge;
	for(int i=0; i<v; i++){
		for(int j=0; j<v; j++){
			printf("Is there an edge between %d and %d ?(0 or 1)",vertices[i],vertices[j]);
		}

	}



}