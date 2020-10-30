#include<stdio.h>
#include<stdlib.h>

struct node{
   int data;
   struct node* next;
   struct node* prev;
};
struct node* head;

//Inserting at the end
void insert(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    if(head == NULL){
        node->prev = node->next = NULL;
        head = node;
    }
    else{
        struct node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        node->next = NULL;
        node->prev = temp;
        temp->next = node;
    }
}

//Inserting at start
void insertstart(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = head;
    node->prev = NULL;
    head = node;
}

//Inserting before a node
void insertatn(int data,int n){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    if(n==1){
        insertstart(data);
    }
    else{
        struct node *temp = head;
        for(int i=0;i<n-2;i++)
            temp = temp->next;
        node->data = data;
        temp->next->prev = node;
        node->next = temp->next;
        temp->next = node;
        node->prev = temp;
    }
}

//Deleting at start
void deletestart(){
    struct node* temp = head;
    head = temp->next;
    temp->next = NULL;
    free(temp);
}

//Deleting at end
void deleteend(){
    struct node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    temp->prev = NULL;
    free(temp);
}

//Deleting a node in between
void deleteatn(int n){
    if(n==1){
        deletestart();
    }
    else{
        struct node *temp = head;
        for(int i=0;i<n-1;i++)
            temp = temp->next;
        if(temp->next == NULL){
            deleteend();
        }
        else{
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
        }
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
        temp = temp->next;
    }
    printf("\n");
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
    printf("Value to insert at start: ");
    scanf("%d",&data);
    insertstart(data);
    print();
    printf("Value and index to insert before: ");
    scanf("%d %d",&data,&n);
    insertatn(data,n);
    print();
    printf("Value to insert at end: ");
    scanf("%d",&data);
    insert(data);
    print();
    printf("After deletion at start\n");
    deletestart();
    print();
    printf("Enter node to delete: \n");
    scanf("%d",&n);
    deleteatn(n);
    print();
    printf("After deletion of end\n");
    deleteend();
    print();
	return 0;
}
