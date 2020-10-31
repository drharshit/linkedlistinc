#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
   struct node* link;
};
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


int main(){
	int n,data;
	printf("Number of Nodes: ");
	scanf("%d",&n);
	printf("Enter Node data\n");
	for(int i=0;i<n;i++){
		scanf("%d",&data);
		insert(data);
	}
    count();
	return 0;
}
