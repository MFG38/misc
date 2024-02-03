#include <stdio.h>
#include <stdlib.h>

int main()
{
    int     a, b;
    char    operator;
    float   result;

    printf("Enter expression: ");
    scanf("%i%c%i", &a, &operator, &b);

    switch(operator)
    {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a * b;
        break;
    case '/':
        result = a / b;
        break;
    default:
        printf("Invalid operator detected");
        break;
    }

    printf("%lf", result);

    return 0;
}
