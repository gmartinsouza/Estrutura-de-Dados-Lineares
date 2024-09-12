#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../stacks/stack.h"
#include "parenthesis.h"



bool isOpen(char character) {
    return character == '(' || character == '[' || character == '{';
}


char getOpen(char closeCharacter) {
    switch (closeCharacter) {
        case ')':
            return '(';
        case ']':
            return '[';
        case '}':
            return '{';
        default:
            return '\0'; 
    }
}


bool Algorithm_Parenthesis_IsValid(char *expression) {
    int size = strlen(expression);
    Stack *stack = Stack_Create(size);
    if (stack == NULL) {
        return false; 
    }

    for (int i = 0; i < size; i++) {
        char currentChar = expression[i];
        if (isOpen(currentChar)) {
            Stack_Push(stack, currentChar);
        } else {
            if (Stack_IsEmpty(stack) || Stack_Pop(stack) != getOpen(currentChar)) {
                Stack_Destroy(stack);
                return false;
            }
        }
    }

    bool isValid = Stack_IsEmpty(stack); 
    Stack_Destroy(stack);
    return isValid;
}
