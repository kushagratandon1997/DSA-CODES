#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int top=-1;
int r,i,j,k;/*r=Registration no. of student*/
struct str
{
    char s[50];
}a[100];

int push();/*defining prototype of function before main function*/
int pop();
int display();

int main()
{
	printf("Enter the number of students who submitted the assignments : ");
	scanf("%d",&r);
	int i;
	printf("\nEnter the Registration No. in the order in which assignments are submitted ");
	for(i=0;i<r;i++)
	{
		push();
		for(j=0;j<i;j++)/*used to check the last entry in stack for below mentioned condition*/
		{
			while(strcmp(a[i].s,a[j].s)==0)/*to check that the last entry of stack is similar or not to entry just previous to last entry*/
			{
			printf("\nYou have just entered duplicate Registration no. !");/*strcmp = comparision of two strings*/
			printf("\n Please enter new Registration no. : ");
			scanf("%s",a[i].s);	
		    }
		}
	}
	for(i=0;i<r-10;i++)/*poping out rest entry from stack except first 10 using for loop*/
	{
		pop();
	}
	display();
}

int push()
{
	{
	if(top==r-1)
		{
			printf("\nStack is full");
		}
	else
		{
			printf("\nEnter the Registration No. : ");
			scanf("%s",a[++top].s);
		}
    }     
}
int pop()
{
	if(top==-1)
		{
			printf("\nStack is empty");
		}
		else
		{
			top--;/*used to pop out entry one by one*/
		}
}
int display()
{
	if(r>=10)
	{
	printf("\nRegistration No. of 10 students who submitted the assignment first are : \n");
	for(i=top;i>=0;i--)/*displays the reg. no. from top to bottom just like entry in stack*/
	{
		printf("%s\n",a[i].s);
	}
    }
    else
    {
    	printf("Enter atleast 10 registration numbers !");
	}
}

