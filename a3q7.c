#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* head1;
struct node* head2;

//Inserting nodes at the end
struct node* insert(struct node* node, int data){
    if(node == NULL){
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->data = data;
        temp->next = NULL;
        return temp;
    }
    node->next = insert(node->next, data);
}

//Displaying the list
void disp(struct node* node){
    if(node == NULL || node->next == NULL){
        printf("\n");
        return;
    }
    printf("%d ",node->data);
    if(node->data == node->next->data)
        disp(node->next->next);
    else
        disp(node->next);
}

struct node* merge( struct node *x, struct node *y){
    struct node *z=NULL;
    if(x==NULL) 
        return y;
    else if (y==NULL) 
        return x;
    if(x->data <= y->data){
        z=x;
        z->next=merge(x->next, y);
    }
    else{
        z=y;
        z->next=merge(x, y->next);
    }
    return z;
}

int main(){
    //First Linked List
	head1 = insert(head1,10);
	head1 =insert(head1,20);
	head1 =insert(head1,30);
	head1 =insert(head1,40);
	head1 =insert(head1,50);
	//Second Linked list
	head2 =insert(head2,10);
	head2 =insert(head2,30);
	head2 =insert(head2,60);
	head2 =insert(head2,70);
	head2 =insert(head2,80);
	disp(head1);
	disp(head2);
    struct node *z = merge(head1,head2);
    disp(z);
	return 0;
}
