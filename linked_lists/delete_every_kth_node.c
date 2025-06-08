#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node*  insert_node(node* head, int data){
    node *newnode;
    newnode = (node*) malloc(sizeof(node));
    newnode->data = data;
    newnode-> next = head;
    head = newnode;
    return head;
}

node* delete_every_kth_node(node* head, int k){
    if(head==NULL||k<0) return head;

    node *current, *prev, *temp;
    current = head;
    prev = NULL;
    int count = 1;
    while(current!=NULL){
        if(count%k==0){
            temp = current;
            if(prev!=NULL){
                prev->next = current->next;
            }
            else{
                head = current->next;
            }
            current = current->next;
            free(temp);
        }
        else{
            prev = current;
            current = current->next;
        }
        count++;
    }
    return head;
}

void print_node(node *head){
    node *temp;
    temp = head;
    while(temp!=NULL){
        printf("%d\t", temp->data);
        temp=temp->next;
    }
    return;
}

void free_node(node* head){
    node *temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(){
    node *head;
    head = NULL;
    head = insert_node(head, 6);
    head = insert_node(head, 5);
    head = insert_node(head, 4);
    head = insert_node(head, 3);
    head = insert_node(head, 2);
    head = insert_node(head, 1);

    print_node(head);

    head = delete_every_kth_node(head, 2);

    printf("\n");

    print_node(head);
    free_node(head);

    printf("\n");

    return 0;
}