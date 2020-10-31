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
        while(temp2->link!= NULL)
            temp2 = temp2->link;
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

//Deleting at Begining
struct node* delatbegin(){
    struct node* temp = head;
    head = temp->link;
    free(temp);
    return head;
}

//Deleting node with address
struct node* deletenode(struct node* point){
    struct node* temp = head;
    while(temp->link != point)
        temp = temp->link;
    temp->link = point->link;
    point->link = NULL;
    free(point);
    return temp;
}

void oddeven(int n){
    struct node* temp = head;
    struct node* last = head;
    while(last->link!=NULL)
        last = last->link;
        for(int i=0;i<n;i++){
        if(temp->data%2 != 0 && temp == head){
            insert(temp->data);
            temp = delatbegin();
        }
        else if(temp->data%2 != 0){
            insert(temp->data);
            temp = deletenode(temp);
        }
        else
            temp = temp->link;
    }
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
    oddeven(n);
    print();
	return 0;
}
