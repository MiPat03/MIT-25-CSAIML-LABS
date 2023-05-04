#include<stdio.h>
#include<stdlib.h>
typedef struct node{
int data;
struct node *link;
}NODE;
typedef struct node *nodeptr;
int function(int element,int m){
return element%m;
}
NODE *create_node(int data){
NODE *temp = malloc(sizeof(NODE));
temp -> data =  data;
temp -> link = NULL;
return temp;
}
NODE *insert(int data,NODE *head){
NODE *temp;
temp = malloc(sizeof(NODE));
temp->data = data;
temp->link = NULL;
NODE *ptr;
ptr = head;
while(ptr->link != NULL){
ptr = ptr->link;
}
ptr->link = temp;
return head;
}
void display(NODE *head){
NODE *ptr = head;
while(ptr!=NULL){
printf("%d->",ptr->data);
ptr = ptr->link;
}
}
int main(){
int n,m,s;
int opcount = 0;
int arr[50];
int b[50];
int flag = 0;
printf("no of elements :");
scanf("%d",&n);
printf("enter the value of m :");
scanf("%d",&m);
printf("enter the elements :");
for(int i=0;i<n;i++)
scanf("%d",&arr[i]);
for(int i=0;i<n;i++){
b[i] = function(arr[i],m);
}
NODE **a=(nodeptr *) malloc(m*sizeof(nodeptr));
*a = malloc(sizeof(NODE));
for(int i=0;i<m;i++){
   a[i] = create_node(i);
}
for(int i=0;i<n;i++){
   for(int j=0;j<m;j++){
       if(b[i]==(a[j]->data)){
           a[j] = insert(arr[i],a[j]);
       }
   }
}

for(int i=0;i<m;i++){
   display(a[i]);
   printf("\n");
}
printf("enter the number to be searched :");
scanf("%d",&s);
int k = function(s,m);
   for(int j=0;j<m;j++){
       opcount++;
       if(k==(a[j]->data)){
           while(a[j]->link!=NULL){
               opcount++;
               if(s==a[j]->data){
                   flag = 1;
                   break;    
               }
               a[j]=a[j]->link;  
           }
   if(flag==0){
       printf("the element is not found and the unsuccessful search is : %d",opcount);
       break;
   }
   else{
       printf("the element is found and the successful search is :%d",opcount);
       break;
   }
       }
   }
}