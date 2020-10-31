#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* head=NULL;

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

//Inserting at the start
void insbegin(int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    if(head == NULL){
        temp->next = NULL;
        return;
    }
    temp->next = head;
    head = temp;
}

//Inserting at any position
struct node* insatn(struct node* node, int data,int x){
    if(x < 1 || head == NULL)
        return head;
    if(x==1){
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->data = data;
        temp->next = node;
        return temp;
    }
    node->next = insatn(node->next,data,x-1);
}

//Delete at start
void delbegin(){
    if(head == NULL)
        return;
    struct node* temp = head;
    head = temp->next;
    free(temp);
}

//Deleting at the end
struct node* delend(struct node* node){
    if(head == NULL)
        return head;
    if(node->next==NULL){
        struct node* temp = node->next;
        free(node);
        return temp;
    }
    node->next = delend(node->next);
}

//Deleting in between
struct node* delatn(struct node* node,int x){
    if( x<1 || head == NULL)
        return head;
    if(x==1){
        struct node* temp=node->next;
        free(node);
        return temp;
    }
    node->next = delatn(node->next,x-1);
}

//Displaying the list
void disp(struct node* node){
    if(node == NULL){
        printf("\n");
        return;
    }
    printf("%d ",node->data);
    disp(node->next);
}

void reverse(struct node* node){
    if(node->next==NULL){
        head = node;
        return;
    }    
    reverse(node->next);
    struct node *rev = node->next;
    rev->next = node;
    node->next = NULL;
}

int main(){
    int n,data;
    printf("Number of nodes: ");
    scanf("%d",&n);
    printf("Enter Node data\n");
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        head = insert(head,data);
    }
    disp(head); 
    printf("Data to insert at start: ");
    scanf("%d",&data);
    insbegin(data);
    disp(head);
    printf("Data and position to insert before: \n");
    scanf("%d %d",&data,&n);
    insatn(head,data,n);
    disp(head);
    printf("List after deleting start\n");
    delbegin();
    disp(head);
    printf("List after deleting end\n");
    delend(head);
    disp(head);
    printf("Position to delete: ");
    scanf("%d",&n);
    head = delatn(head,n);
    disp(head);
    
    printf("Reversed list is\n");
    reverse(head);
    disp(head);
    return 0;
}

