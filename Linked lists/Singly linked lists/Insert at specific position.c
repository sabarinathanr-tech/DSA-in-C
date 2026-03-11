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

void insertPos(int val, int key){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    struct node *temp = head;

    newnode->data = val;

    if(key == 1){
        newnode->next = head;
        head = newnode;
        return;
    }

    while(key > 2 && temp != NULL){
        temp = temp->next;
        key--;
    }

    if(temp == NULL) return;

    newnode->next = temp->next;
    temp->next = newnode;
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
    scanf("%d", &n);

    while(n--){
        int x;
        scanf("%d", &x);
        insert(x);
    }

    int val, key;
    scanf("%d %d", &val, &key);

    insertPos(val, key);

    display();

    return 0;
}
