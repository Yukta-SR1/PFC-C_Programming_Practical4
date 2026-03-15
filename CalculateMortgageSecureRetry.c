#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

// Function declarations
bool readSalaries(double *salary1, double *salary2);
bool validateSalary(double salary);
double calculateMortgage(double salary1, double salary2);
double largerSalary(double salary1, double salary2);
double smallerSalary(double salary1, double salary2);

int main() {
    double salary1, salary2, mortgage;
    const int MAX_ATTEMPTS = 3;
    int attempts = 0;
    bool inputValid = false;
    
    // Give user multiple attempts with security limit
    while (attempts < MAX_ATTEMPTS && !inputValid) {
        printf("Enter two salaries separated by a space:\n");
        
        if (!readSalaries(&salary1, &salary2)) {
            attempts++;
            printf("Error: Invalid input format.\n");
            printf("Attempts remaining: %d\n", MAX_ATTEMPTS - attempts);
            continue;
        }
        
        if (!validateSalary(salary1) || !validateSalary(salary2)) {
            attempts++;
            printf("Error: Salaries must be between £0 and £1,000,000.\n");
            printf("Attempts remaining: %d\n", MAX_ATTEMPTS - attempts);
            continue;
        }
        
        inputValid = true;
    }
    
    // Check if max attempts exceeded
    if (attempts >= MAX_ATTEMPTS) {
        printf("Maximum attempts exceeded. Program terminated.\n");
        return 1;
    }
    
    // Calculate mortgage
    mortgage = calculateMortgage(salary1, salary2);
    
    if (mortgage < 0) {
        printf("Error: Calculation failed due to overflow.\n");
        return 1;
    }
    
    printf("The maximum size of mortgage is: £ %.2lf\n", mortgage);
    
    return 0;
}

// readSalaries 
bool readSalaries(double *salary1, double *salary2) {
    if (salary1 == NULL || salary2 == NULL) return false;
    if (scanf("%lf %lf", salary1, salary2) != 2) {
        while (getchar() != '\n');
        return false;
    }
    return true;
}

// validateSalary 
bool validateSalary(double salary) {
    const double MIN_SALARY = 0.0;
    const double MAX_SALARY = 1000000.0;
    return (salary >= MIN_SALARY && salary <= MAX_SALARY);
}

// calculateMortgage 
double calculateMortgage(double salary1, double salary2) {
    double larger  = largerSalary(salary1, salary2);
    double smaller = smallerSalary(salary1, salary2);
    double mortgage;
    if (larger > (LLONG_MAX / 3))         return -1;
    mortgage = larger * 3;
    if (mortgage > (LLONG_MAX - smaller)) return -1;
    mortgage += smaller;
    return mortgage;
}

// largerSalary 
double largerSalary(double salary1, double salary2) {
    return (salary1 > salary2) ? salary1 : salary2;
}

// smallerSalary
double smallerSalary(double salary1, double salary2) {
    return (salary1 > salary2) ? salary2 : salary1;
}

