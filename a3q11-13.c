#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

struct node* head;

//Inserting at end
void insert(struct node* node, int data)
{
    if(node->next == NULL)
    {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->prev = node;
        newNode->next = NULL;
        node->next = newNode;
        return;
    }

    insert(node->next, data);
}

//Inserting at start
void insbeg(struct node* node,int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;
    temp->prev = NULL;
    head = temp;
}

//Inserting before an index
void insatn(struct node* node, int data,int x){
    if(x<1 || head == NULL)
        return;
    if(x==1 && node == head)
        insbeg(node,data);
    if(x==2){
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->data = data;
        temp->next = node->next;
        node->next->prev = temp;
        node->next = temp;
        temp->prev = node;
    }
    insatn(node->next,data,x-1);
}

//Deleting start
void delstart(){
    struct node* temp = head;
    head = temp->next;
    temp->next->prev = NULL;
    free(temp);
}

//Deleting end
void delend(struct node* node){
    if(head==NULL)
        return;
    if(node->next==NULL){
        struct node* temp = node;
        temp->prev->next = NULL;
        temp->prev = NULL;
        free(node);
        return;
    }
    delend(node->next);
}

//Deleting a index
void delatn(struct node* node,int x){
    if(x<1 || head == NULL)
        return;
    if(x==1 && node==head)
        delstart();
    if(x==1){
        struct node* temp = node;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(node);
        return;
    }
    delatn(node->next,x-1);
}

void disp(struct node* node)
{
    if(node == NULL){
        printf("\n");
        return;
    }
    printf("%d ", node->data);
    disp(node->next);
}

int main(){
    int n,data;
    printf("Number of nodes: ");
    scanf("%d",&n);
    printf("Enter data for Head node: ");
    scanf("%d",&data);
    head = (struct node*)malloc(sizeof(struct node));
    head->data = data;
    head->next = NULL;
    head->prev = NULL;
    n = n-1;
    printf("Data for rest of nodes\n");
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        insert(head,data);
    }
    disp(head);
    
    printf("Data to insert at start: ");
    scanf("%d",&data);
    insbeg(head,data);
    disp(head);
    
    printf("Data and index to index before: ");
    scanf("%d %d",&data,&n);
    insatn(head,data,n);
    disp(head);
    
    printf("Data to insert at end: ");
    scanf("%d",&data);
    insert(head,data);
    disp(head);
    
    printf("List after deleting start\n");
    delstart();
    disp(head);
    
    printf("Position to delete: ");
    scanf("%d",&n);
    delatn(head,n);
    disp(head);

    printf("List after deleting end\n");
    delend(head);
    disp(head);

    return 0;
}
