#include<stdio.h>
#include<stdlib.h>

struct node{
int key;
struct node* next;
};
struct hnode{
struct node* head;
};
struct node* CREATENODE(int k){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->key =k;
	temp->next = NULL;
	return temp;
}
struct node* INSERT(struct node* head, int k){
	struct node* temp = head;
	while(temp->next != NULL)temp = temp->next;
	temp->next = CREATENODE(k);
	return head;

}
void main(){

	int n;
	scanf("%d",&n);
	int i,j;
	struct hnode* list = (struct hnode* )malloc(n*(sizeof(struct hnode)));
	
	int A[n][n];
	for (i = 0;i<n;i++){
		for(j =0;j<n;j++){
			scanf("%d",&A[i][j]);
		}
	}
	for(i=0;i<n;i++){
		list[i].head = CREATENODE(i);
	}
	for(i = 0;i<n;i++){
		
		for(j=0;j<n;j++){
			if(A[i][j] == 1){
				list[i].head = INSERT(list[i].head,j);
			}
		}
	}
	
	
	for(i= 0;i<n;i++){
		struct node* temp = list[i].head;
		while(temp!= NULL){
		printf("%d ",temp->key);
		temp = temp->next;
		}
		printf("\n");
		
	}

}
