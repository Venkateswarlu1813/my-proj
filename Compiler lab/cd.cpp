#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX-1) stack[++top] = c;
}

char popc() {
    if (top >= 0) return stack[top--];
    return '\0';
}

char peek(int i) {
    if (top - i >= 0) return stack[top - i];
    return '\0';
}

int isTerminal(char c) {
    if (c == '+' || c == '*' || c == 'i' || c == '(' || c == ')' || c == '$')
        return 1;
    return 0;
}

char precedence(char a, char b) {
    if (a == '+' && b == '+') return '>';
    if (a == '+' && b == '*') return '<';
    if (a == '+' && b == 'i') return '<';
    if (a == '+' && b == '(') return '<';
    if (a == '+' && b == ')') return '>';
    if (a == '+' && b == '$') return '>';

    if (a == '*' && b == '+') return '>';
    if (a == '*' && b == '*') return '>';
    if (a == '*' && b == 'i') return '<';
    if (a == '*' && b == '(') return '<';
    if (a == '*' && b == ')') return '>';
    if (a == '*' && b == '$') return '>';

    if (a == 'i' && b == '+') return '>';
    if (a == 'i' && b == '*') return '>';
    if (a == 'i' && b == 'i') return ' ';
    if (a == 'i' && b == '(') return ' ';
    if (a == 'i' && b == ')') return '>';
    if (a == 'i' && b == '$') return '>';

    if (a == '(' && b == '+') return '<';
    if (a == '(' && b == '*') return '<';
    if (a == '(' && b == 'i') return '<';
    if (a == '(' && b == '(') return '<';
    if (a == '(' && b == ')') return '=';
    if (a == '(' && b == '$') return ' ';

    if (a == ')' && b == '+') return '>';
    if (a == ')' && b == '*') return '>';
    if (a == ')' && b == 'i') return ' ';
    if (a == ')' && b == '(') return ' ';
    if (a == ')' && b == ')') return '>';
    if (a == ')' && b == '$') return '>';

    if (a == '$' && b == '+') return '<';
    if (a == '$' && b == '*') return '<';
    if (a == '$' && b == 'i') return '<';
    if (a == '$' && b == '(') return '<';
    if (a == '$' && b == ')') return ' ';
    if (a == '$' && b == '$') return '=';

    return ' ';
}

char topMostTerminal() {
    for (int i = top; i >= 0; --i) {
        if (isTerminal(stack[i])) return stack[i];
    }
    return '$';
}

int reduce() {
    if (top >= 0 && stack[top] == 'i') {
        popc();
        push('E');
        printf("Reduce: i -> E\t\tStack: ");
        for (int j = 0; j <= top; ++j) printf("%c", stack[j]);
        printf("\n");
        return 1;
    }
    if (top >= 2 && stack[top] == ')' && stack[top-1] == 'E' && stack[top-2] == '(') {
        popc();
        popc();
        popc();
        push('E');
        printf("Reduce: (E) -> E\tStack: ");
        for (int j = 0; j <= top; ++j) printf("%c", stack[j]);
        printf("\n");
        return 1;
    }
    if (top >= 2 && stack[top] == 'E' && (stack[top-1] == '+' || stack[top-1] == '*') && stack[top-2] == 'E') {
        char op = stack[top-1];
        popc();
        popc();
        popc();
        push('E');
        if (op == '+') printf("Reduce: E+E -> E\tStack: ");
        else printf("Reduce: E*E -> E\tStack: ");
        for (int j = 0; j <= top; ++j) printf("%c", stack[j]);
        printf("\n");
        return 1;
    }
    return 0;
}

int main() {
    char input[MAX];
    printf("Enter input string (use 'i' for id, e.g. i+i*i):\n");
    scanf("%s", input);
    int len = strlen(input);
    if (input[len-1] != '$') {
        input[len] = '$';
        input[len+1] = '\0';
    }
    push('$');
    int ip = 0;
    printf("\nStack\t\tInput\t\tAction\n");
    while (1) {
        printf("%s\t\t%s\t", stack, &input[ip]);
        char a = topMostTerminal();
        char b = input[ip];
        char rel = precedence(a, b);
        if (rel == '<' || rel == '=') {
            push(b);
            ip++;
            printf("Shift '%c'\n", b);
        } else if (rel == '>') {
            int didReduce = reduce();
            if (!didReduce) {
                printf("Error: no valid reduction possible\n");
                break;
            }
        } else if (rel == '=' && a == '$' && b == '$') {
            printf("Accept\n");
            break;
        } else {
            printf("Error: invalid relation between '%c' and '%c'\n", a, b);
            break;
        }
        if (top == 1 && stack[0] == '$' && stack[1] == 'E' && input[ip] == '$') {
            printf("$E\t\t$\tAccept\n");
            break;
        }
    }
    if (top == 1 && stack[0] == '$' && stack[1] == 'E' && input[ip] == '$')
        printf("\nString successfully parsed (ACCEPTED)\n");
    else
        printf("\nString rejected (ERROR in parsing)\n");
    return 0;
}

