// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 21-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>

int main(){
    int choice,neu;
    char anim;
    do
    {
        printf("\n\n\nAnimal Insurance");
        printf("\n______ _________");
        printf("\n\nCodes:\nDog - D/d\tCat - C/c\nBird - B/b\tReptile - R/r");
        printf("\n\nEnter code:");
        scanf("%c", &anim);
        printf("\nIs the animal neutered?(1=Yes, 0=No): ");
        scanf("%d",&neu);

        if(anim == 'd' || anim == 'D'){
            printf("\n\nCOST: Rs. %d", neu*70 + 280);
        }else if(anim == 'C' || anim == 'c'){
            printf("\n\nCOST: Rs. %d", 260 - neu*20);
        }else if(anim == 'r' || anim == 'R' || anim == 'b' || anim == 'B'){
            printf("\n\nCOST: Rs. 0 (No Cost)");
        }else{
            printf("\n\nERROR: Animal not identified among the codes.");
        }

        printf("\nMore? -1 to stop. Other to continue");
        scanf("%d", &choice);
    } while (choice != -1);
    
    return 0;
}
