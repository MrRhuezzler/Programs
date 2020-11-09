// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 21-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>
#include <limits.h>

int main(){
    int choice, min = INT_MAX, n, f;

    do
    {   
        printf("\n\nEnter no. of integers to be considered: ");
        scanf("%d", &n);
        printf("\nEnter %d integers: ",n);

        for(int i = 0; i<n; i+=1){
            scanf("%d", &f);
            if(f <= min){ min = f; }
        }

        printf("\nThe smallest integer is %d",min);

        printf("\n\nMore? -1 to stop, other to continue:");
        scanf("%d", &choice);
    } while (choice != -1);
    

    return 0;
}
