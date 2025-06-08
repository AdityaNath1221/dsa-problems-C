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

void free_node(node *head){
    node *temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
    return;
}

int count_occurences(node *head, int key){
    node *temp;
    int count = 0;
    temp = head;
    while(temp!=NULL){
        if(temp->data==key){
            count++;
        }
        temp = temp->next;
    }
    return count;
}

int main(){
    node *head;
    head = NULL;
    int choice, data, key;

    do{
        printf("Enter the data you want to store: ");
        scanf("%d", &data);
        head = create_node(head, data);
        printf("Do you want to add more?(0: yes 1: No) ");
        scanf("%d", &choice);
    }while(choice!=1);

    printf("Enter data to search for: ");
    scanf("%d", &key);

    int count = count_occurences(head, key);

    printf("No of occurences of %d is: %d", key, count);

    free_node(head);

    printf("\n");
    return 0;
}