#include <stdio.h>
#include <string.h>

int main ()
{
    char arithmetic[5] = {'+', '-', '*', '/', '%'};
    char relational[4] = {'<', '>', '!', '='};
    char bitwise[4] = {'&', '^', '~', '|'};
    char str[3] = {' ', ' ', '\0'};

    printf("Enter value to be identified: ");
    scanf("%2s", str);

    int i;

    if (((str[0] == '&' || str[0] == '|') && str[0] == str[1]) || (str[0] == '!' && str[1] == '\0')) {
        printf("\nIt is Logical operator");
    }

    for (i = 0; i < 4; i++) {
        if (str[0] == relational[i] && (str[1] == '=' || str[1] == '\0')) {
            printf("\nIt is Relational Operator");
            break;
        }
    }

    for (i = 0; i < 4; i++) {
        if ((str[0] == bitwise[i] && str[1] == '\0') || ((str[0] == '<' || str[0] == '>') && str[1] == str[0])) {
            printf("\nIt is Bitwise Operator");
            break;
        }
    }

    if (str[0] == '?' && str[1] == ':')
        printf("\nIt is Ternary Operator");

    for (i = 0; i < 5; i++) {
        if ((str[0] == '+' || str[0] == '-') && str[0] == str[1]) {
            printf("\nIt is Unary Operator");
            break;
        } else if ((str[0] == arithmetic[i] && str[1] == '=') || (str[0] == '=' && str[1] == '\0')) {
            printf("\nIt is Assignment Operator");
            break;
        } else if (str[0] == arithmetic[i] && str[1] == '\0') {
            printf("\nIt is Arithmetic Operator");
            break;
        }
    }

    return 0;
}

