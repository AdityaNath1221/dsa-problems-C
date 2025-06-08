#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *create_node(node *head, int data)
{
    node *newnode, *temp;
    newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    temp = head;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    return head;
}

void convert_to_circular(node *head)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    printf("Conversion successful.\n");
    return;
}

void print_list(node *head){
    node *temp;
    temp = head->next;
    printf("%d\t", head->data);
    while(temp!=head){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("%d\t\n", head->data);
    return;
}

// void free_list(node *head)
// {
//     node *temp;
//     while (head != NULL)
//     {
//         temp = head;
//         head = head->next;
//         free(temp);
//     }
//     return;
// }

int main()
{
    node *head;
    head = NULL;
    int data, choice;
    do
    {
        printf("Enter data: ");
        scanf("%d", &data);
        head = create_node(head, data);
        printf("Press 0 to continue entering data and 1 to stop. ");
        scanf("%d", &choice);
    } while (choice != 1);

    convert_to_circular(head);

    print_list(head);

    // free_list(head);

    return 0;
}
