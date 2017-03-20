// main.c
#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

typedef signed long int Long;
int compareIntegers(void *one, void *other);

int main(int argc, char *argv[]) {
    LinkedList linkedList;
    Node *index;
    Long object;
    Long key;
    Node* (*indexes);
    ULong count;
    ULong i;
    
    Create(&linkedList);
    
    object = 300;
    index = AppendToHead(&linkedList, &object, sizeof(Long));
    GetAt(&linkedList, index, &object, sizeof(Long));
    printf("%d\n", object);

    object = 100;
    index = AppendToHead(&linkedList, &object, sizeof(Long));
    GetAt(&linkedList, index, &object, sizeof(Long));
    printf("%d\n", object);

    object = 200;
    index = InsertBefore(&linkedList, index, &object, sizeof(Long));
    GetAt(&linkedList, index, &object, sizeof(Long));
    printf("%d\n", object);

    object = 500;
    index = InsertAfter(&linkedList, index, &object, sizeof(Long));
    GetAt(&linkedList, index, &object, sizeof(Long));
    printf("%d\n", object);

    object = 600;
    index = AppendToTail(&linkedList, &object, sizeof(Long));
    GetAt(&linkedList, index, &object, sizeof(Long));
    printf("%d\n", object);

    object = 700;
    index = AppendToTail(&linkedList, &object, sizeof(Long));
    GetAt(&linkedList, index, &object, sizeof(Long));
    printf("%d\n", object);

    index = Previous(&linkedList) // To move previous node
    index = Delete(&linkedList);
    if(index == NULL) {
        printf("Current node has been deleted.");
    }

    index = DeleteHead(&linkedList);
    if(index == NULL) {
        printf("Current node has been deleted.");
    }
    index = DeleteTail(&linkedList);
    if(index == NULL) {
        printf("Current node has been deleted.");
    }

    index = DeleteAllItems(&linkedList);
    if(index == NULL) {
        printf("All node have been deleted.");
    }

    index = Previous(&linkedList);
    GetAt(&linkedList, index, &object, sizeof(Long));
    printf("%d\n", object);


    index = First(&linkedList);
    GetAt(&linkedList, index, &object, sizeof(Long));
    printf("%d\n", object);

    index = Previous(&linkedList); // To check underflow
    GetAt(&linkedList, index, &object, sizeof(Long));
    printf("%d\n", object);

    index = Next(&linkedList);
    GetAt(&linkedList, index, &object, sizeof(Long));
    printf("%d\n", object);

    index = Last(&linkedList);
    GetAt(&linkedList, index, &object, sizeof(Long));
    printf("%d\n", object);

    index = Next(&linkedList); // To check overflow
    GetAt(&linkedList, index, &object, sizeof(Long));
    printf("%d\n", object);

    object = 200;
    index = AppendToHead(&linkedList, &object, sizeof(Long));
    GetAt(&linkedList, index, &object, sizeof(Long));
    printf("%d\n", object);

    object = 300;
    index = AppendToHead(&linkedList, &object, sizeof(Long));
    GetAt(&linkedList, index, &object, sizeof(Long));
    printf("%d\n", object);
    
    object = 200;
    index = AppendToHead(&linkedList, &object, sizeof(Long));
    GetAt(&linkedList, index, &object, sizeof(Long));
    printf("%d\n", object);

    object = 100;
    index = AppendToHead(&linkedList, &object, sizeof(Long));
    GetAt(&linkedList, index, &object, sizeof(Long));
    printf("%d\n", object);

    key = 100;
    LinearSearchDuplicate(&linkedList, &key, &indexes, &count, CompareIntegers);
    i = 0;
    while (i < count) {
        GetAt(&linkedList, index, &object, sizeof(Long));
        printf("%d ", object);
        i++;
    }
    printf("\n");
    if(indexes != NULL) {
        free(indexes);
        indexes = NULL;
    }



    Destroy(&linkedList);

    return 0;

}


int compareIntegers(void *one, void *other) {
    int ret;

    if(*((Long*)one) > *((Long*)other)) {
        ret = 1;
    }

    else if(*((Long*)one) > *((Long*)other)) {
        ret = 0;
    }
    
    else if(*((Long*)one) > *((Long*)other)) {
        ret = -1;
    }

    return ret;
}
