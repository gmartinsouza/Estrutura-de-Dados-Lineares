#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "../stacks/stack.h"
#include "sequences.h"

bool Algorithm_Sequences_IsValid(int *pushed, int *popped, int size) {
    Stack *stack = Stack_Create();
    int pushIndex = 0;
    int popIndex = 0;

    while (pushIndex < size) {
        Stack_Push(stack, pushed[pushIndex++]);
        while (!Stack_IsEmpty(stack) && Stack_Peek(stack) == popped[popIndex]) {
            Stack_Pop(stack);
            popIndex++;
        }
    }

    bool isValid = Stack_IsEmpty(stack);
    Stack_Destroy(stack);
    return isValid;
}
