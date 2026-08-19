#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
} *header;

void createLL(int n)
{
    struct node *newNode, *temp;
    int data;

    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL)
    {
        printf("Unable to allocate memory !");
        return;
    }
    else
    {
        printf("Enter the data for node 1: ");
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;
        header = newNode;
        temp = newNode;
    }

    for(int i = 2; i <= n; i++)
    {
        newNode = (struct node*)malloc(sizeof(struct node));
        if(newNode == NULL)
        {
            printf("Unable to allocate memory !");
            return;
        }    
        else
        {
            printf("Enter the data for node %d :", i);
            scanf("%d", &data);

            newNode->data = data;
            newNode->next = NULL;

            temp->next = newNode;
            temp = newNode;
        }
    }
}

void deleteNode(int del)
{
    struct node *temp, *prev;
    
    temp = header;
    prev = header;
    
    int flag = 0;
    while(temp != NULL)
    {
        if(temp->data == del)
        {
            flag = 1;
            break;
        }
        else
        {
            temp = temp->next;
        }
    }

    
    if(flag == 1)
    {
        if(temp == header)
        {
            header = header->next;
            free(temp);
        }
        else
        {
            while(prev->next != temp)
            {
                prev = prev->next;
            }
            prev->next = temp->next;
            free(temp);
        }
        printf("Node deleted successfully!\n");
    }
    else
    {
        printf("Sorry we can't find this node !!\n");
    }
}

void search(int value)
{
    struct node *temp;
    int found = 0, i = 1;
    temp = header;
    while(temp != NULL)
    {
        if(temp->data == value)
        {
            found = 1;
            break;
        }
        temp = temp->next;
        i++;
    }

    if(found == 1)
    {
        printf("Yes!! we found this value at node %d\n", i);
    }
    else
    {
        printf("Sorry !! we could not find this value \n");
    }
}

void display(struct node *header)
{
    struct node *temp;
    temp = header;
    int i = 1;
    printf("Here is the linked list :\n");
    
    while(temp != NULL)
    {
        printf("The value at node %d is : %d \n", i, temp->data);
        temp = temp->next;
        i++;
    }
}

int main()
{
    int opt, n, del, value;
    do {
        printf("\nEnter 1 : To create linked list\n");
        printf("Enter 2 : To delete any node \n");
        printf("Enter 3 : To search any value \n");
        printf("Enter 4 : To display linked list \n");
        printf("Enter 5 : To exit !\n");
        scanf("%d", &opt);

        switch(opt) {
            case 1:
                printf("Enter the number of nodes :");
                scanf("%d", &n);
                createLL(n);
                break;
            case 2:
                printf("Enter the data of the node to be deleted: ");
                scanf("%d", &del);
                deleteNode(del);
                break;
            case 3:
                printf("Enter the value to search :");
                scanf("%d", &value);
                search(value);
                break;
            case 4:
                display(header);
                break;
        }
    } while(opt != 5);
    return 0;
}