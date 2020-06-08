#include <stdio.h>
#include<stdlib.h>
#include "Header.h"
#include <iostream>

using namespace std;

bool isFull4(int top, int size)
{
	if (top == size)
		return 1;
	else
		return 0;
}
bool isEmpty4(int top)
{
	if (top == 0)
		return 1;
	else
		return 0;
}


template <class T>
bool push4(TPStruct<T> * stack, T data, int top)
{
	if (top == stack->arraysize)
		return 0;
	else
	{
		*(stack->array + top) = data;
		return 1;
	}
}

template <class T>
bool pop4(TPStruct<T> *stack, int top)
{
	if (isEmpty4(top) == 1)
	{
		printf("There is no num to pop\n");
		return 0;
	}
	else
	{	
		cout <<"The popped elements is "<< *(stack->array+top - 1)<<endl;
		return 1;
	}
}
template <class T>
void print_stack4(TPStruct<T> *stack, int top)
{
	for (int i = top - 1; i > 0; i--)
		cout << *(stack->array + i) << "--> ";
	cout << *(stack->array) << endl;
	return;
}

template <class T>
void ver4(TPStruct <T>*stack,int size)
{	
	int top = 0;
	while (1)
	{
		int input;
		T data;
		printf("1) push	\n2) pop\n3) printStack\n4) 版本結束\n");
		cin >> input;
		if (input == 4) break;
		switch (input)
		{
		case 1:
			if (isFull4(top,size)==1)
			{
				printf("Stack is Full !!\n");
				break;
			}
			else {
				printf("(push)\n");
				printf("Enter a number: ");
				cin >> data;
				push4(stack, data, top);
				top++;
			}
			break;
		case 2:
			if (isEmpty4(top)==1)
			{
				printf("Stack is Empty !!\n");
				break;
			}			
			if (pop4(stack, top)==1)	
				top--;
			break;
		case 3:
			if (isEmpty4(top)==1)
			{
				printf("Stack is Empty !!\n");
				break;
			}
			print_stack4(stack, top);
			break;
		}

	}
	return;
}

void struct_template() 
{
	int  type;
	printf("(1) int \t(2) float \t(3)END ");
	cin >> type;
	int size;
	printf("\nstack 大小:");
	cin >> size;
	while (type !=3)
	{
		
		if (type == 1) {			
			TPStruct <int> stack(size);
			ver4(&stack,size);
		}
		if (type == 2) {
			TPStruct <float> stack(size);
			ver4(&stack,size);
		}
		printf("(1) int \t(2) float \t(3)END ");
		cin >> type;
	}
}
 
