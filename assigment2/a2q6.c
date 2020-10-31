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
        temp = temp->link;
    }
    printf("\n");
}

void common(struct node** head1, struct node** head2){
    struct node *temp1 = *head1;
    struct node *temp2 = *head2;
    while(temp1 != NULL){
        temp2 = *head2;
        while(temp2 != NULL){
            if(temp1->data == temp2->data)
                printf("%d is common\n",temp1->data);
            temp2 = temp2->link;
        }
        temp1 = temp1->link;
    }
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
	common(&head1,&head2);
	return 0;
}
