#include<stdio.h>
#include<stdlib.h>
#define MAX 50
 int top = -1;
int stack[MAX];
 
void push(char item)
{
	if(top == (MAX - 1))
	{
		printf("Stack is Full\n");
		return;
	}
	top++;
	stack[top] = item;
}
 
char pop()
{
	if(top == -1)
	{
		printf("Stack is Empty\n");
		exit(1);
	}
	return(stack[top--]);
}
 
int match_paranthesis(char a, char b)
{
	if(a == '[' && b == ']')
	{
		return 1;
	}
	else if(a == '{' && b == '}')
	{
		return 1;	
	}
	else if(a == '(' && b == ')')
	{
		return 1;
	}
	return 0;
}
 
int check_paranthesis(char expression[])
{
	int count,k;
	char temp;
	for(count = 0; count < strlen(expression); count++)
	{
		if(expression[count] == '(' || expression[count] == '{' || expression[count] == '[')
		{
			push(expression[count]);
		}
		if(expression[count] == ')' || expression[count] == '}' || expression[count] == ']')
		{
			if(top == -1)
			{
				printf("The Expression has unbalanced parentheses\n");
				return 0;
			}
			else
			{
				temp = pop();
				if(!match_paranthesis(temp, expression[count]))
				{
					k++;
					printf("\nThe parenthesis is Mismatched !");
					printf("\nThe number of Mismatched Parentheses in the Expression is : %d\n",k);
					return 0;
				}
			}
		}
	}
	if(top == -1)
	{
		printf("\nThe Expression has Balanced Parentheses\n"); 
		return 1;
	}
	else 
	{
		printf("The Expression has unbalanced parentheses\n");	
		return 0;
	}
}
int main()
{
	char expression[MAX];
	int validity;
	printf("\nEnter an Algebraic Expression : ");
	scanf("%s", expression);
	validity = check_paranthesis(expression);
	if(validity == 1)
	{
		printf("\nThe Expression is Valid");
	}
	else
	{
		printf("\nThe Expression is Invalid\n");
	}
	return 0;
}


