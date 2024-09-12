#include <stdlib.h>
#include "singlyLinkedList.h"

struct singlyLinkedList
{
    SinglyListNode *head;
    int size ;
};

SinglyLinkedList * SinglyLinkedList_Create(){
   SinglyLinkedList * list = (SinglyLinkedList *) malloc (sizeof(SinglyLinkedList));

    if(list == NULL){
        return NULL;
   }

    list->head = NULL;
    list->size = 0;

   return list;
} 

void SinglyLinkedList_Destroy(SinglyLinkedList *list){
    if (list == NULL) return;
    SinglyListNode *current = SinglyLinkedList_GetHead(list);
    SinglyListNode *next;
    while (current != NULL) {
        next = SinglyListNode_GetNext(current);
        SinglyListNode_Destroy(current);
        current = next;
    }
    free(list);
}

bool SinglyLinkedList_IsEmpty(SinglyLinkedList *list){
    return list->size == 0;
}

void SinglyLinkedList_AddFirst(SinglyLinkedList *list, int value){
    SinglyListNode *newHead = SinglyListNode_Create(value, SinglyLinkedList_GetHead(list));
    SinglyLinkedList_SetHead(list, newHead);
    list->size++;
}

void SinglyLinkedList_AddLast(SinglyLinkedList *list, int value){
    SinglyListNode *newTail = SinglyListNode_Create(value, NULL);
    if (SinglyLinkedList_IsEmpty(list)) {
        SinglyLinkedList_SetHead(list, newTail);
    } else {
        SinglyListNode *oldTail = SinglyLinkedList_GetHead(list);
        while (SinglyListNode_GetNext(oldTail) != NULL) {
            oldTail = SinglyListNode_GetNext(oldTail);
        }
        SinglyListNode_SetNext(oldTail, newTail);
    }
    list->size++;
}

void SinglyLinkedList_Delete(SinglyLinkedList *list, SinglyListNode *nodeToDelete){
    //if (list == NULL || list->head == NULL || nodeToDelete == NULL) return;

    if (list->head == nodeToDelete) {
        SinglyListNode *temp = list->head;
        list->head = SinglyListNode_GetNext(list->head);
        SinglyListNode_Destroy(temp);
    } else {
        SinglyListNode *current = list->head;
        while (current != NULL && SinglyListNode_GetNext(current) != nodeToDelete) {
            current = SinglyListNode_GetNext(current);
        }
        if (current != NULL) {
            SinglyListNode_SetNext(current, SinglyListNode_GetNext(nodeToDelete));
            SinglyListNode_Destroy(nodeToDelete);
        }
    }
    list->size--;
}

SinglyListNode * SinglyLinkedList_GetHead(SinglyLinkedList *list){
    return list->head;
}

void SinglyLinkedList_SetHead(SinglyLinkedList *list, SinglyListNode *newHead){
    list->head = newHead;
}

int SinglyLinkedList_GetSize(SinglyLinkedList *list){
    if (list == NULL) return 0;
    return list->size;
}

SinglyListNode *SinglyLinkedList_Search(SinglyLinkedList *list, int value){
    SinglyListNode *current =  SinglyLinkedList_GetHead(list);
    while (current != NULL) {
        if (SinglyListNode_GetValue(current) == value) {
            return current;
        }
        current = SinglyListNode_GetNext(current);
    }
    return NULL;
}

int * SinglyLinkedList_ToArray(SinglyLinkedList *list){ 
    int size = SinglyLinkedList_GetSize(list);
    int* array = (int*) malloc(size * sizeof(int));
    if (array == NULL) {
        return NULL;
    }

    SinglyListNode* current = SinglyLinkedList_GetHead(list);
    for (int i = 0; i < size; i++) {
        *(array + i) = SinglyListNode_GetValue(current);
        current = SinglyListNode_GetNext(current);
    }

    return array;
}
