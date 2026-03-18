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

void deletePos(int key){
    struct node *temp = head;
    struct node *prev = NULL;

    if(head == NULL) return;

    if(key == 1){
        head = temp->next;
        free(temp);
        return;
    }

    while(key > 1 && temp != NULL){
        prev = temp;
        temp = temp->next;
        key--;
    }

    if(temp == NULL) return;

    prev->next = temp->next;
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

    int key;
    scanf("%d",&key);

    deletePos(key);

    display();

    return 0;
}
