// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 17-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Decrypt(int *digits){

    for(int i = 0; i < 4; i++){
        digits[i] = (digits[i] + 3) * (digits[i] <= 6) + (digits[i] - 7) * (digits[i] > 6);
    }

    swap(&digits[0], &digits[2]);
    swap(&digits[1], &digits[3]);

}

void Encrypt(int *digits){

    for(int i = 0; i < 4; i++){
        digits[i] = (digits[i] + 7) % 10;
    }

    swap(&digits[0], &digits[2]);
    swap(&digits[1], &digits[3]);

}


int main(){

    int choice = 1;
    do{
        printf("1)Encrypt\n2)Decrypt\n3)Quit\nEnter your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            {
                int x[4];
                printf("Enter a number to Encrypt...\n");
                for(int i = 0; i < 4; i++)
                    scanf("%d", &x[i]);
                
                Encrypt(&x[0]);

                printf("Encrypted Number : ");
                for(int i = 0; i < 4; i++)
                    printf("%d", x[i]);

                printf("\n");
            }
            break;
        
        case 2:
            {
                int x[4];
                printf("Enter a Encrypted number to decrypt...\n");

                for(int i = 0; i < 4; i++)
                    scanf("%d", &x[i]);

                Decrypt(&x[0]);

                printf("Decrypted Number : ");
                for(int i = 0; i < 4; i++)
                    printf("%d", x[i]);

                printf("\n");
            }
            break;
        
        case 3:
            printf("Exit !\n");
            break;

        default:
            printf("Invalid Code\n");
            break;
        }

    }while(choice != 3);

    return 0;
}