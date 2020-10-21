// Author        : Rhubanraj P (anonymouspyro369@gmail.com)
// Date created  : 20-Oct-20 (DD-MM-YY) 
// Language Used : C

typedef struct {
    int empNo;
    float empRate;
    float empHours;
    float empPay;
} emp;

int main(){

    int n;
    printf("Enter the number of Employees : ");
    scanf("%d", &n);


    if(n > 0){
        emp employees[n];
        printf("Enter all the employee details in the order.\n");
        printf("Identification Number, Hourly Wage Rate and Number of Hours Worked\n");

        for(int i = 0; i < n; i++){
            printf("%d\n", i + 1);
            printf("%d%f%f", &employees[i].empNo, &employees[i].empRate, &employees[i].empHours);
            printf("\n");
        }

        

    }




    return 0;
}