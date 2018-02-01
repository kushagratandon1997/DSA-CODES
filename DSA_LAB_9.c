#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	struct node *link;
	char n[50];                        /* array defined for name*/
	int marks,regis_no;            /* m for marks of each student and regis_no is registration number of each student*/
};

struct node *h1='\0';
struct node *h2='\0';
struct node *h3='\0';
struct node *tail1='\0';
struct node *tail2='\0';

void enter_details();
void display_lists();
void rearrange_ele();
void merge_sort();

int main()
{
	char choice,menu;
	printf("\nWelcome to the merge sorting operation of two given lists \n ");
	printf("\nList of students who wrote SET- A question paper ( list - 1 ) \n");
	do
	{
		enter_details(&h1);
        printf("\nDo you want to continue?(y/n) : ");
        scanf("%s",&choice);
    }
    while(choice=='y');
    display_lists(h1);
    tail2=tail1;
    printf("\nList of students who wrote SET- B question paper ( list - 2 ) \n");
    do
	{
        enter_details(&h2);
        printf("\nDo you want to continue?(y/n) : ");
        scanf("%s",&menu);
    }
    while(menu=='y');
    display_lists(h2);
    printf("\n");
    tail2->link=h2;
    h2='\0';
    h3=h1;
    printf("\nThe merged list of two list (List -> 1, List -> 2) :  \n");
    display_lists(h3);
    merge_sort(&h3);
    printf("\nThe sorted merged list of two list (List -> 1, List -> 2) :  \n");
    display_lists(h3);
    return 0;
}
void enter_details(struct node **k)
{
    int reg,s;
    char student[10];
    printf("\nEnter the register number of the student :  ");
    scanf("%d",&reg);
    printf("\nEnter the name of the student : ");
    scanf("%s",student);
    printf("\nEnter the score of the quiz gained by student : ");
    scanf("%d",&s);
	struct node* nnode=(struct node*)malloc(sizeof(struct node));
	nnode->regis_no=reg;
	strcpy(nnode->n,student);
    nnode->marks=s;
	nnode->link='\0';
	if(*k=='\0')
    {
        *k=nnode;
    }
    else
    {
        struct node *j = *k;
        while(j->link!='\0')
        {
            j=j->link;
        }
        j->link=nnode;
        tail1=nnode;
    }
}
void display_lists(struct node *k)
{
    int d=0;
    printf("\nRegist.No        Name                     Score \n");
	struct node *j=k;
	while(j->link!='\0')
	{
		printf("   %d               %s                    %d\n",j->regis_no,j->n,j->marks);
		j=j->link;
		d++;
	}
	printf("   %d               %s                    %d\n",j->regis_no,j->n,j->marks);
	d++;
}

void rearrange_ele(struct node *x,struct node *y)
{
    int t1,t2;
    char temp[50];
    
	t1=x->marks;
    x->marks=y->marks;
    y->marks=t1;
    
    t2=x->regis_no;
    x->regis_no=y->regis_no;
    y->regis_no=t2;
    
    strcpy(temp,x->n);
    strcpy(x->n,y->n);
    strcpy(y->n,temp);
}

void merge_sort(struct node **k)
{
    int swap;
    struct node *x;
    struct node *y='\0';
    do
    {
        swap=0;
        x=*k;
        while (x->link!=y)
        {
            if ((x->marks) > (x->link->marks))
            {
                rearrange_ele(x, x->link);
                swap=1;
            }
            x=x->link;
        }
        y=x;
    }
    while(swap);
}

