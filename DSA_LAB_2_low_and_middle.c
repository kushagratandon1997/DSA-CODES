#include <stdio.h>
#include<string.h>
#include<ctype.h>
#define max 100
int topf=-1;
int topb=-1;
char f[100][100];
char b[100][100];
char k[100];
int isemptyf()
{
	if (topf==-1)
    return 1;
    else
    return 0;
}
int isemptyb()
{
	if (topb==-1)
    return 1;
    else
    return 0;
}

int isfullf()
{
	if (topf==max-1)
	return 1;
	else
	return 0;
}
int isfullb()
{
	if (topb==max-1)
	return 1;
	else
	return 0;
}

void pushf(char c[100])
{
	if(isfullf())
	printf("No space in Forward");
	else
	{ 
		topf++ ;
		strcpy(f[topf],c);
	}
}	
void pushb(char d[100])
{
	if(isfullb())
	printf("no space in back");
	else
	{ 
		topb++ ;
		strcpy(b[topb],d);
	}
}	

void popf()
{
	if(isemptyf())
		printf("Forwad stack is empty\n");
	else
		printf("%s\n",f[topf]);
		topf--;
}
void popb()
{
	if(isemptyb())
		printf("Back stack is empty\n");
	else
		printf("%s\n",b[topb]);
		topb--;
}
void displayf()
{   int i;
	if(isemptyf())
		printf("Forward Stack is empty");
	else
	{
		printf("Forward Brose elements are: \n");
		for(i=0;i<=topf;i++)
		{ 
			printf("%s\n",f[i]);
		}
	}
}

void displayb()
{	
	int i;
	if(isemptyb())
		printf("Back Stack is empty");
	else
	{
		printf("Backward Brose elements are: \n");
		for(i=0;i<=topb;i++)
		{
		 	printf("%s\n",b[i]);
		}
	}
}
void back(char nl[100])
{
	pushf(nl);              /*Push the present entry to the forward stack */
	strcpy(nl,b[topb]);    /*Copy topmost entry of back stack to present page i.e. nl*/									
	popb();               /*Delete the topmost entry of the back stack that is being copied to nl*/
}
int main()
{
	int i;
	char nl[100],b[100],p[100];
	printf("Enter the first entry : ");
	gets(nl);
	int n=1;
	while(n!=5)
	{
		printf("1. New Entry\n");
		printf("2. Backward Browsing\n");
		printf("3. Forward Browsing\n");
		printf("4. Display\n");
		printf("5. Exit\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
			    pushb(nl);
			    gets(k);
			    fgets(k,100, stdin);
			    strcpy(nl,k);
                break;
			case 2:
				if(topb==-1)
				{
					printf("No Web page is present in back stack\n");
				}
				else
				{
					back(nl);
				}
                break;
			case 3: 
			if(topf==-1)
				{
					printf("No Web page is present in forward stack\n");
				}
				else
			    {
					pushb(nl);
			    	strcpy(nl,f[topf]);
			    	popf();
            	}
				break;
			case 4:
			    displayb(); 
			    displayf();
            	break;    
			case 5 :  
                break;
		}
	}
	return(0);
}

