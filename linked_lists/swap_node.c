#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node* create_node(node* head, int data){
    node *newnode, *temp;
    newnode = (node*) malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    if(head==NULL){
        head = newnode;
    }
    else{
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return head;
}

void print_list(node *head){
    node *temp;
    temp = head;
    while( temp != NULL){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    return;
}

void free_list(node *head){
    node *temp;
    while(head!=NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
    return;
}

node* swap_node(node *head) {
    if (head == NULL || head->next == NULL)
        return head;

    node *prev = NULL;
    node *curr = head;
    head = curr->next;  

    while (curr != NULL && curr->next != NULL) {
        node *next_pair = curr->next->next;
        node *second = curr->next;

        second->next = curr;
        curr->next = next_pair;

        if (prev != NULL) {
            prev->next = second;
        }

        prev = curr;
        curr = next_pair;
    }

    return head;
}


int main(){
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

    print_list(head);

    head = swap_node(head);

    printf("\nAfter swapping: \n");

    print_list(head);

    free_list(head);

    return 0;
}