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

//Linking the last node
void link(int x){
    struct node* temp = head;
    for(int i=1;i<x;i++)
        temp = temp->link;
    last->link = temp;
    printf("Last Node linked to %d\n",last->link->data);
}

//Finding the node linked
void findnode(){
    int n=1;
    struct node *temp2 = head;
    while(temp2 != last->link){
        temp2 = temp2->link;
        n++;
    }
    printf("Last node linked to node %d with data %d\n",n,temp2->data);
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
    printf("Enter the node to link last node with: ");
    scanf("%d",&n);
    link(n);
    findnode();
	return 0;
}

