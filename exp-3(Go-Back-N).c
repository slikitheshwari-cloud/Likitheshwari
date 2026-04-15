#include<stdio.h>
int main()
{
	int frames,window,i,sent=0,ack;
	printf("Enter total number of frames: ");
	scanf("%d",&frames);
	printf("Enter window size: ");
	scanf("%d",&window);
	while(sent<frames)
	{
		printf("\n sending frames: ");
		for(i=sent;i<sent+window&&i<frames;i++)
		{
			printf("%d",i);
		}
		printf("\n Enter acknowledgement(-1 for loss): ");
		scanf("%d",&ack);
		if(ack==-1){
			printf("Frame lost! Retransmitting from frame %d(Go-Back-N)\n",sent);
		}
		else
		{
			sent=ack+1;
			printf("Acknowledgement received for frame %d\n",ack);
		}
	}
	printf("\n All frames transmitted successfully\n");
}
