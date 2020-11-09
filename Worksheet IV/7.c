// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 21-Oct-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>

char* name(int num){
    switch(num){
        case 0:
            return "";
            break;
        case 1:
            return "one";
            break;
        case 2:
            return "two";
            break;
        case 3:
            return "three";
            break;
        case 4:
            return "four";
            break;
        case 5:
            return "five";
            break;
        case 6:
            return "six";
            break;
        case 7:
            return "seven";
            break;
        case 8:
            return "eight";
            break;
        case 9:
            return "nine";
            break;
        case 10:
            return "ten";
            break;
        case 11:
            return "eleven";
            break;
        case 12:
            return "twelve";
            break;
        case 13:
            return "thirteen";
            break;
        case 14:
            return "fourteen";
            break;
        case 15:
            return "fifteen";
            break;
        case 16:
            return "sixteen";
            break;
        case 17:
            return "seventeen";
            break;
        case 18:
            return "eighteen";
            break;
        case 19:
            return "nineteen";
            break;
    }
}

char* tenth(int num){
    switch(num){
        case 2:
            return "twenty ";
            break;
        case 3:
            return "thirty ";
            break;
        case 4:
            return "forty ";
            break;
        case 5:
            return "fifty ";
            break;
        case 6:
            return "sixty ";
            break;
        case 7:
            return "seventy ";
            break;
        case 8:
            return "eighty ";
            break;
        case 9:
            return "ninety ";
            break;
    }
}

int main(){
    int num,div;
    char* last = "";
    printf("\n\nEnter an integer: ");
    scanf("%d", &num);

    if(num == 100){ printf("one hundred"); }

    else if(num < 20){
        printf("%s", name(num));
    }else if(num < 100){
        if(num%10 != 0){
            last = name(num%10);
        }
        printf("%s%s",tenth(num/10),last);
    }else{
        while(num>0){
            div = 1;
            while(div <= num){
                div *= 10;
            }
            div /=10;
            printf("%s ",name(num/div));
            num %= div;
        }
    }
    return 0;
}