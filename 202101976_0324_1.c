#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
typedef char element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}STATCKTYPE;

void init_stack(STATCKTYPE* s)
{
	s->top = -1;
}

int is_empty(STATCKTYPE* s)
{
	return (s->top == -1);
}

int is_full(STATCKTYPE* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(STATCKTYPE* s, element item)
{
	if (is_full(s))
	{
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

element pop(STATCKTYPE* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

element peek(STATCKTYPE* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "스택 포화 에러\n");
		exit(1);
	}
	else return  s->data[s->top];
}

int eval(char exp[])
{
	int op1, op2, value, i = 0;
	int len = strlen(exp);
	char ch;
	STATCKTYPE s;

	init_stack(&s);
	for (int i = 0; i < len; i++)
	{
		ch = exp[i];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/')
		{
			value = ch - '0';
			push(&s, value);
		}
		else 
		{
			op2 = pop(&s);
			op1 = pop(&s);

			switch (ch) 
			{
			case'+': push(&s, op1 + op2); break;
			case'-': push(&s, op1 - op2); break;
			case'*': push(&s, op1 * op2); break;
			case'/': push(&s, op1 / op2); break;
			}
		}
	}
	return pop(&s);
}


int main(void)
{
	int result;
	printf("후위표기식은 82/3-32*+\n");
	result = eval("75*9+63/-");
	printf("결과값은 %d\n", result);
}