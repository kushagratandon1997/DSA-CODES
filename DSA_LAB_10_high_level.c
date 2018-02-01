#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<ctype.h>

static int count;
struct node
{
	int roll;
	char name[20];
	struct node *prev;
	struct node *next;
}*temp,*temp2,*temp3,*temp4,*prec;
struct node *last=NULL;

void create();
void insert_at_beg();
void insert_at_end();
void insert_at_mid();
void delete_record();
void search_records();
void display();

int main()
{
	int i;
	int n=1;
	printf("\n                       Welcome !                     \n\n");
	while(n!=7)
	{
		printf("\n\n1. Insert At Beginning \n");
		printf("2. Insert At End \n");
		printf("3. Insert At Mid \n");
		printf("4. Deletion and Display \n");
		printf("5. Search and Display \n");
		printf("6. Display \n");
		printf("7. Exit \n");
		printf("\nEnter the choice : ");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				insert_at_beg();
				break;
			case 2:
				insert_at_end();
				break;
			case 3:
				insert_at_mid();
				break;
			case 4:
				delete_record();
				break;
			case 5:
				search_records();
				break;
			case 6:
				display();
				break;
		}
	}
	return 0;
}
void create()
{
	char nam[20];
	int rol;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->next=NULL;
	temp->prev=NULL;
	printf("\nEnter the name of the student : ");
	scanf("%s",nam);
	printf("\nEnter the roll number of the student : ");
	scanf("%d",&rol);
	strcpy(temp->name,nam);
	temp->roll=rol;
	count++;
}
void insert_at_beg()
{
	if (last == NULL)
    {
        create();
        last=temp;
        temp->next=last;
        temp->prev=last;
    }
	else 
	{
		create();
		temp->next=last->next;
		last->next=temp;
		temp->prev=last;
	}
}
void insert_at_end()
{
	if(last==NULL)
	{
		create();
		last=temp;
        temp->next=last;
        temp->prev=last;
	}
	else
	{
		create();
		temp->next=last->next;
		last->next=temp;
		temp->prev=last;
		last=temp;
	}
}
void insert_at_mid()
{
    int pos, i = 2;
	printf("\n Enter position to be inserted : ");
    scanf("%d", &pos);
    temp2 = last->next;
 
    if ((pos < 1) || (pos >= count + 1))
    {
        printf("\n Sorrry ! Position is out of range for new node to be inserted \n");
        return;
    }
    else if ((last == NULL) && (pos != 1))
    {
        printf("\n The list is empty so insertion will happen at 1st position \n");
        return;
    }
    else if ((last == NULL) && (pos == 1))
    {
        create();
        last=temp;
        temp->next=last;
        temp->prev=last;
        return;
    }
    else
    {
        while (i < pos)
        {
            temp2 = temp2->next;
            i++;
        }
        create();
        temp->prev = temp2;
        temp->next = temp2->next;
        temp2->next->prev = temp;
        temp2->next = temp;
    }
}
void delete_record()
{
	int num;
	printf("\nEnter the roll number which has to be delete : ");
	scanf("%d",&num);
	if(last==NULL)
	{
		printf("List is Empty \n");
	}
	else if(count==1 && last->roll==num)
	{
		temp3=last;
		last=NULL;
		free(temp3);
		count--;
		printf("List is Empty \n");
	}
	else if(count==1 && last->roll!=num)
	{
		printf("Not Found \n");
	}
	else if(last->next->roll==num && count!=1)
	{
		temp3=last->next;
		last->next=temp3->next;
		temp3->next->prev=last;
		free(temp3);
		count--;
		if(count==1)
		{
			printf("\nNothing to Display as Predecessor and Successor !\n");
		}
		else if(count==2)
		{
			printf("\nThe Predecessor and Successor are same and they are -> %s and %d \n",last->name,last->roll);
		}
		else
		{
			printf("\nThe Name of Successor is -> %s",last->next->next->name);
			printf("\nThe Roll number of Successor is -> %d",last->next->next->roll);
			printf("\nThe Name of Predecessor is -> %s \n",last->name);
			printf("\nThe ROll number of Predecessor is -> %s",last->roll);
		}
	}
	else 
	{
		temp3=last->next->next;
		prec=last->next;
		while(temp3!=last->next)
		{
			if(temp3->next==last->next && temp3->roll!=num)
			{
				printf("Not Found \n");
				return;
			}
			else if(temp3->roll==num)
			{
				goto flag;
			}
			else
			{
				prec=temp3;
				temp3=temp3->next;
			}
		}
		flag:
			if(temp3->next==last->next)
			{
				last->next->prev=prec;
				prec->next=last->next;
				last=prec;
				free(temp3);
				count--;
				printf("\nThe Current Name is -> %s",prec->name);
				printf("\nThe Current Roll Number is -> %d \n",prec->roll);
				if(count==1)
				{
					printf("\n Nothing to Display as Predecessor and Successor !\n");
				}
				else if(count==2)
				{
					printf("Previous and Successor Name and Roll Number are same and are  %s and %d \n",last->name,last->roll);
				}
				else
				{
				printf("\nThe Current Name is -> %s",prec->name);
				printf("\nThe Current Roll Number is -> %d",prec->roll);
				printf("\nThe Predecessor Name is -> %s",prec->prev->name);
				printf("\nThe Predecessor Name  is -> %d",prec->prev->roll);
				printf("\nThe Successor Name is -> %s",prec->next->name);
				printf("\nThe Successor Roll Number is -> %d",prec->next->roll);
				}
			}
			else
			{
				prec->next=temp3->next;
				temp3->next->prev=temp3->prev;
				free(temp3);
				count--;
				printf("\nThe Current Name is -> %s",prec->name);
				printf("\nThe Current Roll Number is -> %d",prec->roll);
				printf("\nThe Predecessor Name is -> %s",prec->prev->name);
				printf("\nThe Predecessor Name  is -> %d",prec->prev->roll);
				printf("\nThe Successor Name is -> %s",prec->next->name);
				printf("\nThe Successor Roll Number is -> %d",prec->next->roll);
				
			}
	}
}
void search_records()
{
	int n;
	printf("\nEnter the roll number which has to search : ");
	scanf("%d",&n);
	if(last==NULL)
	{
		printf("List is Empty \n");
	}
	else if(count==1 && last->roll==n)
	{
		printf("Previous and Successor are not allowed as only one element is there in the list \n");
	}
	else if(count==1 && last->roll!=n)
	{
		printf("Not Found \n");
	}
	else if(last->next->roll==n && count!=1)
	{
		printf("\nThe Predecessor Name is -> %s",last->name);
		printf("\nThe Predecessor Roll number -> %d",last->roll);
		printf("\nThe Successor Name is -> %s",last->next->next->name);
		printf("\nThe Successor Roll number is -> %d  :\n",last->next->next->roll);
	}
	else 
	{
		temp3=last->next->next;
		while(temp3!=last->next)
		{
			if(temp3->next==last->next && temp3->roll!=n)
			{
				printf("Not Found \n");
				return;
			}
			else if(temp3->roll==n)
			{
				goto flag;
			}
			else
			{
				temp3=temp3->next;
			}
		}
		flag:
			if(temp3->next==last->next)
			{
				printf("\nThe Current Name is -> %s",temp3->name);
				printf("\nThe Current Roll Number is -> %d",temp3->roll);
				printf("\nThe Predecessor Name is -> %s",temp3->prev->name);
				printf("\nThe Predecessor Roll Number is -> %d",temp3->prev->roll);
				printf("\nThe Successor Name is -> %s",temp3->next->name);
				printf("\nThe Successor Roll Number is -> %d",temp3->next->roll);
			}
			else
			{
				printf("\nThe Current Name is -> %s",temp3->name);
				printf("\nThe Current Roll Number is -> %d",temp3->roll);
				printf("\nThe Predecessor Name is -> %s",temp3->prev->name);
				printf("\nThe Predecessor Roll Number is -> %d",temp3->prev->roll);
				printf("\nThe Successor Name is -> %s",temp3->next->name);
				printf("\nThe Successor Roll Number is -> %d",temp3->next->roll);
			}
	}
}
void display()
{
	struct node *temp5;
	if(last==NULL)
		printf("List is Empty \n");
	else
	{
		printf("\nName                Roll Number");
		temp5=last->next;
		while(temp5!=last)
		{
			printf("\n  %s              %d",temp5->name,temp5->roll);
			temp5=temp5->next;
		}
		printf("\n  %s              %d",last->name,last->roll);
	}
}
