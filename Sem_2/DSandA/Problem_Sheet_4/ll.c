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

void delete_node(LL *ll, int index){

    Node *toDelete, *curr, *prev;

    if(index == 0){
        toDelete = ll->head;
        ll->head = toDelete->next;
        free(toDelete);
        ll->size--;
        return ;
    }

    curr = ll->head->next;
    prev = ll->head;

    int ind = 1;

    while(curr && ind != index){

        prev = curr;
        curr = curr->next;

        ind++;
    }

    toDelete = curr;
    prev->next = toDelete->next;
    free(toDelete);
    ll->size--;

}

void remove_node(LL *ll, int value){

    Node *prev, *curr, *toDelete;

    curr = ll->head->next;
    prev = ll->head;

    while(curr && curr->data != value)
    {
        prev = curr;
        curr = curr->next;
    }

    toDelete = curr;
    prev->next = toDelete->next;
    free(toDelete);
    ll->size--;

}

void insert_node(LL *ll, int index, int elem){

    Node *new = (Node*) malloc(sizeof(Node));
    new->data = elem;
    new->next = NULL;

    Node* temp, *tempsNext;
    int ind = 0;

    if(index == ind){
        temp = ll->head;
        ll->head = new;
        new->next = temp;
        ll->size++;
        return;
    }

    temp = ll->head;
    while(temp && ind < index - 1){ 
        ind++;
        temp = temp->next;
    }

    tempsNext = temp->next;
    temp->next = new;
    new->next = tempsNext;
    ll->size++;

}

void insert_aft_value(LL *ll, int value, int new_value){

    Node *t = (Node *) malloc(sizeof(Node));
    t->data = new_value;
    t->next = NULL;

    Node *temp, *tempsNext;

    temp = ll->head;

    while(temp && temp->data != value)
    {
        temp = temp->next;
    }

    tempsNext = temp->next;
    temp->next = t;
    t -> next = tempsNext;

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

int search(LL *ll, int value){

    Node *temp;
    temp = ll->head;

    while (temp)
    {
        if(temp->data == value){
            return 1;
        }

        temp = temp->next;
    }

    return 0;
}

void reverse(LL *ll){

    Node *temp;
    temp = ll->head;

    LL *tll = createLL();

    while (temp)
    {
        insert_node(tll, 0, temp->data);
        temp = temp->next;
    }

    ll->head = tll->head;

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

int main(){

    LL *ll = createLL();

    append_node(ll, 1);
    append_node(ll, 2);
    append_node(ll, 3);
    append_node(ll, 4);
    append_node(ll, 5);

    printLL(ll);

    char choice;

    printf("a. Insert an element in the beginning\nb. Insert an element in the middle for a given k th position.\nc. Insert an element in the middle after a given value of node. For example, in the above linked list, insert 35 after 30.\nd. Insert an element at the end.\ne. Delete the head node\nf. Delete a node in the middle for a given k th position.\ng. Delete a node in the middle with a given value of node. For example, in the above linked list, delete node with value 30.\nh. Delete the last node.\ni. Given a key element, search whether key is present is linked list or not.\nj. Delete the entire linked list.\nk. Reverse the linked list.\nYour Choice : ");
    scanf("%c", &choice);

    switch (choice)
    {
    case 'a':
        {

            int value;
            printf("Insert an element in the beginning.\n");
            printf("Enter a value : ");
            scanf("%d", &value);

            insert_node(ll, 0, value);

        }
        break;
    
    case 'b':
        {
            
            int value, index;
            printf("Insert an element in the middle for a given k th position.\n");
            printf("Enter a value : ");
            scanf("%d", &value);
            printf("Enter an index : ");
            scanf("%d", &index);

            insert_node(ll, index, value);

        }
        break;

    case 'c':
        {

            int value, new_value;
            printf("Insert an element in the middle after a given value of node. For example, in the above linked list, insert 35 after 30.\n");
            printf("Enter a value to insert : ");
            scanf("%d", &value);
            printf("Enter the value : ");
            scanf("%d", &new_value);

            insert_aft_value(ll, value, new_value);

        }
        break;

    case 'd':
        {
            int value;
            printf("Insert an element at the end.\n");
            printf("Enter a value : ");
            scanf("%d", &value);

            append_node(ll, value);

        }
        break;

    case 'e':
        {
            printf("Delete the head node.");
        }
        break;
    
    case 'f':
        {
            int value, index;
            printf("Delete a node in the middle for a given k th position.\n");
            printf("Enter an index : ");
            scanf("%d", &index);

            delete_node(ll, index);

        }
        break;

    case 'g':
        {

            int value;
            printf("Delete a node in the middle with a given value of node. For example, in the above linked list, delete node with value 30.\n");
            printf("Enter a value to remove : ");
            scanf("%d", &value);
            remove_node(ll, value);

        }
        break;
    
    case 'h':
        {
            
            printf("Delete the last node.\n");
            delete_node(ll, ll->size - 1);

        }
        break;
    
    case 'i':
        {

            int value;
            printf("Given a key element, search whether key is present is linked list or not.\n");
            printf("Enter a value : ");
            scanf("%d", &value);

            if(search(ll, value) == 1){
                printf("PRSENT\n");
            }else{
                printf("NOT PRESENT\n");
            }

        }
        break;
    
    case 'j':
        {
            printf("Delete the entire linked list.\n");
            while (ll->size--)
            {
                delete_node(ll, 0);
            }
        }
        break;

    case 'k':
        {
            printf("Reverse the linked list.\n");
            reverse(ll);
        }
        break;

    }

    printLL(ll);

    return 0;
}

