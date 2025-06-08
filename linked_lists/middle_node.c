#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* create_node(node *head, int data){
    node *newnode, *temp;
    newnode = (node*) malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    temp = head;
    if (head==NULL)
    {
        head=newnode;
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next = newnode;
    }
    return head;
}

void print_node(node *head){
    node *temp;
    temp = head;
    while(temp!=NULL){
        printf("%d \t", temp->data);
        temp = temp->next;
    }
    return;
}

void middle_node(node *head, int idx){
    if(head==NULL){
        printf("List is empty.");
        return;
    }
    node *temp;
    temp = head;
    while(idx!=0 && temp!=NULL){
        temp = temp->next;
        idx--;
    }
    printf("Middle Node: %d", temp->data);
    return;
}

void free_node(node *head){
    node *temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
    return;
}

int main(){
    node *head;
    head = NULL;
    // head = create_node(head, 5);
    // head = create_node(head, 4);
    // head = create_node(head, 3);
    // head = create_node(head, 2);
    // head = create_node(head, 1);
    int choice, data, count = 0;

    do{
        printf("Enter the data you want to store: ");
        scanf("%d", &data);
        head = create_node(head, data);
        count++;
        printf("Do you want to add more?(0: yes 1: No) ");
        scanf("%d", &choice);
    }while(choice!=1);

    // printf("%d", count);

    // print_node(head);

    middle_node(head, count/2);

    free_node(head);

    printf("\n");
    return 0;
}