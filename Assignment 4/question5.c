#include<stdio.h>
#include<string.h>

int top = -1;
char stack[10];

//Pushing elements onto stack
void push(char item){
    top = top+1;
    stack[top] = item;
}

//Popping elements from stack
char pop(){
    if(top==-1)
        printf("Underflow\n");
    else
        return stack[top--];
}

//If stack is empty or not
int isnotempty(){
    if(top==-1)
        return 0;
    return 1;
}

int main(){
    char str[20];
    int i=0,j;
    printf("Enter string: ");
    scanf("%s", str);
    
    while(str[i] != 'x'){
        push(str[i]);
        i++;
    }

    i=i+1;
    
    while(isnotempty()){
        if(str[i] == pop())
            j = 1;
        else{
            j = 0;
            break;
        }
        i++;
    }
    
    if(j==1)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");
    return 0;
}
