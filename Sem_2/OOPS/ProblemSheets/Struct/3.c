#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct {
    
    char term[100];
    char meaning[1000];

} S_TERM;

typedef struct {

    int size;
    int currentIndex;
    S_TERM *elements;

} S_DICT;

void addTerm(S_DICT *dict, S_TERM *term){

    strcpy(dict->elements[dict->currentIndex].term, term->term);
    strcpy(dict->elements[dict->currentIndex].meaning, term->meaning);
    dict->currentIndex++;

}

void readTerm(S_TERM *term){
    
    printf("Word : ");
    gets(term->term);
    printf("Meaning : ");
    gets(term->meaning);

}

void search(S_DICT *dict, char * term){

    int i;
    for(i = 0; i < dict->size; i++){
        if(!strcmp(term, dict->elements[i].term)){
            printf(dict->elements[i].meaning);
            break;
        }
    }
    
    if(i == dict->size){
        printf("Key Not Found");
    }


}

void initDict(S_DICT *dict, int size){
    dict->size = size;
    dict->currentIndex = 0;
    dict->elements = (S_TERM *) malloc(sizeof(S_TERM) * size);
}

int main(){

    int n;
    printf("Enter the total number of terms : ");
    scanf("%d", &n);

    S_DICT *dictionary = (S_DICT *) malloc(sizeof(S_DICT));
    initDict(dictionary, n);

    int i;
    S_TERM *term;

    for(i = 0; i < n; i++){
        term = (S_TERM *)malloc(sizeof(S_TERM));
        readTerm(term);
        addTerm(dictionary, term);
        free(term);
    }

    for(i = 0; i < dictionary->size; i++){
        if(dictionary->elements[i].term[0] == 65){
            printf("Term : %s\nMeaning : %s\n", dictionary->elements[i].term, dictionary->elements[i].meaning);
        }
    }

    free(dictionary->elements);
    free(dictionary);

    return 0;
}