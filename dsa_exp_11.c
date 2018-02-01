#include <stdio.h>
#include <stdlib.h>
struct node
{
	char data;
	struct node *next;
};
struct node *head,*tail,*nw,*temp1,*temp2,*temp,*head1,*tail1;

void create()
{
	nw=(struct node*)malloc(sizeof(struct node));
	nw->data='F';
	head=nw;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data='L';
	nw->next=temp;
	nw=(struct node*)malloc(sizeof(struct node));
	nw->data='A';
	temp->next=nw;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data='M';
	nw->next=temp;
	nw=(struct node*)malloc(sizeof(struct node));
	nw->data='E';
	temp->next=nw;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data='S';
	nw->next=temp;
	tail=temp;
	temp->next=NULL;
}
void del(int x)
{
	int i;
	tail->next=head;
	temp1=head;
	while(temp1->next!=temp1)
	{
		for(i=1;i<x-1;i++)
		temp1=temp1->next;
		temp2=temp1->next;
		temp1->next=temp2->next;
		temp2->next=NULL;
		temp1=temp1->next;
	}
	printf("%c --> ",temp1->data);
	if(temp1->data=='F')
	printf("Friends\n");
	else if(temp1->data=='L')
	printf("Love\n");
	else if(temp1->data=='A')
	printf("Affection\n");
	else if(temp1->data=='M')
	printf("Marriage\n");
	else if(temp1->data=='E')
	printf("Enmity\n");
	else
	printf("Sister\n");
}
void upd(int x)
{
	int i;
	tail->next=head;
	temp1=head;
	nw=(struct node *)malloc(sizeof(struct node));
	nw->data=NULL;
	head1=nw;
	while(temp1->next!=temp1)
	{
		for(i=1;i<x-1;i++)
		temp1=temp1->next;
		temp2=temp1->next;
		temp1->next=temp2->next;
		temp2->next=NULL;
		temp1=temp1->next;
		if(nw->data==NULL)
		{
			nw->data=temp2->data;
			tail1=nw;
		}
		else
		{
			nw=(struct node *)malloc(sizeof(struct node));
			nw->data=temp2->data;
			nw->next=head1;
			head1=nw;
		}
	}
	nw=(struct node *)malloc(sizeof(struct node));
	nw->data=temp1->data;
	nw->next=head1;
	head1=nw;
	printf("%c --> ",head1->data);
	if(head1->data=='F')
	printf("Friends\n");
	else if(head1->data=='L')
	printf("Love\n");
	else if(head1->data=='A')
	printf("Affection\n");
	else if(head1->data=='M')
	printf("Marriage\n");
	else if(head1->data=='E')
	printf("Enmity\n");
	else
	printf("Sister\n");
}
int main()
{
	int x,n;
	create();
	printf("Enter the number of uncommon letters\n");
	scanf("%d",&x);
	printf("Choose the method\n1: Deletion\n2: Updation\n");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			del(x);
			break;
		case 2:
			upd(x);
			break;	
	}
	return 0;
}

