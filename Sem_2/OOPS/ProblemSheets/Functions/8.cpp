// 8. Write a C++ program to accept records of n employees and store it in array. Use
// array of structures. The structure of employee should be as follows:
#include <iostream>
#include <cstring>
#define N 10

struct Employee
{
int EmpNo;
char Name[20];
char Gender;
long Salary; 
};

// Implement following search functions:
int search(struct Employee arr[], int EmpNo){
    for(int i = 0; i < N; i++){
        if(arr[i].EmpNo == EmpNo){
            return i;
        }
    }
    return -1;
}
int search(struct Employee arr[], char Name[]){
    for(int i = 0; i < N; i++){
        if(!strcmp(arr[i].Name, Name)){
            return i;
        }
    }
    return -1;
}
int search(struct Employee arr[], char Gender){
    for(int i = 0; i < N; i++){
        if(arr[i].Gender == Gender){
            return i;
        }
    }
    return -1;
}
int search(struct Employee arr[], long Salary){
    for(int i = 0; i < N; i++){
        if(arr[i].Salary == Salary){
            return i;
        }
    }
    return -1;
}

// Also implement a function to return an employee who is drawing highest salary by using
// following function:

inline struct Employee compare(long a, long b){
    
}





