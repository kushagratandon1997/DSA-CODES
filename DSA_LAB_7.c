#include<stdio.h>
#include<stdlib.h>
int front=-1,rear=-1;
int Queue[50],max=50;
int Queue_empty();
int Queue_full();
void enQueue();
void deQueue();
void display_old_data();
void display_new_data();
void front_and_rear();
int main()
{
    int i;
    char j;
    printf("Welcome,Enter the choice for DVD operations \n\n");
    do
	{
        printf("1. Enter new data to the Buffer\n2. Burn data from Buffer\n3. Display the front and rear indices\n4. Display the old unburnt data in the Buffer\n5.Display the newly instered data\n");
        scanf("%d",&i);
        if(i==1)
        enQueue();
        else if(i==2)
        deQueue();
        else if(i==3)
        front_and_rear();
        else if(i==4)
        display_old_data();
        else
        display_new_data();
        printf("\nDo you want to continue ?(y/n) : ");
        scanf("%s",&j);
        printf("\n");
    }
    while(j=='y');
    return 0;
}
int Queue_empty()
{
    if(rear==front)
    return 1;
    return 0;
}

int Queue_full()
{
    if((front==rear+1)||(front==0&&rear==max-1))
    return 1;
    return 0;
}
void enQueue()
{
    int d;
    if(Queue_full()==1)
    printf("Buffer is full\n");
    else
    {
        printf("\nEnter new data in Buffer : ");
        scanf("%d",&d);
        if(front==-1)
        {
            front=0;
            rear=0;
        }
        else
        rear=(rear+1)%max;
        Queue[rear]=d;
    }
}
void deQueue()
{
    int a;
    if(Queue_empty()==1)
    {
        printf("Buffer is empty\n");
    }
    else
    {
        a=Queue[front];
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        front=(front+1)%max;
        printf("\nBurned data from Buffer is : %d",a);
    }
}
void display_old_data()
{
    int old;       /*old = old data*/
    for(old=front;old!=rear;old=(old+1)%max)
    printf("\nThe old unburnt data is : %d\n",Queue[old]);
}
void display_new_data()
{
    printf("\nThe newly inserted data is : %d\n",Queue[rear]);
}
void front_and_rear()
{
    printf("\nFront index is : %d",front);
    printf("\nRear index is : %d",rear);
}

