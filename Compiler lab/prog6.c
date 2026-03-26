#include <stdio.h>
#include <string.h>

int E(), Edash(), T(), Tdash(), F();
char *ip;
char string[50];

int main() {
    printf("Enter the string\n");
    scanf("%s", string);
    ip = string;
    printf("\n\nInput\tAction\n--------------------------------\n");

    if (E() && *ip == '\0') {   // Check end of string
        printf("\n--------------------------------\n");
        printf("\nString is successfully parsed\n");
    } else {
        printf("\n--------------------------------\n");
        printf("Error in parsing String\n");
    }
}

int E() {
    printf("%s\tE -> T E'\n", ip);
    if (T()) {
        if (Edash()) {
            return 1;
        }
    }
    return 0;
}

int Edash() {
    if (*ip == '+') {
        printf("%s\tE' -> + T E'\n", ip);
        ip++;
        if (T()) {
            if (Edash()) return 1;
        }
        return 0;
    } else {
        printf("%s\tE' -> ^\n", ip);
        return 1;
    }
}

int T() {
    printf("%s\tT -> F T'\n", ip);
    if (F()) {
        if (Tdash()) return 1;
    }
    return 0;
}

int Tdash() {
    if (*ip == '*') {
        printf("%s\tT' -> * F T'\n", ip);
        ip++;
        if (F()) {
            if (Tdash()) return 1;
        }
        return 0;
    } else {
        printf("%s\tT' -> ^\n", ip);
        return 1;
    }
}

int F() {
    if (*ip == '(') {
        printf("%s\tF -> ( E )\n", ip);
        ip++;
        if (E()) {
            if (*ip == ')') {
                ip++;
                return 1; // ? Return 1 for success
            }
        }
        return 0;
    } else if (*ip == 'i') { // Assume 'i' is the start of "id"
        ip++;
        printf("%s\tF -> id\n", ip);
        return 1;
    }
    return 0;
}

