#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
   struct node* link;
};
struct node* last;
struct node* head;

//Inserting at the end
void insert(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    if(head == NULL){
        node->link = node;
        head = node;
    }
    else{
        struct node* temp = head;
        while(temp->link!=head)
            temp = temp->link;
        node -> link = temp -> link;
        temp -> link = node;
    }
    last = node;
}

//Inserting at start
void insertstart(int data){
    struct node* temp = head;
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->link = temp;
    while(temp->link!=head)
        temp = temp->link;
    temp->link = node;
    head = node;
}

//Deleting at start
void deletestart(){
    struct node* temp = last->link;
    last->link = temp->link;
    head = last->link;
    free(temp);
}

//Deleting at end
void deleteend(){
    struct node* temp = last->link;
    struct node* temp2 = last;
    while(temp->link!=temp2)
        temp = temp->link;
    temp->link = temp2->link;
    last = temp;
    free(temp2);
}

//Reversing the List
void reverse(){
    struct node* prev = last;
    struct node* curr = last->link;
    struct node* next;
    struct node* head2 = last->link;
    while(curr!=last){
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }
    head = curr;
    curr->link = prev;
    last = head2;
}

void count(){
    struct node* temp = head;
    int count = 0; 
    do
    {
        count ++;
        temp = temp->link;
    } while (temp!=head);
    printf("Number of nodes = %d\n", count);
}

//Displaying the List
void print(){
    if(head == NULL){
        printf("the list is empty\n");
        return;
    }
    printf("the list is : ");
    struct node* temp = head;
    printf("%d ",temp->data);
    temp = temp->link;
    while(temp!=head){
        printf("%d ",temp->data);
        temp = temp->link;
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
    printf("Data to insert at start: ");
    scanf("%d",&data);
    printf("List after inserting at start\n");
    insertstart(data);
    print();
    printf("Data to insert at end: ");
    scanf("%d",&data);
    printf("List after inserting at end\n");
    insert(data);
    print();
    count();
	return 0;
}