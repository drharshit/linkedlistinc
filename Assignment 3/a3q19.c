#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* head = NULL;
struct node* last = NULL;

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
void disp(struct node* node,struct node* end){
    if(node == end){
        printf("%d ",node->data);
        printf("\n");
        return;
    }
    printf("%d ",node->data);
    disp(node->next,end);
}

//Linking the last node
void link(struct node* node, int x){
    if(x<1 || head==NULL)
        return;
    if(x==1){
        last->next = node;
        printf("Last Node linked to %d\n",last->next->data);
    }
    link(node->next, x-1);
}

//Finding the node linked
struct node* findnode(struct node* node,int x){
    if(node == last->next){
        printf("Last node linked to node %d with data %d\n",x+1,node->data);    
        return node;
    }
    findnode(node->next, x+1);
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
    disp(head,last);
    printf("Enter the node to link last node with: ");
    scanf("%d",&n);
    link(head,n);
    struct node* z = findnode(head,0);
    disp(z,last);
    return 0;
}
