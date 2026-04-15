#include<stdio.h>
#include<string.h>
void computeCRC(char data[], char key[])
{
	int i,j;
	int dataLen=strlen(data);
	int keyLen=strlen(key);
	char temp[50];
	strcpy(temp,data);
	for(i=0;i<=dataLen-keyLen;i++)
	{
		if(temp[i]='1')
		{
			for(j=0;j<keyLen;j++)
			{
				temp[i+j]=(temp[i+j]==key[j])?'0':'1';
			}
		}
	}
printf("CRC remainder:");
for(i=dataLen-keyLen+1;i<dataLen;i++)
printf("%c",temp[i]);
printf("\n");
}
int main()
{
	char data[50],key[20],choice,i;
	printf("Enter the data bits:");
	scanf("%s",data);
	printf("Choose CRC polynomial:\n");
	printf("1.CRC-12\n");
	printf("2.CRC-16\n");
	printf("3.CRC-CCITT\n");
	printf("Enter the choice:");
	scanf("%d",&choice);
	if(choice==1)
	{
		strcpy(key,"1100000001111");
    }
	else if(choice==2)
	{
			strcpy(key,"11000000000000101");
	}
	else if(choice==3)
	{
		strcpy(key,"1000100000100001");		
	}
	else
	{
		printf("invalid choice");
		return 0;
		
	}
	int keyLen=strlen(key);
	for(i=0;i<keyLen-1;i++)
	strcat(data,"0");
	computeCRC(data,key);
	return 0;
}
