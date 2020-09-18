#include <stdio.h>
#include <math.h>

int main(){

	int opt;
	
	float p, r, n, t, ci, si, mv;
	
	do{

		printf("1 => SI\n2 => CI\n3 => Quit\nYour choice: ");
		scanf("%d", &opt);

		if(opt == 1){

			printf("Enter Principal Amount, Interest rate (%%), Period...\n");
			scanf("%f %f %f", &p, &r, &t);
			r /= 100;
			si = p * r * t;
			mv = p * ( 1 + (r * t) );

			printf("Simple Interest: %f\nMaturity Value: %f\n", si, mv);

		}else if(opt == 2){


			printf("Enter Principal Amount, Interest rate (%%), Period...\n");
			scanf("%f %f %f", &p, &r, &n);
			r /= 100;
			ci = p * pow(1 + r, n);

			printf("Compound Interest: %lf\n", ci);

		}else if(opt == 3){
			printf("%s\n", "Thank you !");
		}else{
			printf("%s\n", "Invalid choice !");
		}

	}while(opt != 3);

}