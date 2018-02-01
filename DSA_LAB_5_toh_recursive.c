#include<stdio.h>
#include<stdlib.h>
void toh(int ngd,char source,char idt,char dest); /*ngd = n no. of golden disks , ,source = initial tower ,idt = intermediate tower, dest = final tower*/
int main()
{
	char source='A',idt='B',dest='C';/*idt = intermediate pole*/
	int ngd;
	printf("\nEnter the number of golden disks : ");
	scanf("%d",&ngd);
	printf("\nThe Sequence is : \n");
	toh(ngd,source,idt,dest);
	return 0;
}
void toh(int ngd,char source,char idt,char dest)
{
	if(ngd==1)
	{
		printf("\nMove golden disk %d from  pole %c  ->  pole %c\n",ngd,source,dest);
		return;
	}
	toh(ngd-1,source,dest,idt);
	printf("\nMove the golden disk %d from  pole %c  ->  pole %c\n",ngd,source,dest);
	toh(ngd-1,idt,source,dest);
}

