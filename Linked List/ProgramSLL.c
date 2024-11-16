#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head;

void createList()
{
    struct node *one;
    struct node *two;
    struct node *three;
    struct node *four;

    one = (struct node *)malloc(sizeof(struct node));
    two = (struct node *)malloc(sizeof(struct node));
    three = (struct node *)malloc(sizeof(struct node));
    four = (struct node *)malloc(sizeof(struct node));

    one->data = 1;
    two->data = 2;
    three->data = 3;
    four->data = 4;

    head = one;
    one->next = two;
    two->next = three;
    three->next = four;
    four->next = NULL;

}
void display()
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d  ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void insertionBegining(int data)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("\n%d is inserted successfully at beginning.",data);
}
void insertingendPosition(int data)
{
    struct node *newNode;
    struct node *temp=head;
    newNode = (struct node *)malloc(sizeof(struct node));
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next = newNode;
    newNode->data = data;
    newNode->next = NULL;
     printf("\n%d is inserted successfully at the end",data);
}

void insertingatPosition(int data,int pos)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    temp = head;
    for(int i = 1;i<=pos-2;i++)
    {
       temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->data = data;
     printf("\n%d is inserted successfully at position %d.",data,pos);
}

void deletingatBegining()
{
    struct node *temp;
    if (head==NULL)
    printf("LIST IS ALREADY EMPTY");
    else
    {
        temp = head;
        head = head->next;
        printf("\nData deleted = %d\n", temp->data);
        free(temp);
        printf("Succesfully Deleted First Node from List\n");
    }
}
void delteLastNode()
{
    struct node *temp,*last;
    temp = head;
    last = head;
    while(temp->next!=NULL)
    {
        last = temp;
        temp = temp->next;
    }
    if (head==temp)
    head = NULL;
    else
    {
        last->next = NULL;
    }
    printf("\nData deleted = %d\n", temp->data);
    free(temp);
    printf("Succesfully Deleted LAST Node from List\n");
}
void deleteatPosition(int position)
{
    struct node *temp,*prev;
    if (head==NULL)
    printf("LIST IS ALREADY EMPTY");
    else
    {
        temp = head;
        prev = head;
        for(int i = 2; i<=position;i++)
        {
            prev = temp;
            temp = temp->next;
            if(temp==NULL)
            break;
        }
        if(temp != NULL)
        {
            if(temp == head)
            head = head->next;

            prev->next = temp->next;
            temp->next = NULL;
            printf("\nData deleted = %d\n", temp->data);
            printf("SUCCESFULLY DELETED NODE FROM OF LIST\n");
        }
        else
        printf("Invalid postion");
        }
}
int main()
{
    createList();
    display();
    insertionBegining(5);
    insertionBegining(9);
    insertingendPosition(10);
    insertingatPosition(8,3);
    insertingatPosition(6,7);
    deletingatBegining();
    delteLastNode();
    deleteatPosition(1);
    deleteatPosition(3);
    display();
return 0;
}
