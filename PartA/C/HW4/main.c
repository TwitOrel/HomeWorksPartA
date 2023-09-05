#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "LinkedList.h"
#include "ISRQueue.h"

Element cpy(Element element){
    if(element == NULL)
        return NULL;
    return strdup((char*)element);
}

bool cmp(Element e1, Element e2){
    if (strlen(e1) != strlen(e2)) {
        return false;
    }
    for (int i = 0; i < strlen(e1); i++) {
        if(toupper(((char*)e2)[i]) != toupper(((char*)e1)[i]))
        return false;
    }
    return true;
}
void printQueue(ISRQueue queue){
    int size = ISRQueueSize(queue);
    for (int i = 0; i < size; ++i) {
        printf("%s ",(char*) ISRDequeue(queue));
    }
    printf("\n");
}

int main() {
    ISRQueue queue = ISRCreate(cpy, free, cmp);
    if (queue == NULL) {
        return -1;
    }
    ISREnqueue(queue, "Beth");
    ISREnqueue(queue, "Kylian");
    ISREnqueue(queue, "Zlatan");
    ISREnqueue(queue, "Mohamed");
    ISREnqueue(queue, "Ada");
    free(ISRDequeue(queue));
    ISREnqueueFirst(queue, "Lionel");
    ISREnqueueAfter(queue, "Karim", "Kylian");
    ISREnqueueAfter(queue, "Megan", "Alex");
    ISRQueue queue2 = ISRQueueSplit(queue);
    if (queue2 == NULL) {
        return -1;
    }
    printQueue(queue);
    printQueue(queue2);
    ISRDestroy(queue);
    ISRDestroy(queue2);
    return 0;
}