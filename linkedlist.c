#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
   struct node* link;
};
struct node* head;

//Inserting Node
void insert(int data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    if(head == NULL){
        head = temp;
    }
    else{
       struct node* temp2 = head;
        while(temp2->link!= NULL){
        temp2 = temp2->link;
        }
        temp2->link = temp;
    }
}

//Displaying the List
void print(){
    if(head == NULL){
        printf("the list is empty\n");
        return;
    }
    printf("the list is : ");
    struct node* temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->link;
    }
    printf("\n");
}

//Inserting at the Start
void begining(int data){
     struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = head;
    head = temp;
}

//Inserting at an index
void insertatn(int data , int n){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data = data;
   	if(n == 1){
       temp->link = head;
       head = temp;
   	}
   	else{
    	struct node* temp2 = head;
    	for(int i=0;i<n-2;i++){
        	temp2=temp2->link;
    	}
    	temp->link=temp2->link;
    	temp2->link=temp;
   }
}

//Inserting at end
void insertend(int data){
	struct node* node=(struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->link = NULL;
	if(head==NULL){
		head = node;
	}
	else{
		struct node* temp = head;
		while(temp->link!=NULL){
			temp = temp->link;
		}
		temp->link = node;
	}
}
//Delete at index
void deleteatn(int n)
{
    struct node* temp1 = head;
    if(n==1){
        head = temp1->link;
        free(temp1);
        return;
    }
    int i;
    for(i=0;i<n-2;i++)
    {
        temp1 = temp1->link;
       
    }
    struct node* temp2 = temp1->link;
    temp1->link = temp2->link;
    free(temp2);
}

//Deleting at Begining
void delatbegin(){
    struct node* temp1 = head;
        head = temp1->link;
        free(temp1);
        return; 
}

//Deleting at end
void delatend(){
    struct node* temp1 = head;
    struct node* prev;
    while(temp1->link!=NULL){
        prev = temp1;
        temp1 = temp1->link;
    }
    if(temp1 == head){
        head = NULL;
        free(temp1);
        return;
    }
    prev->link = NULL;
    free(temp1);
}

//Reversing the list
void reverse(){
    struct node* curr= head;
    struct node* next= NULL;
    struct node* prev= NULL;
    while (curr!= NULL){
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }
        head = prev;
    }

int main(){
	int n,data;
	printf("Number of Nodes: ");
	scanf("%d",&n);
	printf("Enter Node data\n");
	for(int i=0;i<n;i++){
		scanf("%d",&data);
		insert(data);
	}
	print();
	printf("Deletion at start\n");
	delatbegin();
	print();
	printf("Deletion at end\n");
	delatend();
	print();
	printf("Index to delete: ");
	scanf("%d",&n);
	deleteatn(n);
	print();
	printf("Value to insert at start: ");
	scanf("%d",&data);
	begining(data);
	print();
	printf("Value to insert at end: ");
	scanf("%d",&data);
	insertend(data);
	print();
	printf("Value and Index to insert: ");
	scanf("%d %d",&data,&n);
	insertatn(data,n);
	print();
	printf("Reversed list: ");
	reverse();
	print();
	return 0;
}



