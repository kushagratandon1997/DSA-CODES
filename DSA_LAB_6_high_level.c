#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int priority[20],p=-1,cat_of_vip;
char que[20][20],name_of_vip[20];
int size=20,rear=-1,front=0;
void arranging_riders();
void push(int i,char name[])
{
    int j;
	rear++;
    for(j=0;j<i;j++)
    que[rear][j]=name[j];
    que[rear][i]='\0';
}
int main()
{
    char g,i[1]={'\0'},catagory;
    int a,age[20],q=-1,family_member,adult=0,child=0;
    do{
    printf("Specify, The Rider is with Family or is Alone : ");
    printf("\n 1. Press F for Family \n 2. Press A for Alone \n");
    scanf("\n%c",&g);
    if(g=='A')
     {
        char sn[20];
        printf("Enter the catagory to which Rider belong : ");
        printf("\n 1. Press N for Normal Rider \n 2. Press V for V.I.P Rider \n ");
        scanf("\n%c",&catagory);
        if(catagory=='N')
{
        priority[++p]=0;
        printf("Enter Rider's name :");
        scanf("%s",sn);
        sn[strlen(sn)]='\0';
        push(strlen(sn),sn);
        printf("Your Rider's Age : ");
        scanf("%d",&age[++q]);
        if(age[q]>=18)
            adult++;
        else
            child++;}
        else if(catagory=='V')
        {
            printf("\nEnter the catagory of V.I.P : ");
            printf("\n 1.Press 1 for Low priority V.I.P \n 2.Press 2 for Moderate priority V.I.P \n 3.Press 3 for High priority V.I.P \n ");
            scanf("%d",&cat_of_vip);
            priority[++p]=cat_of_vip;
            printf("Enter Rider's name :");
            scanf("%s",sn);
            sn[strlen(sn)]='\0';
            push(strlen(sn),sn);
            printf("Enter Rider's age : ");
            scanf("%d",&age[++q]);
            if(age[q]>=18)
            adult++;
        else
            child++;}
        }

    else
    {
        char v,family_name[20];
        printf("Enter the number of Family members : ");
        scanf("%d",&family_member);
        printf("Enter the catagory of Rider's  family : ");
        printf("\n 1. Press N for Normal Rider \n 2. Press V for V.I.P Rider \n ");
        scanf("\n%c",&v);
        if(v=='N')
		{
        printf("Enter name and age of family members :\n");
        for(a=0;a<family_member;a++)
        {
            if(q<20){
            priority[++p]=0;
            printf("Enter Rider's name : ");
            scanf("%s",family_name);
            push(strlen(family_name),family_name);
            printf("Enter Rider's age : ");
            scanf("%d",&age[++q]);
            if(age[q]>=18)
                adult++;
            else
                child++;
            }
            else
                printf("\n Sorry, Queue is full !");

        }
    }
	else if(v=='V')
{
        printf("Enter the catagory of V.I.P : ");
        printf("\n 1.Press 1 for Low priority V.I.P \n 2.Press 2 for Moderate priority V.I.P \n 3.Press 3 for High priority V.I.P \n ");
        scanf("%d",&cat_of_vip);
        printf("Enter name and age of Family members :\n");
        for(a=0;a<family_member;a++)
        {
            if(q<20)
			{
            priority[++p]=cat_of_vip;
            printf("Enter Rider's name : ");
            scanf("%s",family_name);
            push(strlen(family_name),family_name);
            printf("Enter Rider's age : ");
            scanf("%d",&age[++q]);
            if(age[q]>=18)
                adult++;
            else
                child++;
            }
            else
                printf("Sorry, Queue is full ! ");

        }
    }
    }
    arranging_riders();
    for(a=0;a<q+1;a++)
    printf("%d. rider is :  %s\n",a+1,que[a]);
    printf("Number of adults are:%d\n",adult);
    printf("Number of children are:%d\n",child);
    if(q<20)
    {
        printf("Do you want to add more people(y/n) : ");
        scanf("%s",i);
    }
    
if(q==20)
        printf("\nSorry, Queue is full !\n");
    }
	while(i[0]=='y');
	return 0;
}
void arranging_riders()
{
    int m,n,t,temp;
    for(m=0;m<p;m++)
        for(n=m+1;n<p+1;n++)
    {
        if(priority[m]<priority[n])
		{
            temp=priority[m];
            priority[m]=priority[n];
            priority[n]=temp;
            for(t=0;t<strlen(que[m]);t++)
            name_of_vip[t]=que[m][t];
            name_of_vip[t]='\0';
            for(t=0;t<strlen(que[n]);t++)
            que[m][t]=que[n][t];
            que[m][t]='\0';
            for(t=0;t<strlen(name_of_vip);t++)
            que[n][t]=name_of_vip[t];
            que[n][t]='\0';
        }
    }
}

