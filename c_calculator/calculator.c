#include <stdio.h>
#include <stdlib.h>

int main()
{
    int     a, b;
    char    operator;
    float   result;
    //char  expression[4];

    printf("Operator: ");
    scanf("%c", &operator);
    printf("First number: ");
    scanf("%i", &a);
    printf("Second number: ");
    scanf("%i", &b);

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
