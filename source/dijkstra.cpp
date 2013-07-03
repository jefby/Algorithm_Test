#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define MAX_NODES 1024
#define INFINITY	1000000000 // 10^9

int n,dist[MAX_NODES][MAX_NODES];//dist[i][j] is the distance from i to j



void shortest_path(int s,int t,int path[])
{
	int i,k,min;

	enum label_state{permanent,tentative};
	struct state
	{
		int predecessor;//previous node
		int length;//length from source to this node
		label_state label;//label state
	}state[MAX_NODES];
	struct state *p;
	for(p = &state[0];p<&state[n];p++)
	{
		p->predecessor = -1;
	        p->length = INFINITY;
		p->label = tentative;
    }

    state[t].length = 0;
    state[t].label = permanent;

    k = t;//k is the initial working node
    do
    {
        for(i=0;i<n;++i)//this graph has n nodes
        {
            if(dist[k][i] != 0 && state[i].label == tentative)
            {
                if(state[k].length+dist[k][i] < state[i].length)
                {
                    state[i].predecessor = k;
                    state[i].length = state[k].length+dist[k][i];
                }
            }
        }
        //find the tentatively labeled node with the smallest label
        k = 0; min = INFINITY;
        for(i=0;i<n;++i)
        {
            if(state[i].label == tentative && state[i].length < min)
            {
                min = state[i].length;
                k = i;
            }
        }
        state[k].label = permanent;
    }while(k!=s);

    //copy the path into the output array
    i = 0;k = s;
    do{
        path[i++]=k;k=state[k].predecessor;
    }while(k>=0);
    int path_cnt = i;
    printf("%d",path[0]);
    for(i=1;i<path_cnt;++i)
    {
        printf("->%d",path[i]);
    }
}

int main()
{
    FILE *fin = freopen("input.txt","r",stdin);
    if(fin == NULL)
    {
	    printf("freopen error!\n");
    }
    int i,j,len,n;
    scanf("%d",&n);
    fflush(stdin);
    while(scanf("%d %d %d",&i,&j,&len) == 3)
    {
        dist[i-1][j-1]=len;
    }
    int *path = (int*)malloc(sizeof(int)*n);
    shortest_path(n-1,0,path);
    free(path);
}
