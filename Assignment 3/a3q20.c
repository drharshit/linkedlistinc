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
void disp(struct node* node,struct node* end){
    if(node == end){
        printf("%d ",node->data);
        printf("\n");
        return;
    }
    printf("%d ",node->data);
    disp(node->next,end);
}

void split(struct node* node,int x){
    if(x==1){
        struct node* last1 = node;
        struct node* head2 = node->next;
        last1->next = head;
        last->next = head2;
        printf("First list\n");
        disp2(head,last1);
        printf("Second List\n");
        disp2(head2,last);
        return;
    }
    split(node->next,x-1);
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
    
    if(n%2==0)
        split(head,n/2);
    else
        split(head,(n/2)+1);
    return 0;
}
