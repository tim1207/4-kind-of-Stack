#pragma once
extern struct stackNode {   /* self-referential structure */
    float data;
    struct stackNode* nextPtr;
};
#define STACK_SIZE 3
typedef  stackNode StackNode;
typedef StackNode* StackNodePtr;

template <class T>
struct TPStruct
{
	TPStruct(int size) : arraysize(size), array(new T[size]) {}
	~TPStruct() {
		delete[] array;
	}
	T* array;
	int arraysize;
};

void push(StackNodePtr&, float);
float pop(StackNodePtr&);
int isEmpty(StackNodePtr);
void printStack(StackNodePtr);
void instructions(void);
void ver1();
void ver2();
void ver3();
void struct_template();

