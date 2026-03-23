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

void removeDuplicates(){
    struct node *temp = head, *curr;

    while(temp != NULL && temp->next != NULL){
        curr = temp;

        while(curr->next != NULL){
            if(curr->next->data == temp->data){
                struct node *dup = curr->next;
                curr->next = curr->next->next;
                free(dup);
            } else {
                curr = curr->next;
            }
        }

        temp = temp->next;
    }
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

    removeDuplicates();

    display();

    return 0;
}
