# dijkstra
Dijskstra's for a grid using C  
# USAGE    
#include<stdio.h>  
#include"Dijkstras.c"  
int main(){  
char *path;  
int count=0,i=0;  
path=dijkstra(1,25,&count);  
for(i=0;i<=count;i++){  
printf("%c\n",path[i]);  
}  
return 0;  
}  

