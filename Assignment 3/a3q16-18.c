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

//Inserting at the start
struct node* insbegin(int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    if(head == NULL){
        temp->next = temp;
        return temp;
    }
    temp->next = head;
    last->next = temp;
    head = temp;
}

//Inserting at any position
struct node* insatn(struct node* node, int data,int x){
    if(x < 1 || head == NULL)
        return head;
    if(x==1 && node==head){
        return insbegin(data);
    }
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
    last->next = head;
    free(temp);
}

//Deleting at the end
void delend(struct node* node){
    if(head == NULL)
        return;
    if(node->next == last){
        struct node* temp = last;
        node->next = head;
        last = node;
        free(temp);
        return;
    }
    delend(node->next);
}

//Deleting in between
void delatn(struct node* node,int x){
    if( x<1 || head == NULL)
        return;
    if (x==1 && node==head){
        delbegin();
        return;
    }
    if (x==1 && node==last){
        delend(head);
        return;
    }
    if(x==2){
        struct node* temp=node->next;
        node->next = temp->next;
        free(temp);
        return;
    }
    delatn(node->next,x-1);
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

void reverse(struct node* node){
    if(node->next==head){
        head = node;
        return;
    }    
    reverse(node->next);
    struct node *rev = node->next;
    rev->next = node;
    node->next = head;
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
    
    printf("Data to insert at start: ");
    scanf("%d",&data);
    head = insbegin(data);
    disp(head);
    
    
    printf("Data and position to insert before: \n");
    scanf("%d %d",&data,&n);
    head = insatn(head,data,n);
    disp(head);
    
    printf("List after deleting start\n");
    delbegin();
    disp(head);
    
    printf("List after deleting end\n");
    delend(head);
    disp(head);
    
    printf("Position to delete: ");
    scanf("%d",&n);
    delatn(head,n);
    disp(head);
    
    printf("Reversed list is\n");
    reverse(head);
    disp(head);
    return 0;
}

