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

void nthnode(struct node* node,int x){
    if(x==1){
        printf("Node with data %d is the required node\n",node->data);
        return;
    }
    nthnode(node->next,x-1);
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
    int nth;
    printf("Position from end: ");
    scanf("%d",&nth);
    nthnode(head,n-nth);
    return 0;
}
