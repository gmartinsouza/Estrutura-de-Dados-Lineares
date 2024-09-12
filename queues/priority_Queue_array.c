#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "priorityQueue.h" 

#define PRIORITY_QUEUE_MAX_SIZE 100

struct priorityQueue {
    int size;
    int data[PRIORITY_QUEUE_MAX_SIZE];
};

PriorityQueue *PriorityQueue_Create() {
    PriorityQueue *queue = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    if (queue == NULL) {
        printf("Erro ao alocar memória para a fila de prioridade.\n");
        return NULL;
    }
    queue->size = 0;
    return queue;
}

void PriorityQueue_Destroy(PriorityQueue *queue) {
    free(queue);
}

bool PriorityQueue_IsEmpty(PriorityQueue *queue) {
    return queue->size == 0;
}

int findLocation(PriorityQueue *priorityQueue, int value) {
    int location = 0;
    while (location < priorityQueue->size && priorityQueue->data[location] < value) {
        location++;
    }
    return location;
}

int openSpace(PriorityQueue *priorityQueue, int location) {
    for (int i = priorityQueue->size; i > location; i--) {
        priorityQueue->data[i] = priorityQueue->data[i - 1];
    }
    return location;
}

void PriorityQueue_Enqueue(PriorityQueue *queue, int value) {
    if (queue->size == PRIORITY_QUEUE_MAX_SIZE) {
        printf("Erro: a fila de prioridade está cheia.\n");
        return;
    }

    int location = findLocation(queue, value);
    location = openSpace(queue, location);

    queue->data[location] = value;
    queue->size++;
}

int PriorityQueue_Dequeue(PriorityQueue *queue) {
    if (PriorityQueue_IsEmpty(queue)) {
        printf("Erro: a fila de prioridade está vazia.\n");
        return 0;
    }

    int front = queue->data[0];
    for (int i = 0; i < queue->size - 1; i++) {
        queue->data[i] = queue->data[i + 1];
    }
    queue->size--;
    return front;
}
