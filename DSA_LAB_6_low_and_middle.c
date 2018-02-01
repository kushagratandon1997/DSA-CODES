#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char queue_of_riders[20][20];
int size=20,rear=-1,front=0;
int i,j;
void push(int i,char name[]);
int main()
{
    char catagory,i[1]={'\0'};
    int a,age[20],q=-1,family_member,adult=0,child=0;
    do
	{
    printf("\nSpecify, Rider is with Family or is Alone :"); 
	printf("\n 1. Press F for Family \n 2. Press A for Alone \n");  
    scanf("\n%c",&catagory);
    if(catagory=='A')
    {
        char Rider_name[20];
        printf("Enter Rider's name :");
        scanf("%s",Rider_name);
        Rider_name[strlen(Rider_name)]='\0';
        push(strlen(Rider_name),Rider_name);
        printf("Enter Rider's age :");
        scanf("%d",&age[++q]);
        if(age[q]>=18)
        adult++;
        else
        child++;
    }
    else
    {
        char family_names[20];
        printf("Enter the number of Members in the Rider's Family : ");
        scanf("%d",&family_member);
        printf("Enter name and age of family members :\n");
        for(a=0;a<family_member;a++)
        {
            if(q<20)
	{
            printf("Enter name:");
            scanf("%s",family_names);
            push(strlen(family_names),family_names);
            printf("Enter age:");
            scanf("%d",&age[++q]);
            if(age[q]>=18)
            adult++;
            else
            child++;
            }
            else
            printf("\nSorry, Queue is full !\n");
	}
    }
    for(a=0;a<q+1;a++)
    printf("%d rider is :  %s\n",a+1,queue_of_riders[a]);
    printf("Number of adults in the queue are : %d\n",adult);
    printf("Number of children in the queue are : %d\n",child);
    if(q<20)
    {
        printf("You want to enter more people(y/n):");
        scanf("%s",i);
    }
    if(q==20)
    {
    	printf("Sorry Queue is full !");
    }
    }
   while(i[0]=='y');
    return 0;
}
void push(int i,char name[])
{
    rear++;
    for(j=0;j<i;j++)
    queue_of_riders[rear][j]=name[j];
    queue_of_riders[rear][i]='\0';
}



