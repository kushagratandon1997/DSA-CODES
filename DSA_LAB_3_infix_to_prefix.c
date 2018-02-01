#include<stdio.h>
#define SIZE 100            /* Size of Stack */
#include<string.h>
#include <ctype.h>
char s[SIZE];
int top=-1;       /* Global declarations */
 
push(char elem)
{                       /* Function for PUSH operation */
    s[++top]=elem;
}
 
char pop()
{                      /* Function for POP operation */
    return(s[top--]);
}
 
int pr(char elem)
{                 /* Function for precedence */
    switch(elem)
    {
    case '#': 
	return 0;
    case ')': 
	return 1;
    case '^':
    return 2;
    case '*':
    case '/': 
	return 3;
    case '+':
    case '-': 
	return 4;
    }
}
 
int main()
{                         
    char infx[50],prfx[50],ch,elem;
    int i=0,k=0;
    printf("Enter the Athematic Expression  : ");
    scanf("%s",infx);
    push('#');/*for null*/
    strrev(infx);
    while( (ch=infx[i++]) != '\0')
    {
        if( ch == ')') 
		push(ch);
        else if(isalnum(ch)) prfx[k++]=ch;
            else if( ch == '(' )
                {
                    while( s[top] != ')' )
                        prfx[k++]=pop();
                    elem=pop(); /* Remove ) */
                }
                else
                {       /* Operator */
                    while( pr(s[top]) >= pr(ch) )
                        prfx[k++]=pop();
                    push(ch);
                }
    }
    while( s[top] != '#')     /* Pop from stack till empty */
        prfx[k++]=pop();
    prfx[k]='\0';          /* Make prfix as valid string */
    strrev(prfx);
    strrev(infx);
    printf("\nPolish Notation is : %s",prfx);
    return 0;
}

