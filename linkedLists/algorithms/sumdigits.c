#include <stdlib.h>
#include "sumdigits.h"


SinglyLinkedList* Algorithm_SumDigits(SinglyLinkedList* listAddendOne, SinglyLinkedList* listAddendTwo) {
    SinglyLinkedList* output = SinglyLinkedList_Create();
    if (output == NULL) {
        return NULL;
    }

    int* arrayOne = SinglyLinkedList_ToArray(listAddendOne);
    int* arrayTwo = SinglyLinkedList_ToArray(listAddendTwo);

    int sizeOne = SinglyLinkedList_GetSize(listAddendOne);
    int sizeTwo = SinglyLinkedList_GetSize(listAddendTwo);

    int biggerSize;
    if(sizeOne > sizeTwo){
        biggerSize = sizeOne;
    }else{
        biggerSize = sizeTwo;
    }
    int jumpValue = 0;

    for (int i = 0; i < biggerSize; i++) {
        int valOne = 0;
        int valTwo = 0;

        if (i < sizeOne) {
            valOne = *(arrayOne + i);
        }

        if (i < sizeTwo) {
            valTwo = *(arrayTwo + i);
        }

        int sum = valOne + valTwo + jumpValue;
        jumpValue = sum / 10;
        SinglyLinkedList_AddLast(output, sum % 10);
    }

    if (jumpValue > 0) {
        SinglyLinkedList_AddLast(output, jumpValue);
    }

    free(arrayOne);
    free(arrayTwo);

    return output;
}
