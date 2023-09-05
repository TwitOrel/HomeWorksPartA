#ifndef HW4_ISRQUEUE_H
#define HW4_ISRQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedList.h"

typedef struct ISRQueue* ISRQueue;

ISRQueue ISRCreate(Element (*cpy)(Element), void (*fre)(Element), bool (*cmp)(Element e1, Element e2));

void ISRDestroy(ISRQueue queue);

void ISREnqueue(ISRQueue queue, Element pips);

void ISREnqueueFirst(ISRQueue queue, Element pips);

void ISREnqueueAfter(ISRQueue queue,Element pips, Element existing);

Element ISRDequeue(ISRQueue queue);

unsigned int ISRQueueSize(ISRQueue queue);

ISRQueue ISRQueueSplit(ISRQueue queue);
#endif //HW4_ISRQUEUE_H
