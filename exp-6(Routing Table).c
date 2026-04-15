#include<stdio.h>
#define MAX 10
#define INF 9999

typedef struct{
    int dist[MAX];
    int from[MAX];
} Node;

int main()
{
    int n,i,j,k;
    int cost[MAX][MAX];
    Node table[MAX];

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    printf("Enter cost matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
            table[i].dist[j] = cost[i][j];
            table[i].from[j] = j;
        }
    }

    int updated;
    do{
        updated = 0;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                for(k=0;k<n;k++){
                    if(table[i].dist[j] > cost[i][k] + table[k].dist[j]){
                        table[i].dist[j] = cost[i][k] + table[k].dist[j];
                        table[i].from[j] = k;
                        updated = 1;
                    }
                }
            }
        }
    } while(updated);

    for(i=0;i<n;i++){
        printf("\nRouting table for node %d\n",i);
        printf("Destination\tNext Hop\tDistance\n");
        for(j=0;j<n;j++){
            printf("%d\t\t%d\t\t%d\n",j,table[i].from[j],table[i].dist[j]);
        }
    }

    return 0;
}
