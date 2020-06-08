#include <stdio.h>
#include<stdlib.h>
#include "Header.h"
#include <iostream>
using namespace std;
void ver3()
{
    StackNodePtr stackPtr = NULL;  /* points to stack top */
    int  control;
    float value = 0;

    instructions();
    printf("Enter your control: \n");
    cin >> control;

    while (control != 4) {

        switch (control) {
        case (1):      /* push value onto stack */
            printf("Enter an number: ");
            cin >> value;
            push(stackPtr, value);
            printStack(stackPtr);
            break;
        case (2):      /* pop value off stack */
            if (!isEmpty(stackPtr))
                printf("The popped value is %f.\n", pop(stackPtr));
            printStack(stackPtr);
            break;
        case (3):
            printStack(stackPtr);
            break;
        default:
            printf("Invalid control.\n\n");
            instructions();
            break;
        }
        printf("\n");
        printf("Enter your control: \n");
        scanf_s(" %d", &control);
    }
    printf("End of run.\n");
    return;
}
void instructions(void)
{
    printf("Enter control:\n"
        "1 to push a value on the stack\n"
        "2 to pop a value off the stack\n"
        "3 to print out stack\n"
        "4 to end\n");
}

/* Insert a node at the stack top */
void push(StackNodePtr& topPtr, float info)
{
    // StackNodePtr newPtr;

    StackNodePtr newPtr = (StackNodePtr)malloc(sizeof(StackNode));
    if (newPtr != NULL)
    {
        newPtr->data = info;
        newPtr->nextPtr = topPtr;
        topPtr = newPtr;
    }
    else
        printf("%f not inserted. No memory available.\n", info);
    return;
}

/* Remove a node from the stack top */
float pop(StackNodePtr& topPtr)
{
    StackNodePtr tempPtr;
    float popValue;

    tempPtr = topPtr;
    popValue = (topPtr)->data;
    topPtr = (topPtr)->nextPtr;
    free(tempPtr);
    return popValue;
}

/* Print the stack */
void printStack(StackNodePtr currentPtr)
{
    if (currentPtr == NULL)
        printf("The stack is empty.\n\n");
    else {
        printf("The stack is:\n");

        while (currentPtr != NULL) {
            printf("%f --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }

        printf("NULL\n\n");
    }
}

/* Is the stack empty? */
int isEmpty(StackNodePtr topPtr)
{
    return topPtr == NULL;
}