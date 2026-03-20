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

int search(int key){
    struct node *temp = head;
    int pos = 1;

    while(temp != NULL){
        if(temp->data == key)
            return pos;
        temp = temp->next;
        pos++;
    }
    return -1;
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

    int res = search(key);

    if(res == -1)
        printf("Not Found");
    else
        printf("%d", res);

    return 0;
}
