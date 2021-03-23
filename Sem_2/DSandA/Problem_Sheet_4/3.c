#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

void split(LL *a, LL *b, LL *c){

    int frstHalf = ceil(a->size / 2.0);
    int i = 0;

    Node *temp = a->head;
    Node *nxt;
    while(temp){

        nxt = temp->next;
        temp->next = NULL;

        if(i < frstHalf){
            if(!b->head){
                b->head = temp;
            }else{
                Node *btemp = b->head;
                while(btemp->next){
                    btemp = btemp->next;
                }
                btemp->next = temp;
            }

        }else{

            if(!c->head){
                c->head = temp;
            }else{
                Node *ctemp = c->head;
                while(ctemp->next){
                    ctemp = ctemp->next;
                }
                ctemp->next = temp;
            }

        }

        temp = nxt;
        i++;
    }
    
    a->head = NULL;

}


int main(){

    LL *a = createLL();
    LL *b = createLL();
    LL *c = createLL();
    
    for(int i = 0; i < 10; i++){
        append_node(a, i);
    }

    printLL(a);
    
    split(a, b, c);
    
    printf("First Half\n");
    printLL(b);
    
    printf("Second Half\n");
    printLL(c);

}

