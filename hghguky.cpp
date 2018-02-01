#include<stdio.h>
#include<string.h>
struct hash_table
{
int place;
char data[10];
int status;
};
int size;
int weight(char *c)
{
int i,sum=0;
int l=strlen(c);
for(i=0;i<l;i++)
{
sum+=c[i]-97;
}
return sum;
}
int prime(int n)
{
int p=1,i;
for(i=2;i<=n/2;i++)
{
if(n%i==0)
{
p=0;
break;
}
}
if(p==0)
{
n+=1;
prime(n);
}
else
{
size=n;
return n;
}
}
int place(char *c,int size)
{
int p=weight(c)%size;
return(p);
}
int main()
{
int n,i,p;
printf("Enter the no. of elements");
scanf("%d",&n);
prime(n);
printf("prime=%d",size);
struct hash_table a[size];
char b[10];
for(i=0;i<size;i++)
{
a[i].status=0;
a[i].place=i;
strcpy(a[i].data,"");
}
for(i=0;i<n;i++)
{
printf("\n\nEnter the element:\t");
scanf("%s",b);
p=place(b,size);
printf("place by modulo= %d",p);
while(a[p].status!=0)
{
p+=1;
}
strcpy(a[p].data,b);
a[p].status=1;
}
for(i=0;i<size;i++)
{
printf("\nHash table");
printf("\nplace: %d\telement: %s",a[i].place,a[i].data);
}
return 0;
}


