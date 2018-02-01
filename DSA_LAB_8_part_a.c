#include<stdio.h>
#include<stdlib.h>

int truck_on_road[100],r=-1; /*array defined for no. of trucks on road*/
int truck_in_garage[100],days_of_stay[100]; /* stack 1 for trucks in garage and stack 2 for no. of days of stay for trucks in garage*/
int garage_top=-1,truck,c;
int charge();
void entry_on_road();
int entry_in_garage();
void exiting_road();
void exiting_garage();
void display_garage_truck();
void display_road_truck();

int main()
{
    int menu,choice,i;
    char j;
    printf(" \nWelcome, to Truck Operations using Stack Implementation \n\n ");
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
    int id,j,count=0,days;
    if(r==-1)
        printf("\n Sorry, The road is empty ");
    else
    {
        printf("\nEnter the trucks id which has to move from road to garage :  ");
        scanf("%d",&id);
        printf("\nEnter the number of days the truck is going to stay in garage : ");
        scanf("%d",&days);
        for(j=0;j<=r;j++)
        {
            if(truck_on_road[j]==id)
            {
                truck=j;                   /*in this part entry of truck in garage takes place and latest entry is at top of the stack*/
                count++;
                garage_top++;
                truck_in_garage[garage_top]=id; 
                days_of_stay[garage_top]=days;  /* simutaneously the no. of days which the truck is going to stay in garage is placed at same position in another stack*/
                return 1;
                break;
            }
        }
        if(count==0)
        {
            printf("\nTruck id -> %d is not present on the road\n",id);
            return 0;
        }
    }
}
void exiting_road()
{
    int t;
    printf("\nTruck id -> %d is moving in the garage from road \n",truck_on_road[truck]);
    for(t=truck+1;t<=r;t++)
    {
        truck_on_road[t-1]=truck_on_road[t];  /* here the swapping takes place in the array of trucks on road one place forward after one truck moves into the garage*/
    }
    r--;
}
void exiting_garage()
{
    int id,pay,t,count=0;
    if(garage_top>-1)
    {
        printf("\nEnter the truck id which wants to exit from garage : ");
        scanf("%d",&id);
        for(t=0;t<=garage_top;t++)
        {
            if(truck_in_garage[t]==id)
            count++;
        }
        if(count==0)
        printf("\nSorry, Truck id -> %d is not present in the garage\n",id);
        else
        {
            if(truck_in_garage[garage_top]==id)
            {
                pay=charge(days_of_stay[garage_top]);
                printf("\nThe rent for stay of truck id -> %d  is Rs. %d\n",truck_in_garage[garage_top],pay);
                printf("\nTruck id -> %d has successfully moved out from the garage\n",truck_in_garage[garage_top]);
                garage_top--;
            }
            else
            printf("\nTruck id -> %d cannot be moved out of the garage \n",id);
        }
    }
    else
    printf("\nSorry, The garage is empty\n");
}
void display_garage_truck()
{
    int t;
    for(t=0;t<=garage_top;t++)
    printf("\nTrucks present in the garage are : %d\n",truck_in_garage[t]);
}
void display_road_truck()
{
    int t;
    for(t=0;t<=r;t++)
    printf("\nTrucks present on the road are : %d\n",truck_on_road[t]);
}

