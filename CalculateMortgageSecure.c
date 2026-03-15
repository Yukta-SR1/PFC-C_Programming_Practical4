/* CalculateMortgageSecure.c
   Practical 4, Part 2(a)
   Yukta Singh Rajbanshi*/

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

// Function declarations
double largerSalary(double salary1, double salary2);
double smallerSalary(double salary1, double salary2);
bool   validateSalary(double salary);
bool   readSalaries(double *salary1, double *salary2);
double calculateMortgage(double salary1, double salary2);

// main
int main() {
    double salary1, salary2, mortgage;

    printf("Enter two salaries separated by a space:\n");

    // Step 1: Read and validate format
    if (!readSalaries(&salary1, &salary2)) {
        printf("Error: Invalid input. Program terminated.\n");
        return 1;
    }

    // Step 2: Validate salary ranges
    if (!validateSalary(salary1) || !validateSalary(salary2)) {
        printf("Error: Salaries must be positive and within valid range.\n");
        return 1;
    }

    // Step 3: Calculate with overflow protection
    mortgage = calculateMortgage(salary1, salary2);
    if (mortgage < 0) {
        printf("Error: Mortgage calculation failed.\n");
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
