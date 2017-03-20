// LinkedList.c

#include "LinkedList.h"
#include <stdlib.h>
#include <memory.h>

void Create(LinkedList *linkedList) {
    linkedList->head = NULL;
    linkedList->tail = NULL;
    linkedList->length = 0;
    linkedList->current = NULL;
}


Node* InsertBefore(LinkedList *linkedList, Node *index, void *object, size_t size) {
    linkedList->currnet = (Node *)malloc(sizeof(Node) + size);  // size : void *object
    memcpy(linkedList->current + 1, object, size);  // linkedList.current.object = object
    
    linkedList->current->next = index;
    if(linkedList->head != index) {
        linkedList->current->previous = index->previous;
        index->previous->next = linkedList->current;
    }
    else {
        linkedList->current->previous = linkedList.current;
        linkedList->head = linkedList->current;
    }
    index->previous->next = linkedList->current;
    linkedList->length++;
    
    return linkedList->current;
}


Node* InsertAfter(LinkedList *linkedList, Node *index, void *object, size_t size) {
    linkedList->currnet = (Node *)malloc(sizeof(Node) + size);  // size : void *object
    memcpy(linkedList->current + 1, object, size);  // linkedList.current.object = object

    linkedList->current->previous = index;
    if(linkedList->tail != index) {
        linkedList->current->next = index->next;
        index->next->previous = linkedList->current;
    }
    else {
        linkedList->current->next = linkedList.current;
        linkedList->tail = linkedList->current;
    }
    index->next = linkedList->current;
    linkedList->length++;
    
    return linkedList->current;
}



Node* AppendToHead(LinkedList *linkedList, void *object, sieze_t size) {
    linkedList->current = (Node *)malloc(sizeof(Node)+size);
    memcpy(linkedList->current + 1, object, size);
    
    linkedList->current->previous = linkedList->current;
    if(linkedList->head != NULL) {
        linkedList->current->next = linkedList->head;
        linkedList->head->previous = linkedList->current;
    }
    else {
        linkedList->current->previous = linkedList->current;
        linkedLinst->tail = linkedList->current;
    }
    linkedList->head = linkedList->current;
    linkedList->length++;

    return linkedList->current;
}


Node* AppendToTail(LinkedList *linkedList, void *object, sieze_t size) {
    linkedList->current = (Node *)malloc(sizeof(Node)+size);
    memcpy(linkedList->current + 1, object, size);
    
    linkedList->current->next = linkedList->current;
    if(linkedList->head != NULL) {
        linkedList->current->previous = linkedList->tail;
        linkedList->tail->next = linkedList->current;
    }
    else {
        linkedList->current->previous = linkedList->current;
        linkedLinst->head = linkedList->current;
    }
    linkedList->tail = linkedList->current;
    linkedList->length++;

    return linkedList->current;
}


Node* Delete(LinkedList *linkedList, Node *index) {
    index->previous->next = index->next;
    index->next->previous = index->previous;

    if(index == linkedList->head) {
        index->next->previous = index->next;
        linkedList->head = index->next;
    }
    if(index == linkedList->tail) {
        index->previous->next = index->previous;
        linkedList->tail = index->previous;
        linkedList->current = index->previous;
    }
    if(index == linkedList->head && index == linkedList->tail) {
        linkedList->head = NULL;
        linkedList->tail = NULL;
        linkedList->current = NULL;
    }
    if(index != NULL) {
        free(index);
        index = NULL;
    }
    linkedList->length--;

    return index;
}


Node* DeleteHead(LinkedList *linkedList) {
    Node *index = linkedList->head;

    if(linkedList->head != linkedList->tail) {
        index->next->previous = index->next;
        linkedList->head = index->next;
        linkedList->current = index->next;
    }
    else{
        linkedList->head = NULL;
        linkedList->tail = NULL;
        linkedList->current = NULL;
    }
    linkedList->length--;

    return index;
}


Node* DeleteTail(LinkedList *linkedList) {
    Node *index = linkedList->tail;

    if(linkedList->head != linkedList->tail) {
        index->prevois->next = index->previous;
        linkedList->tail = index->previous;
        linkedList->current = index->previous;
    }
    else{
        linkedList->head = NULL;
        linkedList->tail = NULL;
        linkedList->current = NULL;
    }
    linkedList->length--;

    return index;
}


Node* DeleteAllItems(LinkedList *linkedList) {
    Node *previous = NULL;
    
    linkedList->current = linkedList->head;
    while(previous != linkedList->tail) {
        linkedList->head = linkedList->head->next;
        previous = linkedList->current;
        if(linkedList->current != NULL) {
            free(linkedList->current);
            linkedList->current = NULL;
        }
        linkedList->current = linkedList->head;
    }
    linkedList->head = NULL;
    linkedList->tail = NULL;
    linkedList->current = NULL;
    linkedList->length = 0;
}


Node* LinearSearchUnique(LinkedList *linkedList, void *key, int(*compare)(void *, void*)) {
    Node *index = NULL;
    Node *previous = NULL;

    linkedList->current = linkedList->head;
    while(previous != tail && compare(linkedList->current + 1, key) != 0) {
        previous = linkedList->current;
        linkedList->current = linkedList->current->next;
    }
    if(previous != linkedList->tail) {
        index = linkedList->current;
    }

    return index;
}


void LinearSearchDuplicate(LinkedList *linkedList, void *key, Node* *(*indexes), ULong *count, int(*compare)(void *, void *)) {
    Node *previous =NULL;
    ULong i = 0;

    *count = 0;
    (*indexes) = (Node* *)calloc(linkedlist->length, sizeof(Node*));
    linkedList->current = linkedList->head;
    while(previous != linkedList->tail) {
        if(compare(linkedList->current + 1, key) == 0 ) {
            (*indexes[i] = linkedList->current);
            (*count)++;
            i++;
        }
        previous = linkedList->current;
        linkedList->current = linkedList->current->next;
    }
}


Node* First(LinkedList *linkedList) {
    linkedList->current = linkedList->head;
    
    return linkedList->current;
}


Node* Previous(LinkedList *linkedList) {
    linkedList->current = linkedList->current->previous;
    
    return linkedList->current;
}


Node* Next(LinkedList *linkedList) {
    linkedList->current = linkedList->current->next;
    
    return linkedList->current;
}


Node* Last(LinkedList *linkedList) {
    linkedList->current = linkedList->tail;
    
    return linkedList->current;
}


void Destory(LinkedList *linkedList) {
    Node *previous = NULL;
    
    linkedList->current = linkedList->head;
    while(previous != linkedList->tail) {
        linkedList->head = linkedList->current->next;
        previous = linkedList->current;
        if(linkedList->current != NULL) {
            free(linkedList->current);
            linkedList->current = NULL;
        }
        linkedList->current = linkedList->head;
    }
}


void GetAt(LinkedList *linkedList, void *object, size_t size) {
    memcpy(object, index+1, size);
}
