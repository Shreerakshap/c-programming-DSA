#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define True 1
#define False 0
typedef struct node
{
    int info;
    struct node *next;
} Node;
/*Function prototype*/
Node *create_node();
int isEmpty(Node *);
void display(Node *);
int count_node(Node *);
void insert_beg(Node **);
void insert_end(Node **);
void insert_pos(Node **);
void delete_beg(Node **);
void delete_end(Node **);
void delete_pos(Node **);

void main()
{
    int item, ch, ch1;
    Node *START = NULL;
    do
    {
        printf("\n\nMain Menu");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n1. Insert in the beginning");
            printf("\n2. Insert at the end");
            printf("\n3. Insert at specific position");
            printf("\n4. Back to main menu");
            printf("\nEnter your choice ");
            scanf("%d", &ch1);
            switch (ch1)
            {
            case 1:
                insert_beg(&START);
                break;
            case 2:
                insert_end(&START);
                break;
            case 3:
                insert_pos(&START);
                break;
            case 4:
                break;
            default:
                printf("\nInvalid choice !");
            }
            break;
        case 2:
            printf("\n1. Delete from the beginning");
            printf("\n2. Delete from the end");
            printf("\n3. Delete from a specific position");
            printf("\n4. Back to main menu");
            printf("\nEnter your choice:");
            scanf("%d", &ch1);
            switch (ch1)
            {
            case 1:
                delete_beg(&START);
                break;
            case 2:
                delete_end(&START);
                break;
            case 3:
                delete_pos(&START);
                break;
            case 4:
                break;
            default:
                printf("\nInvalid choice");
            }
            break;
        case 3:
            display(START);
            break;
        case 4:
            exit;
            break;
        default:
            printf("\nInvalid choice!");
        }
        getch();
    } while (1);
}

Node *create_node()
{
    Node *nptr;
    int item;
    nptr = (Node *)malloc(sizeof(Node));
    if (nptr == NULL)
    {
        printf("\nOverflow: Memory not allowed");
        // exit();
        exit;
    }
    printf("Enter the value to be inserted");
    scanf("%d", &item);
    nptr->info = item;
    nptr->next = NULL;
    return nptr;
}

int isEmpty(Node *START)
{
    if (START == NULL)
        return True;
    else
        return False;
}

void display(Node *START)
{
    Node *temp = START;
    if (isEmpty(temp))
    {
        printf("\nList is empty");
        return;
    }
    while (temp != NULL)
    {
        printf("%d", temp->info);
        temp = temp->next;
    }
}

int count_node(Node *START)
{
    Node *temp = START;
    int count = 0;
    while (temp != NULL)
    {
        count = count + 1;
        temp = temp->next;
    }
    return count;
}

void insert_beg(Node **START)
{
    Node *nptr = create_node();
    nptr->next = *START;
    *START = nptr;
    printf("\nNode inserted");
}

void insert_end(Node **START)
{
    Node *temp = *START;
    Node *nptr = create_node();
    if (isEmpty(temp))
    {
        *START = nptr;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nptr;
    }
    printf("\nNode inserted");
}

void insert_pos(Node **START)
{
    int i, pos, count;
    Node *nptr = create_node();
    Node *temp = *START;
    printf("\nEnter the position at which you want to insert node");
    scanf("%d", &pos);
    count = count_node(*START);
    if (pos <= 0 || pos > count + 1)
    {
        printf("\nInvalid position");
        return;
    }
    if (pos == 1)
    {
        nptr->next = *START;
        *START = nptr;
    }
    else
    {
        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        nptr->next = temp->next;
        temp->next = nptr;
    }
    printf("\nNode inserted");
}

void delete_beg(Node **START)
{
    Node *temp = *START;
    if (isEmpty(temp))
    {
        printf("\nUnderflow List is empty");
        return;
    }
    *START = temp->next;
    free(temp);
    printf("\nNode deleted");
}

void delete_end(Node **START)
{
    Node *temp = *START;
    Node *save;
    if (isEmpty(temp))
    {
        printf("\nUnderflow List is empty");
        return;
    }
    if (temp->next == NULL)
    {
        *START = NULL;
    }
    else
    {
        while (temp->next != NULL)
        {
            save = temp;
            temp = temp->next;
        }
        save->next = NULL;
    }
    free(temp);
    printf("\nNode deleted");
}

void delete_pos(Node **START)
{
    Node *temp = *START;
    Node *save;
    int i, pos, count;
    if (isEmpty(temp))
    {
        printf("\nUnderflow List is empty");
        return;
    }
    printf("\nEnter the position you want to delete the node from");
    scanf("%d", &pos);
    count = count_node(temp);
    if (pos <= 0 || pos > count)
    {
        printf("\nInvalid position");
        return;
    }
    if (pos == 1)
    {
        *START = temp->next;
    }
    else
    {
        for (i = 1; i < pos; i++)
        {
            save = temp;
            temp = temp->next;
        }
        save->next = temp->next;
    }
    free(temp);
    printf("\nNode deleted");
}