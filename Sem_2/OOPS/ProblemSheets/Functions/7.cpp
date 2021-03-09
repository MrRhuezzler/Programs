// Write a program that computes and displays the charges for a patient’s hospital stay.
// First, the program should ask if the patient was admitted as an in-patient or an out-
// patient. If the patient was an in-patient the following data should be entered:
// - The number of days spent in the hospital
// - The daily rate
// - Charges for hospital services (lab tests, etc.)
// - Hospital medication charges
// If the patient was an out-patient the following data should be entered.
// - Charges for hospital services (lab tests, etc.)
// - Hospital medication charges
// The program should use two overloaded functions to calculate the total charges. One of the
// functions should accept arguments for the in-patient data, while the other function accepts
// arguments for out-patient data. Both functions should return the total charges.
// Input Validation: Do not accept negative numbers for any information.

#include<iostream>

typedef struct
{
    int days;
    double dailyRate;
    double services;
    double medication;

} IN_PATIENT;


typedef struct
{
    
    double services;
    double medication;

} OUT_PATIENT;

void readData(IN_PATIENT *p){
    do{
        std::cout << "Enter days of stay : ";
        std::cin >> p->days;
    }while (p->days > 0 || !p->days);
    
    do{
        std::cout << "Enter daily rate : ";
        std::cin >> p->dailyRate;
    }while (p->dailyRate > 0 || !p->dailyRate);
    
    do{
        std::cout << "Enter Services Charges : ";
        std::cin >> p->services;
    }while (p->services > 0 || !p->services);

    do{
        std::cout << "Enter Medication charges : ";
        std::cin >> p->medication;
    }while (p->medication > 0 || !p->medication);
}

void readData(OUT_PATIENT *p){
    do{
        std::cout << "Enter Services Charges : ";
        std::cin >> p->services;
    }while (p->services > 0 || !p->services);

    do{
        std::cout << "Enter Medication charges : ";
        std::cin >> p->medication;
    }while (p->medication > 0 || !p->medication);
}

double calculateCharges(IN_PATIENT *p){
    return (p->days * p->dailyRate) + p->services + p->medication;
}

double calculateCharges(OUT_PATIENT *p){
    return p->services + p->medication;
}

int main(){

    // Code to use all the above defined functions

    return 0;
}


