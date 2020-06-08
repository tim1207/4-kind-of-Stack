#include <stdio.h>
#include "Header.h"
#include <iostream>
using namespace std;
#define STACK_SIZE 3
void printver1(float*, int);
void ver1()
{

	float stack[STACK_SIZE] = { 0 }, value = 0;
	int index = 0;
	int input;
	instructions();
	printf("Enter your control: \n");
	scanf_s(" %d", &input);

	while (input != 4)
	{
		switch (input)
		{
		case (1):
			if (index >= STACK_SIZE)
			{
				printf("Stack is Full !!\n");
				break;
			}
			printf("(push)\n");
			printf("Enter a number: ");
			cin >> value;
			stack[index] = value;
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
			printf("The popped value is %f.\n", stack[index]);

			break;
		case (3):
			if (index == 0)
			{
				printf("Stack is Empty !!\n");
				break;
			}
			printver1(stack, index);
			break;
		}
		printf("\n");
		printf("Enter your control: \n");
		scanf_s(" %d", &input);
	}
	printf(" End the version1 !!\n");
	return;
}
void printver1(float* stack, int index)
{
	for (int i = index - 1; i > 0; i--)
	{
		printf("%f --> ", stack[i]);
	}
	printf("%f \n", stack[0]);
	return;
}