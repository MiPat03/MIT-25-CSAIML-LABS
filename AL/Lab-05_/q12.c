#include<stdio.h>
#include<stdlib.h>

void createAdjMat(int ** mat,int v,int* indegree){
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			scanf("%d",&mat[i][j]);
			if(mat[i][j]){
				(indegree[j+1])++;
			}
		}
	}
}

void dfs_topo(int i,int v,int* visited,int** mat,int* pop_order,int* k){
	visited[i] = 1;
	for(int j=0;j<v;j++){
		if(mat[i-1][j] && !visited[j+1])
			dfs_topo(j+1,v,visited,mat,pop_order,k);
	}
	pop_order[(*k)++] = i;
}

void source_removal(int i,int v,int** mat,int* sourcelist,int* indegree,int* visited,int* k){
	if( indegree[i] == 0 ){
			visited[i] = 1;
			for(int j=0;j<v;j++){
				if(mat[i-1][j] && indegree[j+1] !=0 ){
					indegree[j+1]--;
				}
			}
			sourcelist[(*k)++] = i;
			if(*k == v)
				return;
			else
				for(int j=1;j<v+1;j++){
					if(indegree[j] == 0 && !visited[j]){
						i = j;
						break;
					}
				}
				source_removal(i,v,mat,sourcelist,indegree,visited,k);

	}
	else{
		source_removal(i+1,v,mat,sourcelist,indegree,visited,k);
	}	
} 	

int main(){
	int v,k=0;
	printf("Enter the number of vertices:\n");
	scanf("%d",&v);
	int** mat = (int**)malloc((v+1)*sizeof(int*));
	int* visited = (int*)malloc(v*sizeof(int));
	int* pop_order = (int*)malloc(v*sizeof(int));
	int* sourcelist = (int*)malloc(v*sizeof(int));
	int* indegree = (int*)malloc((v+1)*sizeof(int));
	for(int i=0;i<v;i++){
		visited[i] = 0;
		indegree[i]=0;
		mat[i] = (int*)malloc(v*sizeof(int)); 
	}
	createAdjMat(mat,v,indegree);
	// dfs_topo(1,v,visited,mat,pop_order,&k);
	// printf("POP ORDER:\n");
	// for(int i=k-1;i>=0;i--){
	// 	printf("%d ",pop_order[i]);
	// }
	k=0;
	for(int i=0;i<v;i++){
		visited[i]=0;
	}
	source_removal(1,v,mat,sourcelist,indegree,visited,&k);
	printf("Topological Sort(Source Removal):\n");
	for(int i=0;i<k;i++){
		printf("%d ",sourcelist[i]);
	}
	return 0;
}