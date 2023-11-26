#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100000


int isOpening(char ch) {
    return (ch == '(' || ch == '{' || ch == '[');
}


int isValidPair(char open, char close) {
    return ((open == '(' && close == ')') || 
	(open == '{' && close == '}') || (open == '[' && close == ']'));
}


int isBeautiful(char S[]) {
    int len = strlen(S);
    char stack[MAX_SIZE];
    int top = -1; 
    int i;
    for (i = 0; i < len; i++) {
        char currentChar = S[i];
        if (isOpening(currentChar)) {
            stack[++top] = currentChar; 
        } else {
            if (top == -1 || !isValidPair(stack[top], currentChar)) {
                return 0;
            }
            top--;
        }
    }

    return (top == -1); 
}

int main() {
    char S[MAX_SIZE];
    scanf("%s", S);
    
    if (isBeautiful(S)) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    return 0;
}
