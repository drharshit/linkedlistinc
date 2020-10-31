#include<stdio.h>
int size, top = -1;

//Pushing elements onto stack
void push(int *stack, int value){
    if(top == size)
        printf("Overflow\n");
    else{
        top = top+1;
        stack[top] = value;
    }
    return;
}

//Popping elements from stack
int pop(int *stack){
    if(top==-1)
        printf("Underflow\n");
    else
        return stack[top--];
}

//Top element
int topelement(int *stack){
    if(top==-1)
        printf("Underflow\n");
    else
        return stack[top];
}

//Size of stack
int stacksize(int *stack){
    int count=0;
    if(top==-1){
        printf("Underflow");
        return count;
    }
    else{
        while(count <= top)
            count++;
        return count;
    }
}

//If stack is full
int isfull(){
    if(top == size)
      printf("Stack is Full\n");
    return 0;
}

//If stack is empty or not
int isempty(){
    if(top==-1)
        printf("Stack is empty\n");
    else
        printf("Stack is not empty\n");  
    return 0;
}

//Printing stack
void disp(int *stack){
    printf("Stack is\n");
    for(int i=top;i>-1;i--)
        printf("%d\n",stack[i]);
}

int main(){
    int val;
    printf("Size of stack: ");
    scanf("%d",&size);
    int stack[size];
    
    printf("Enter stack values\n");
    for(int i=0;i<size;i++){
        scanf("%d",&val);
        push(stack, val);
    }
    
    printf("Value to push: ");
    scanf("%d",&val);
    push(stack, val);
    disp(stack);
    printf("Stack size: %d\n",stacksize(stack));

    printf("Popped element: %d\n",pop(stack));
    printf("Stack size: %d\n",stacksize(stack));
    disp(stack);
    
    printf("Top element: %d\n",topelement(stack));

    printf("Stack size: %d\n",stacksize(stack));

    isfull();
    
    isempty();

    return 0;
}
