#include<stdio.h>
#include<string.h>
int main(){
	char pattern[50],source[100];
	int i,k,flag = 0,pos;
	int count = 0;
	int opcount = 0;
	printf("enter the source : ");
	scanf("%[^\n]",source);
	printf("\n enter the pattern :");
	scanf("%s",pattern);
	int m = strlen(pattern);
	int n = strlen(source);
	printf("%d %d\n",m,n);
	 int shift[500];
    for (i = 0; i < 500; i++)
        shift[i] = m;
    for (i = 0; i < m-1; i++) 
        shift[pattern[i]] = m-1-i;
	i=m-1;
	while(i<n){
		k = 0;
		while(k<m && pattern[m-1-k] == source[i-k]){
			k++;
			count++;
		}
		if(k==m){
			flag = 1;
			pos = i-m+1;
			break;
		}
		else{
			i = shift[source[i]] + i;
			opcount++; 
		}

	}
	if(flag==0){
		printf("the pattern is not found");
		printf("the successful and unsuccessful search are %d and %d",count,opcount);
	}
	else{
		printf("the pattern found at %d\n",pos+1);
		printf("the successful  and unsuccessful search are %d and %d",count,opcount);		
	}
}
