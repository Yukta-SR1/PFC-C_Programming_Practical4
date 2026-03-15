/* CalculateMortgageB.c  
Practical 4, Part 1 (b) 
Yukta Singh Rajbanshi */ 
 
#include <stdio.h>

// Function declarations
double largerSalary(double salary1, double salary2);
double smallerSalary(double salary1, double salary2);

int main() {
    // Declare variables
    double salary1, salary2, mortgage;

    // Read in two salaries, salary1, salary2
    printf("Enter two salaries separated by a space: \n");
    scanf(" %lf %lf", &salary1, &salary2);

    // Calculate mortgage
    // call largerSalary function
    mortgage = largerSalary(salary1, salary2) * 3;

    // call smallerSalary function
    mortgage += smallerSalary(salary1, salary2);

    // Display the mortgage
    printf("The maximum size of mortgage is: £ %.2lf \n", mortgage);

    return 0;
}

// function stub for largerSalary(double, double)
double largerSalary(double salary1, double salary2) {
    return 1;
} // function stub

// function stub for smallerSalary(double, double)
double smallerSalary(double salary1, double salary2) {
    return 1;
} // function stub


