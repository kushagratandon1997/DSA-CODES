#include<stdio.h>
#include<stdlib.h>
int truck_on_road[100],r=-1;                            /*array for trucks on road*/
int truck_in_garage[100],days_of_stay[100];      /* circular queue 1 for truck in garage and circular queue 2 for days of stay of truck in garage*/
int front=0,rear=-1,truck,c;
int charge();
int garage_empty();
void entry_on_road();
int entry_in_garage();
void exiting_road();
void exiting_garage();
void display_road_truck();
void display_garage_truck();
int main()
{
    int menu,choice,i;
    char j;
    printf(" \nWelcome, to Truck Operations using Circular Queue Implementation \n\n ");
    printf("\nEnter the charge for stay of truck in the garage : ");
    scanf("%d",&c);
    do
	{
        printf("\nEnter the choice:\n");
        printf("1. Enter the truck on road\n2. Enter the truck in the garage\n3. Exit the truck from garage\n4. Show trucks on garage/road\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            {
                entry_on_road();
                break;
            }
        case 2:
            {
                i=entry_in_garage();
                if(i==1)
                exiting_road();
                break;
            }
        case 3:
            {
                exiting_garage();
                break;
            }
        default:
            {
                printf("Enter the choice:\n");
				printf("\n1. The trucks in garage \n2. The trucks on road\n");
                scanf("%d",&menu);
                if(menu==1)
                display_garage_truck();
                else if(menu==2)
                display_road_truck();
                break;
            }
        }
        printf("Do you want to continue ? (y/n) : ");
        scanf("%s",&j);
        printf("\n");
    }
    while(j=='y');
    return 0;
}
int charge(int d)
{
    return d*c;
}
int garage_empty()
{
    if(rear<front)
    return 1;
    else
    return 0;
}
void entry_on_road()
{
    int id;
    printf("\nEnter the truck id for entry on road : ");
    scanf("%d",&id);
    r++;
    truck_on_road[r]=id;
}
int entry_in_garage()
{
    int id,t,j,days,temp1,temp2,count=0;
    if(r==-1)
    printf("\n Sorry, The road is empty ");
    else
    {
        printf("\nEnter the trucks id which has to move from road to garage :  ");
        scanf("%d",&id);
        for(t=0;t<=r;t++)
        if(truck_on_road[t]==id)
        {
        count++;
        }
        if(count==0)
		{
            printf("\nTruck id -> %d is not present on the road\n",id);
            return 0;
        }
        else
        {
            printf("\nEnter the number of days the truck is going to stay in garage : ");
            scanf("%d",&days);
            for(t=0;t<=r;t++)
			{
                if(truck_on_road[t]==id)
				{
                    truck=t;
                    rear++;
                    truck_in_garage[rear]=id;
                    days_of_stay[rear]=days;
                    break;
                }
            }
            for(t=front;t<rear;t++)  /*swapping of trucks in garage according to days of stay in ascending order*/ 
            {
                for(j=t+1;t<=rear;j++)
				{
                    if(days_of_stay[j]<days_of_stay[t])
					{
                        temp1=days_of_stay[j];
                        temp2=truck_in_garage[j];
                        days_of_stay[j]=days_of_stay[t];
                        truck_in_garage[j]=truck_in_garage[t];
                        days_of_stay[t]=temp1;
                        truck_in_garage[t]=temp2;
                    }
                }
            }
            return 1;
        }
    }
}
void exiting_road()
{
    int t;
    printf("\nTruck id -> %d is moving in the garage from road \n",truck_on_road[truck]);
    for(t=truck+1;t<=r;t++)
    truck_on_road[t-1]=truck_on_road[t];  /* here the swapping takes place in the array of trucks on road one place forward after one truck moves into the garage*/
    r--;
}

void exiting_garage()
{
    int id,pay,i,count=0;
    if(garage_empty()==1)
    printf("\n Garage is empty !\n ");
    else
    {
        printf("\nEnter the truck id which wants to exit from garage : ");
        scanf("%d",&id);
        for(i=front;i<=rear;i++)
		{
        if(truck_in_garage[i]==id)
        count++;
        }
        if(count==0)
        printf("\nSorry, Truck id -> %d is not present in the garage\n",id);
        else
        {
            if(truck_in_garage[front]==id)
			{
                pay=charge(days_of_stay[front]);
                printf("\nThe charge for stay of truck id -> %d is Rs. %d\n",id,pay);
                printf("\nTruck id -> %d has successfully moved out of the garage\n",id);
                front++;
            }
            else
            printf("\nTruck id -> %d cannot be moved out of the garage \n",id);
        }
    }
}
void display_road_truck()
{
    int t;
    for(t=0;t<=r;t++)
    printf("\nTrucks present on the road are : %d\n",truck_on_road[t]);
}
void display_garage_truck()
{
    int t;
    for(t=front;t<=rear;t++)
    printf("\nTrucks present in the garage are : %d\n",truck_in_garage[t]);
}
