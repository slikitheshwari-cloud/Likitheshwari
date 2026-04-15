#include<stdio.h>
int main()
{
	int incoming;
	int bucket_size,output_rate,n,i;
	int packets[50];
	int bucket_content=0;
	printf("Enter bucket size:");
	scanf("%d",&bucket_size);
	printf("Enter output_rate(packets per second): ");
	scanf("%d",&output_rate);
	printf("Enter number of time intervals: ");
	scanf("%d",&n);
	printf("Enter number of packets arriving at eack interval:\n");
	for(i=0;i<n;i++)
    {
    	scanf("%d",&packets[i]);
	}
	printf("\n Time\tIncoming\tBucket\tSent\tReamining\tDropped:\n");
	for(i=0;i<n;i++)
	incoming=packets[i];
	int dropped=0;
	if(incoming+bucket_content>bucket_size){
		dropped=(incoming+bucket_content)-bucket_size;
		bucket_content+=incoming;
	}
	int sent=(bucket_content<output_rate)?bucket_content:output_rate;
	bucket_content-=sent;
	printf("%d\t%d%d\t%d%d\t%d\n",i+1,incoming,bucket_content+sent,sent,bucket_content,dropped);
	return 0;	
}
