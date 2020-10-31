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

void nthnode(int nth){
    struct node* temp = head;
    for(int i=1;i<nth;i++)
        temp = temp->link;
    printf("Required node is %d",temp->data);
}
int main(){
	int nth;
	insert(10);
	insert(20);
	insert(30);
	insert(40);
	insert(50);
	printf("Enter nth node from end: ");
	scanf("%d",&nth);
	nthnode(5-nth);
	return 0;
}
