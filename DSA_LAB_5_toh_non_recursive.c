#include <stdio.h>
#include <stdlib.h>
#include <math.h>/*for pow function*/
struct Stk
{
	int top;
	int *a;  /*a=array*/
	int size;
};
struct Stk* createStk(int size)/*function created for stack of given size*/
{
	struct Stk* stk_obj = (struct Stk*)malloc(sizeof(struct Stk));
    	stk_obj -> size = size;
    	stk_obj -> top = -1;
    	stk_obj -> a = (int*)malloc(stk_obj -> size*sizeof(int));
    	return stk_obj;
}
int Empty(struct Stk *stk_obj)
{
	return (stk_obj->top == -1);
} 
int Full(struct Stk* stk_obj)
{
	return (stk_obj->top == stk_obj->size - 1);
}
void display(char from_pole,char to_pole, int ngd)
{
	printf("Move the golden disk %d from  pole %c  ->  pole %c\n\n", ngd, from_pole, to_pole);
}
void push_disk(struct Stk *stk_obj, int item)/*function of push operation*/
{
	if(Full(stk_obj))
    {
		return;
	}
    	stk_obj -> a[++stk_obj -> top] = item;
}
int pop_disk(struct Stk* stk_obj)/*function of pop operation*/
{
	if(Empty(stk_obj))
    {
		return 0;
	}
	else
	{
    	return stk_obj -> a[stk_obj -> top--];
    }
}
void shift_disk(struct Stk *initial_pole, struct Stk *final_pole, char source, char dest)/*movement of disks b/w two poles*/
{
    int pole_1 = pop_disk(initial_pole);
    int pole_2 = pop_disk(final_pole);
    if(pole_1==0)/* pole 1 is assigned value 0 to represent pole is empty*/
    {
        push_disk(initial_pole, pole_2);
        display(dest, source, pole_2);
    }
    else if(pole_2==0)/*pole 2 is assigned value  0 to represent pole is empty*/
    {
        push_disk(final_pole, pole_1);
        display(source, dest, pole_1);
    }	
    else if(pole_1 > pole_2)/*function of movement is top disk of pole 1 is larger than pole 2*/
    {
        push_disk(initial_pole, pole_1);
        push_disk(initial_pole, pole_2);
        display(dest, source, pole_2);
    } 
    else
    {
        push_disk(final_pole, pole_2);
        push_disk(final_pole, pole_1);
        display(source, dest, pole_1);
    }
}
void toh(int d, struct Stk *initial_pole, struct Stk *idt_pole, struct Stk *final_pole)/*function for tower of hanoi puzzle*/
{
	int i, shift;
    char source = 'A',idt = 'B',dest = 'C';/*idt=intermediate pole*/
    if(d%2==0)/*condition for even number of disks*/
    {
        char c=dest;/*swapping of disk b/w final pole and intermediate pole*/
        dest=idt;
        idt=c;
    }
    shift=pow(2, d) - 1;
    for(i=d;i>=1;i--)
    {
		push_disk(initial_pole, i);
	} 
    for (i=1;i<=shift;i++)
    {
        if (i%3==1)
        {
            shift_disk(initial_pole, final_pole, source, dest);
		} 
        else if (i%3==2)
		{
		    shift_disk(initial_pole, idt_pole, source, idt);
		}
        else if(i%3==0)
        {
            shift_disk(idt_pole, final_pole, idt, dest);
        }
    }	
}
int main()
{
    int d;/* d= nuumber of disks*/
    struct Stk *initial_pole, *final_pole, *idt_pole;
	printf("\nEnter the number of golden disks : ");
	scanf("%d",&d);
	printf("\n The Sequence is : \n");
    initial_pole=createStk(d);/*creation of different stacks each for given pole to hold the given set of disks*/
    idt_pole=createStk(d);
    final_pole=createStk(d);
    toh(d, initial_pole, idt_pole, final_pole);
	printf("\n");
    return 0;
}

