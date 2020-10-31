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

//Displaying the list
void disp(struct node* node){
    if(node == NULL){
        printf("\n");
        return;
    }
    printf("%d ",node->data);
    disp(node->next);
}

//Deleting node based on pointer
struct node* deletenode(struct node* temp, struct node* node){
    if(temp==NULL || node == NULL)
        return NULL;
    if(temp==node){
        temp = node->next;
        free(node);
        return temp;
    }
    temp->next = deletenode(temp->next,node);
    return temp;
}

int main(){
    int n,data;
    struct node* temp = head;
    printf("Number of nodes: ");
    scanf("%d",&n);
    printf("Enter Node data\n");
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        head = insert(head,data);
    }
    disp(head);
    head = deletenode(head,head->next);
    disp(head);
    return 0;
}
