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
struct node *start=NULL;
struct node *last=NULL;

void create();
void insert_at_beg();
void insert_at_end();
void insert_at_mid();
void delete_record();
void search_record();
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
		printf("3. Insert At Middle \n");
		printf("4. Deletion and Display \n");
		printf("5. Search and Display \n");
		printf("6. Display \n");
		printf("7. Exit \n\n");
		printf("Enter the choice : ");
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
				search_record();
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
	if (start == NULL)
    {
        create();
        start = temp;
        last = start;
    }
	else 
	{
		create();
		start->prev=temp;
		temp->next=start;
		start=temp;
	}
}
void insert_at_end()
{
	if(start==NULL)
	{
		create();
		start = temp;
        last = start;
	}
	else
	{
		create();
		last->next=temp;
		temp->prev=last;
		last=temp;
	}
}
void insert_at_mid()
{
    int pos, i = 2;
	printf("\n Enter the position at which new node has  to be inserted : ");
    scanf("%d", &pos);
    temp2 = start;
 
    if ((pos < 1) || (pos >= count + 1))
    {
        printf("\n Sorrry ! Position is out of range for new node to be inserted \n");
        return;
    }
    else if ((start == NULL) && (pos != 1))
    {
        printf("\n The list is empty so insertion will happen at 1st position \n");
        return;
    }
    else if ((start == NULL) && (pos == 1))
    {
        create();
        start = temp;
        last = start;
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
	printf("\nEnter the roll number which has to be deleted : ");
	scanf("%d",&num);
	if(start==NULL)
	{
		printf("List is Empty \n");
	}
	else if(count==1 && start->roll==num)
	{
		temp3=start;
		start=NULL;
		free(temp3);
		count--;
		printf("List is Empty \n");
	}
	else if(count==1 && start->roll!=num)
	{
		printf("Not Found \n");
	}
	else if(start->roll==num && count!=1)
	{
		temp3=start;
		start=start->next;
		start->prev=NULL;
		free(temp3);
		count--;
		if(start->next==NULL)
		{
			printf("Nothing to Display \n");
		}
		else
		{
			printf("The name of Successor is  -> %s \n",start->next->name);
			printf("The Roll number of Successor is  -> %d \n",start->next->roll);
		}
		printf("\nSorry ! Their is no predecessor \n");
	}
	else 
	{
		temp3=start->next;
		prec=start;
		while(temp3!=NULL)
		{
			if(temp3->next==NULL && temp3->roll!=num)
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
			if(temp3->next==NULL)
			{
				prec->next=NULL;
				free(temp3);
				count--;
				printf("\n The Current Name is -> %s ",prec->name);
				printf("\n The Current Roll Number is -> %d ",prec->roll);
				if(prec->prev==NULL)
				{
					printf("Nothing to DISPLAY \n");
				}
				else
				{
					printf("\nThe name of the predecessor is -> %s and %d \n",prec->prev->name);
					printf("\nThe Roll number of the predecessor is -> %d \n",prec->prev->roll);
				}
				printf("\nSorry ! Their is no successor \n");
			}
			else
			{
				prec->next=temp3->next;
				temp3->next->prev=temp3->prev;
				free(temp3);
				count--;
				printf("\nThe Current Name is -> %s",prec->name);
				printf("\nThe Current Roll Number is -> %d \n",prec->roll);
				if(prec->prev==NULL)
				{
					printf("Nothing to Display \n");
				}
				else
				{
					printf("\nThe Predecessor Name is -> %s",prec->prev->name);	
					printf("\nThe Predecessor Roll Number is -> %d ",prec->prev->roll);
				}
				printf("\nSorry ! Their is no successor \n");
				if(prec->next==NULL)
				{
					printf("Nothing to Display as Successor \n");
				}
				else
				{
					printf("\nThe Successor Name is -> %s ",prec->next->name);
					printf("\nThe Successor Roll Number is -> %d ",prec->next->roll);
				}
			}
	}
}
void search_record()
{
	int n;
	printf("\nEnter the roll number which has to search : ");
	scanf("%d",&n);
	if(start==NULL)
	{
		printf("List is Empty \n");
	}
	else if(count==1 && start->roll==n)
	{
		printf("\nPredecessor and Successor are not allowed as only one element is there in the list \n");
	}
	else if(count==1 && start->roll!=n)
	{
		printf("Not Found \n");
	}
	else if(start->roll==n && count!=1)
	{
		printf("\nPredecessor is not allowed \n");
		printf("\nThe Successor Name is -> %s",start->next->name);
		printf("\nThe Successor Roll number is -> %d",start->next->roll);
	}
	else 
	{
		temp3=start->next;
		while(temp3!=NULL)
		{
			if(temp3->next==NULL && temp3->roll!=n)
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
				prec=temp3;
				temp3=temp3->next;
			}
		}
		flag:
			if(temp3->next==NULL)
			{
				printf("\nThe Current Name is  -> %s",temp3->name);
				printf("\nThe Current Roll Number is ->  %d",temp3->roll);
				printf("\nThe Predecessor Name is -> %s",temp3->prev->name);
				printf("\nThe Predecessor Roll Number is -> %d",temp3->prev->roll);
				printf("\nSorry ! Their is no successor \n");
			}
			else
			{
				printf("\nThe Current Name is  -> %s",temp3->name);
				printf("\nThe Current Roll Number is ->  %d",temp3->roll);
				printf("\nThe Predecessor Name is -> %s",temp3->prev->name);
				printf("\nThe Predecessor Roll Number is -> %d",temp3->prev->roll);
				printf("\nThe Successor Name is  -> %s",temp3->next->name);
				printf("\nThe Successor Roll Number is  -> %d ",temp3->next->roll);
			}
	}
}
void display()
{
	struct node *temp5;
	if(start==NULL)
		printf("List is Empty \n");
	else
	{
		printf("\nName               Roll Number");
		temp5=start;
		while(temp5!=NULL)
		{
			printf("\n  %s              %d",temp5->name,temp5->roll);
			temp5=temp5->next;
		}
	}
}

