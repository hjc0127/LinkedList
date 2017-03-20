// LinkedList.h 

#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include <stddef.h>  // size_t

// Type definition
typedef unsigned long int ULong;
typedef struct _node Node;
typedef struct _node {
    Node *previous;
    // void *object;
    Node *next;
} Node;
typedef struct _linkedList {
    Node *head;
    Node *tail;
    ULong length;
    Node *current;
} LinkedList;

// Fuction declaration
void Create(LinkedList *linkedList);
Node* InsertBefore(LinkedList *linkedList, Node *index, void *object, size_t size);
Node* InsertAfter(LinkedList *linkedList, Node *index, void *object, size_t size);
Node* AppendToHead(LinkedList *linkedList, void *object, sieze_t size);
Node* AppendToTail(LinkedList *linkedList, void *object, sieze_t size);
Node* Delete(LinkedList *linkedList, Node *index);
Node* DeleteHead(LinkedList *linkedList);
Node* DeleteTail(LinkedList *linkedList);
Node* DeleteAllItems(LinkedList *linkedList);
Node* LinearSearchUnique(LinkedList *linkedList, void *key, int(*compare)(void *, void*));
void LinearSearchDuplicate(LinkedList *linkedList, void *key, Node* *(*indexes), ULong *count, int(*compare)(void *, void *));
Node* First(LinkedList *linkedList);
Node* Previous(LinkedList *linkedList);
Node* Next(LinkedList *linkedList);
Node* Last(LinkedList *linkedList);
void Destroy(LinkedList *linkedList);
void GetAt(LinkedList *linkedList, void *object, size_t size);

#endif // _LINKEDLIST_H


