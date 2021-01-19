#include <stdio.h>
#include <limits.h>

int main()
{
    char c;
    printf("\nLargest value that can be stored in 1 byte is %d\n", CHAR_MAX);
    printf("Smallest value that can be stored in 1 byte is %d\n\n", CHAR_MIN);

    printf("\nData Overflow !\n\n");

    c = 122;

    for (int i = 0; i < 10; i++)
    {
        if (i == 6)
            printf("Data Overflowed and got wrapped to the Min value (CHAR_MIN) !\n");
        printf("The Value of c is %d\n", c);
        c++;
    }

    printf("\nData Underflow !\n\n");

    c = -123;

    for (int i = 0; i < 10; i++)
    {
        if (i == 6)
            printf("Data Underflowed and got wrapped to the Max value (CHAR_MAX) !\n");
        printf("The Value of c is %d\n", c);
        c--;
    }

    printf("\n");
}