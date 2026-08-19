#include<stdio.h>
#define MAX 10
int stack[MAX];
int top=-1;

void push()
{
    int val;
    if(top==MAX-1)
    {
        printf("\nThe stack is full!!\n");
    }
    else
    {
        printf("\nEnter the value to be pushed :");
        scanf("%d",&val);
        top++;
        stack[top]=val;
        printf("\n%d pushed successfully !!\n",val);
    }
}

void pop()
{
    if(top==-1)
    {
        printf("\nThe stack is empty!!\n");
    }
    else
    {
        printf("\n%d poped successfully !!\n",stack[top]);
        top--;
    }
}

void peek()
{
    if(top==-1)
    {
        printf("\nThe stack is empty !\n");
    }   
    else
    {
        printf("\nThe top element of stack is : %d\n",stack[top]);
    }
}   

void display()
{
    if(top==-1)
    {
        printf("\nThe stack is empty !\n");
    }
    else
    {
        for(int i=top;i>=0;i--)
        {
            printf("\nElement %d: %d",top-i+1,stack[i]);
        }
    }
}
int main()
{   
    int opt;
    do{
    printf("\nEnter 1 : To push the element ");
    printf("\nEnter 2 : To pop the element ");
    printf("\nEnter 3 : To peek the top element ");
    printf("\nEnter 4 : To display the stack ");
    printf("\nEnter 5 : To exit \n");
    scanf("%d",&opt);
    switch(opt)
    {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
    }
    }while(opt!=5);
    return 0;
}
