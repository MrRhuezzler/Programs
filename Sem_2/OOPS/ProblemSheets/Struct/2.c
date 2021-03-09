#include<stdio.h>
#include<stdlib.h>

typedef enum { Software, Package, HeaderFile} E_PROGRAMTYP;

typedef struct {

    int linesOfCode;
    int noOfFunctions;
    int noOfLibraries;

} S_PROGRAM;

void readProgram(S_PROGRAM *program){

    printf("Total number of lines of code : ");
    scanf("%d", &program->linesOfCode);
    printf("Total number of functions used : ");
    scanf("%d", &program->noOfFunctions);
    printf("Total number of libraries used : ");
    scanf("%d", &program->noOfLibraries);
    printf("---\n");

}

E_PROGRAMTYP checkType(S_PROGRAM *program){

    if(program->linesOfCode >= 1000000 && program->noOfFunctions >= 100 && program->noOfLibraries >= 10){
        return Software;
    }else if(program->linesOfCode >= 1000 && program->noOfFunctions >= 50 && program->noOfLibraries >= 1){
        return Package;
    }else{
        return HeaderFile;
    }

}

void writeProgram(S_PROGRAM *program){

    printf("Total number of lines of code : %d\n", program->linesOfCode);
    printf("Total number of functions used : %d\n", program->noOfFunctions);
    printf("Total number of libraries used : %d\n", program->noOfLibraries);

}


int main(){

    int n, i;
    printf("Enter the total number of entries : ");
    scanf("%d", &n);

    S_PROGRAM* arrayOfPrograms = (S_PROGRAM*)malloc(sizeof(S_PROGRAM) * n);

    for(i = 0; i < n; i++){
        printf("%d)\n", i + 1);
        readProgram(&arrayOfPrograms[i]);
    }

    printf("Program Types ...\n");

    for(i = 0; i < n; i++){

        E_PROGRAMTYP typ = checkType(&arrayOfPrograms[i]);

        printf("%d)\n", i + 1);
        printf("Type : ");

        if(typ == Software){
            printf("Software\n");
        }else if(typ == Package){
            printf("Package\n");
        }else{
            printf("HeaderFile\n");
        }

        writeProgram(&arrayOfPrograms[i]);
        
    }


    return 0;
}