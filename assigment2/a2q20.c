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

//Splitting the list
void split(int x){
    struct node *last1, *head2, *temp;
    last1 = head;
    if (x%2==0){
        for(int i=1;i< x/2;i++)
            last1 = last1->link;
        head2 = last1->link;
        last1 ->link = head;
        last->link = head2;
    }
    else{
        for(int i=1;i< x/2 + 1;i++)
            last1 = last1->link;
        head2 = last1->link;
        last1 ->link = head;
        last->link = head2;
    }
    
    printf("First list is: ");
    temp = head;
    do
    {
        printf("%d ",temp->data);
        temp = temp->link;
    } while (temp!=head);
    printf("\n");
    
    printf("Second list is: ");
    temp = head2;
    do
    {
        printf("%d ",temp->data);
        temp = temp->link;
    } while (temp!=head2);
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
    split(n);
	return 0;
}
