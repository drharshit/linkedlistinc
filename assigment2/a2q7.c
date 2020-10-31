#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};
struct node* head1;
struct node* head2;

//Inserting Node
void insert(struct node** head,int data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    if(*head == NULL){
        *head = temp;
    }
    else{
        struct node* temp2 = *head;
        while(temp2->link!= NULL){
        temp2 = temp2->link;
        }
        temp2->link = temp;
    }
}

void print(struct node **head){
    if(*head == NULL){
        printf("the list is empty\n");
        return;
    }
    printf("the list is : ");
    struct node* temp = *head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        if(temp->data == temp->link->data){
            temp=temp->link;
        }
        temp = temp->link;
    }
    printf("\n");
}

struct node* fun( struct node *x, struct node *y){
    struct node *z=NULL;
    if(x==NULL) 
        return y;
    else if (y==NULL) 
        return x;
    if(x->data <= y->data){
        z=x;
        z->link=fun(x->link, y);
    }
    else{
        z=y;
        z->link=fun(x, y->link);
    }
    return z;
}

int main(){
    //First Linked List
	insert(&head1,10);
	insert(&head1,20);
	insert(&head1,30);
	insert(&head1,40);
	insert(&head1,50);
	//Second Linked list
	insert(&head2,10);
	insert(&head2,30);
	insert(&head2,60);
	insert(&head2,70);
	insert(&head2,80);
    struct node *z = fun(head1,head2);
    print(&z);
	return 0;
}
