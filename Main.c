#include <stdio.h>
#include <string.h>
#include <math.h>
#define PI 3.14159265358979323846

void pIns() {
    printf("Available operations:\n");
    printf("+ : Addition\n");
    printf("- : Subtraction\n");
    printf("* : Multiplication\n");
    printf("/ : Division\n");
    printf("m : Modulus\n");
    printf("^ : Power\n");
    printf("r : Square Root\n");
    printf("l : Logarithm\n");
    printf("t : Logarithm\n");
    printf("f : Factorial\n");
    printf("p : Percentage\n");
    printf("a : Area of Circle\n");
    printf("c : Circumference of Circle\n");
    printf("x : Exit the calculator\n");
}

long long factorial(int n) {
    if (n < 0) {
        printf("Error: Factorial of negative numbers is not defined.\n");
        return -1;
    }
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

void calc(char operator, float a, float b) {
    switch (operator) {
        case '+':
            printf("Result: %.2f\n", a + b);
            break;
        case '-':
            printf("Result: %.2f\n", a - b);
            break;
        case '*':
            printf("Result: %.2f\n", a * b);
            break;
        case '/':
            if (b != 0) {
                printf("Result: %.2f\n", a / b);
            } else {
                printf("Error: Division by zero is not allowed.\n");
            }
            break;
        case 'm':
            if ((int)b != 0) {
                printf("Result: %d\n", (int)a % (int)b);
            } else {
                printf("Error: Modulus by zero is not allowed.\n");
            }
            break;
        case '^':
            printf("Result: %.2f\n", pow(a, b));
            break;
        case 'r':
            if (a >= 0) {
                printf("Result: %.2f\n", sqrt(a));
            } else {
                printf("Error: Square root of a negative number is not defined.\n");
            }
            break;
        case 'l':
            if (a > 0) {
                printf("Natural Log (ln): %.2f\n", log(a));
            } else {
                printf("Error: Logarithm of non-positive numbers is not defined.\n");
            }
            break;
        case 't':
            if (a > 0) {
                printf("Logarithm (Base 10): %.2f\n", log10(a));
            } else {
                printf("Error: Logarithm of non-positive numbers is not defined.\n");
            }
            break;
        case 'f':
            printf("Factorial of %.0f is: %lld\n", a, factorial((int)a));
            break;
        case 'p':
            printf("%.2f%% of %.2f is: %.2f\n", a, b, (a / 100) * b);
            break;
        case 'a':
            printf("Area of circle with radius %.2f is: %.2f\n", a, PI * a * a);
            break;
        case 'c':
            printf("Circumference of circle with radius %.2f is: %.2f\n", a, 2 * PI* a);
            break;
        default:
            printf("Invalid operator! Please choose a valid operation.\n");
    }
}

int main() {
    char name[50];
    char operator;
    float a, b;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Hello, %s! Welcome to the Calculator.\n", name);

    while (1) {
        pIns();
        printf("\nEnter the operator for your desired operation: ");
        scanf(" %c", &operator);

        if (operator == 'x') {
            printf("Exiting the calculator.\nGoodbye, %s!\n", name);
            break;
        }

        if (operator == 'r' || operator == 'l' || operator == 't' || operator == 'f' || operator == 'a' || operator == 'c') {
            printf("Enter the number: ");
            scanf("%f", &a);
            b = 0; 
        } else {
            printf("Enter the first number: ");
            scanf("%f", &a);
            printf("Enter the second number: ");
            scanf("%f", &b);
        }

        calc(operator, a, b);
    }

    return 0;
}
