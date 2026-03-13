#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int val){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = head;
    head = newnode;
}

void deleteEnd(){
    struct node *temp = head;
    struct node *prev = NULL;

    if(head == NULL) return;

    if(head->next == NULL){
        free(head);
        head = NULL;
        return;
    }

    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

void display(){
    struct node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main(){
    int n;
    scanf("%d",&n);

    while(n--){
        int x;
        scanf("%d",&x);
        insert(x);
    }

    deleteEnd();

    display();

    return 0;
}
