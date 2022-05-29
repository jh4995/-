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

int prec(char op)
{
	switch (op) 
	{
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}

void infix_to_postfix(char exp[])
{
	int i = 0;
	char ch, top_op;
	int len = strlen(exp);
	STATCKTYPE s;

	init_stack(&s);
	for (int i = 0; i < len; i++)
	{
		ch = exp[i];
		switch (ch)
		{
		case '+': case '-': case '*': case '/':
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
				printf("%c", pop(&s));
			push(&s, ch);
			break;

		case '(':
			push(&s, ch);
			break;

		case ')':
			top_op = pop(&s);
			while (top_op != '(') 
			{
				printf("%c", top_op);
				top_op = pop(&s);
			}
			break;

		default:
			printf("%c", ch);
			break;
		}
	}
	while (!is_empty(&s))
		printf("%c", pop(&s));

}
int main(void)
{
	char* s = "(2+3)*4+9";
	printf("중위표시수식 %s \n", s);
	printf("후위표시수식 ");
	infix_to_postfix(s);
	printf("\n");
	return 0;
}

