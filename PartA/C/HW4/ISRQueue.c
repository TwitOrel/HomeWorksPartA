#include <malloc.h>
#include <time.h>
#include "ISRQueue.h"
#include "LinkedList.h"
struct ISRQueue{
    LinkedList list;
    Element (*cpy)(Element);
    void (*fre)(Element);
    bool (*cmp)(Element e1, Element e2);
};
ISRQueue ISRCreate(Element (*cpy)(Element), void (*fre)(Element), bool (*cmp)(Element e1, Element e2)){
    ISRQueue queue = malloc(sizeof (struct ISRQueue));
    if(queue == NULL){
        return NULL;
    }
    queue->cmp = cmp;
    queue->cpy = cpy;
    queue->fre = fre;
    queue->list = LLCreate(cpy,fre);
    return queue;
}
void ISRDestroy(ISRQueue queue){
    LLDestroy(queue->list);
    free(queue);
}
void ISREnqueue(ISRQueue queue, Element pips){
    LLAdd(queue->list,LLSize(queue->list),pips);
}
void ISREnqueueFirst(ISRQueue queue, Element pips){
    LLAdd(queue->list,0,pips);
}
void ISREnqueueAfter(ISRQueue queue,Element pips, Element existing){
    unsigned int size = LLSize(queue->list);
    for (int i = 0; i < size; i++){
        if(queue->cmp(existing, LLAt(queue->list,i))){
            LLAdd(queue->list,i+1,existing);
            return;
        }
    }
    ISREnqueue(queue,pips);
}
Element ISRDequeue(ISRQueue queue){
    return LLRemove(queue->list,0);
}
unsigned int ISRQueueSize(ISRQueue queue){
    return LLSize(queue->list);
}
ISRQueue ISRQueueSplit(ISRQueue queue){
    srand(time(NULL));
    ISRQueue newQueue = ISRCreate(queue->cpy,queue->fre,queue->cmp);
    if(newQueue == NULL)return NULL;
    Element element;
    unsigned int size = LLSize(queue->list)/2;

    for (unsigned int i = LLSize(queue->list); i > size; i--) {
        if(LLSize(newQueue->list) == 0) {
            element = LLRemove(queue->list, i-1);
            LLAdd(newQueue->list, 0, element);
        }
        else {
            element = LLRemove(queue->list, i-1);
            LLAdd(newQueue->list, rand() % LLSize(newQueue->list), element);
        }
        free(element);
    }
    return newQueue;
}