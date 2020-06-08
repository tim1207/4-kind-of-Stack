#include <stdio.h>
#include<stdlib.h>
#include "Header.h"
#include <iostream>
using namespace std;

void printver2(float*, int);

int StackSet(float** array, int size = 3)
{
	*array = (float*)malloc(sizeof(float) * size);

	if (array == NULL) {
		printf("fail to allocate malloc\n");
		return 0;
	}
	return 1;
}

void ver2()
{
	float* array = { 0 };
	float value = 0, temp = 0;
	int  size = 0, index = 0, check = 0;
	int input;
	printf("Change the size of array:\nThe default size is 3");
	printf("(1)Yes (2)No");
	cin >> check;
	if (check == 1) {
		printf("Input the size of array :");
		cin >> size;
		temp = StackSet(&array, size);
	}
	else if (check == 2) {
		temp = StackSet(&array);
	}
	if (temp == 0)return;
	for (int i = 0; i < size; i++)
		*(array + i) = 0;
	instructions();
	printf("Enter your control: \n");
	scanf_s(" %d", &input);
	while (input != 4)
	{
		switch (input)
		{
		case (1):
			if (index >= size)
			{
				printf("Stack is Full !!\n");
				break;
			}
			printf("(push)\n");
			printf("Enter a number: ");
			cin >> value;
			*(array + index) = value;
			index++;
			break;
		case (2):
			if (index == 0)
			{
				printf("Stack is Empty !!\n");
				break;
			}
			index--;
			printf("(pop)\n");
			printf("The popped value is %f.\n", *(array + index));
			break;
		case (3):
			if (index == 0)
			{
				printf("Array is Empty !!\n");
				break;
			}
			printver2(array, index);
		}
		printf("\n");
		printf("Enter your control: \n");
		scanf_s(" %d", &input);
	}
	printf(" End the version2 !!\n");
	free(array);
	return;
}
void printver2(float* stack, int index)
{
	for (int i = index - 1; i > 0; i--)
	{
		printf(" %f -->", *(stack + i));
	}
	printf(" %f \n", *stack);
	return;
}