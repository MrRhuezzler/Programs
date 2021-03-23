#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
};

typedef struct node Node;

typedef struct {
    
    Node *head;
    int size;

} LL;

LL* createLL(){

    LL* ll = (LL *)malloc(sizeof(LL));
    ll->head = NULL;
    ll->size = 0;
    return ll;

}

void append_node(LL* ll, int elem){

    Node *new = (Node*)malloc(sizeof(Node));
    new->data = elem;
    new->next = NULL;

    if(ll->head == NULL){

        ll->head = new;

    }else{

        Node *maybeTail = ll->head;
        
        while(maybeTail->next){
            maybeTail = maybeTail->next;
        }
        
        maybeTail->next = new;
    }

    ll->size++;
}

void printLL(LL *ll){
    
    Node *head = ll->head;
    while (head)
    {
        printf("%d, ", head->data);
        head = head->next;
    }
    printf("\n");

}

void concatenate(LL *a, LL *b){

    Node *temp = a->head;

    while(temp->next){
        temp = temp->next;
    }

    temp->next = b->head;
    b->head = NULL;

}


int main(){


    LL *a = createLL();
    LL *b = createLL();
    
    for(int i = 0; i < 5; i++){
        append_node(a, i);
        append_node(b, i);
    }


    concatenate(a, b);
    printLL(a);

    return 0;
}