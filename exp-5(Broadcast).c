#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#define MAX 100
int minkey(int key[],bool mstSet[],int v)
{
	int min=INT_MAX,min_index=-1,V;
	for(v=0;v<V;v++)
	{
		if(mstSet[v]==false && key[v]<min)
		{
			min=key[v];
			min_index=v;
		}
	}
	return min_index;
}
void printMST(int parent[],int graph[MAX][MAX],int V)
{
	int i;
	printf("\n Broadcast Tree Edges:\n");
	for(i=1;i<V;i++)
	{
		printf("%d-%d \t %d\n",parent[i],i,graph[i][parent[i]]);
	}
}
void primMST(int graph[MAX][MAX],int V)
{
	int parent[MAX],i,count;
	int key[MAX];
	bool mstSet[MAX];
	for(i=0;i<V;i++)
	{
		key[i]=INT_MAX;
		mstSet[i]=false;
	}
	key[0]=0;
	parent[0]=-1;
	for(count=0;count<V-1;count++)
	{
		int u=minkey(key,mstSet,V);
		mstSet[u]=true;
	}
	printMST(parent,graph,V);
}
int main()
{
	int V,i,j;
	int graph[MAX][MAX];
	printf("Enter number of hosts in subnet: ");
	scanf("%d",&V);
	printf("Enter adjacency matrix (cost between hosts):\n");
	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
		{
			scanf("%d",&graph[i][j]);
		}
	}
	primMST(graph, V);
	return 0;
}

