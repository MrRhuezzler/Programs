// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 18-Sep-20 (DD-MM-YY) 
// Language Used : C

#include <stdio.h>
#include <math.h>

int main(){

	int option;
		
	do{

		printf("1 => SI\n2 => CI\n3 => Quit\nYour choice: ");
		scanf("%d", &option);

		if(option == 1){

			float interestRate, amount, timePeriod, simpleInterest, maturityValue;

			printf("Enter Principal Amount, Interest rate (%%), Period...\n");
			scanf("%f %f %f", &amount, &interestRate, &timePeriod);
			interestRate /= 100;
			simpleInterest = amount * interestRate * timePeriod;
			maturityValue = amount * ( 1 + (interestRate * timePeriod) );

			printf("Simple Interest: %f\nMaturity Value: %f\n", simpleInterest, maturityValue);

		}else if(option == 2){

			float amount, interestRate, timePeriod, compoundInterest;

			printf("Enter Principal Amount, Interest rate (%%), Period...\n");
			scanf("%f %f %f", &amount, &interestRate, &timePeriod);
			interestRate /= 100;
			compoundInterest = amount * pow(1 + interestRate, timePeriod);

			printf("Compound Interest: %lf\n", compoundInterest);

		}else if(option == 3){
			printf("%s\n", "Thank you !");
		}else{
			printf("%s\n", "Invalid choice !");
		}

	}while(option != 3);

}