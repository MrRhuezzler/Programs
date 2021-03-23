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

void sortedInsert(LL *a, Node *temp){

    if(a->head == NULL || a->head->data >= temp->data){

        temp->next = a->head;
        a->head = temp;

    }else{

        Node *current = a->head; 

        while(current->next != NULL && current->next->data < temp->data) 
        { 
            current = current->next; 
        }

        temp->next = current->next; 
        current->next = temp;

    }

}

void insertionSort(LL *a){

    Node *temp = a->head;
    LL *sorted = createLL();
    Node *nxt;

    while(temp){

        nxt = temp->next;
        sortedInsert(sorted, temp);
        temp = nxt;

    }

    a->head = sorted->head;

}

void selectionSort(LL *a){

    Node *temp = a->head;
    while (temp)
    {

        Node *min = temp;
        Node *current = temp->next;

        while (current)
        {

            if(current->data < min->data){
                min = current;
            }

            current = current->next;

        }

        int x = temp->data;
        temp->data = min->data;
        min->data = x;

        temp = temp->next;

    }

}

void split(Node* source, Node** frontRef, Node** backRef) 
{ 
    Node* fast;
    Node* slow; 
    slow = source; 
    fast = source->next;

    while (fast != NULL) { 
        fast = fast->next; 
        if (fast != NULL) { 
            slow = slow->next; 
            fast = fast->next; 
        } 
    } 

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

Node* sortedMerge(Node* a, Node* b) 
{ 

    Node* result = NULL; 
  
    if (a == NULL) 
        return (b); 
    else if (b == NULL) 
        return (a); 
  
    if (a->data <= b->data) { 
        result = a; 
        result->next = sortedMerge(a->next, b); 
    } 
    else { 
        result = b; 
        result->next = sortedMerge(a, b->next); 
    } 
    return (result); 

}

void mergeSort(Node **l){

    Node *a;
    Node *b;

    if((*l == NULL) || ((*l)->next == NULL)){
        return;
    }

    split(*l, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *l = sortedMerge(a, b);

}

int main(){

    int arr[8] = {5, 6, 8, 10, 31, 12, 0, 1};

    LL *a = createLL();
    for(int i = 0;i < 8; i++){
        append_node(a, arr[i]);
    }

    printLL(a);
    mergeSort(&a->head);
    printLL(a);

    return 0;
}
