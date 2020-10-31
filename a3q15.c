#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* head = NULL;
struct node* last;

//Inserting nodes at the end
void insert(struct node* node, int data){
    if(head == NULL){
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->data = data;
        temp->next = temp;
        head = temp;
        return;
    }
    if(node->next == head){
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->data = data;
        temp->next = head;
        node->next = temp;
        last = temp;
        return;
    }
    insert(node->next, data);
}

//Displaying the list
void disp(struct node* node){
    if(node->next == head){
        printf("%d ",node->data);
        printf("\n");
        return;
    }
    printf("%d ",node->data);
    disp(node->next);
}

void count(struct node* node,int num){
    if(head==NULL)
        return;
    if(node->next == head){
        printf("Number of nodes : %d\n",num+1);
        return;
    }
    count(node->next,num+1);
}

int main(){
    int n,data;
    printf("Number of nodes: ");
    scanf("%d",&n);
    printf("Enter Node data\n");
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        insert(head,data);
    }
    disp(head);
    count(head,0);
    return 0;
}

