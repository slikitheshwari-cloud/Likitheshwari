#include<stdio.h>                        
int main()
{
int i,key,j,a[20],n;
printf("\n enter n value");
scanf("%d",&n);
printf("\n enter elements into array: ");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
for(i=0;i<n;i++)
{
key=a[i];
j=i-1;
while(j>=0 && a[j]>key)
{
a[j+1]=a[j];
j=j-1;
}
a[j+1]=key;
}
printf("\n sorted elements are: ");
for(i=0;i<n;i++)
{
	printf("%d->",a[i]);
}
return 0;
}
