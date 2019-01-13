#include<stdio.h>
#include<stdlib.h>
#define INF 999
#define TRUE 1
#define FALSE 0
void adjacent(int x1,int y1,int adj[4][2]);
int min_dis(int dist[], int included[]);
void sh_path(int start, int end);

int grid[5][5]={
    {1,2,3,4,5},
    {6,7,8,9,10},
    {11,12,13,14,15},
    {16,17,18,19,20},
    {21,22,23,24,25}};

void adjacent(int x1,int y1,int adj[4][2]){
    int i=0,x=0,y=0;
    int key_x[4]={-1,0,1,0};//N E S W
    int key_y[4]={0,1,0,-1};
    for(i=0;i<4;i++){
        adj[i][0]=-1;
        adj[i][1]=-1;
        x=x1+key_x[i];
        y=y1+key_y[i];
        if(x>-1&&y>-1&&x<5&&y<5){
            adj[i][0]=x;
            adj[i][1]=y;
        }
    }
}
int min_dis(int dist[], int included[]){
    int min=INF,min_index=0,i=0;
    for(i=0;i<25;i++)
    {
        if((included[i]==FALSE)&&dist[i]<min)
        {
            min=dist[i];
            min_index=i;
        }
    }
    return min_index;
}
void sh_path(int start, int end){
    int dist[25],parent[25];
    int count=0,p_nx=0,p_ny=0,n_nx=0,n_ny=0,weight=1,u=0,v=0,i=0,j=0;
    int included[25];
    int adj[4][2]={{0,0},{0,0},{0,0},{0,0}};
    for(i=0;i<25;i++){
        dist[i]=INF;
        included[i]=FALSE;
        parent[i]=INF;
        }
    dist[start]=0;
    parent[start]=start;
    for(i=0;i<24;i++){
        u=min_dis(dist,included);
    //    printf("%d\n",u);
        included[u]=TRUE;
        p_nx=u/5;
        p_ny=u%5;
        adjacent(p_nx,p_ny,adj);
        for(j=0;j<4;j++){
            if(adj[j][0]!=-1){

                n_nx=adj[j][0];
                n_ny=adj[j][1];
                v=grid[n_nx][n_ny]-1;
                //printf("%d  %d\n",n_nx,n_ny);
                if((included[v]==FALSE)&&(dist[v]>(dist[u]+weight)))   // d[u,v] > d[u,i]+d[i,v] here d[i,v] is always 1 for a grid
                    {dist[v]=dist[u]+weight;
                     parent[v]=u;
                          }
            }
        }
    }
    for(int i=0;i<25;i++)
        printf("%d  %d\n",i,parent[i]);
}

int main(){
int i=0,j=0;
int *p;
int start=1;
int end=25;

for(i=0;i<5;i++){
    for(j=0;j<5;j++)
    printf("%*d  ",4,grid[i][j]-1);
    printf("\n");}
sh_path(12,4);
return 0;
}
