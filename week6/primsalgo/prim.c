/*
name- pankaj kumar
roll - 111601014
lab-5 - prims algorithm;
*/

#include <stdio.h>
#include <stdlib.h>

struct graph {                      //for making adjancy list;
    int vertex1; //next node;
    int vertex2;
    int weight; //weight
    int colour;//red==2;tree edge;black==1;normal edge;
    struct graph* next; //pointer
};
struct pheap                 //for priority queue;
{
	int vertex1;
	int vertex2;
	int weight;
}; 
struct pheap heap[100];      //priority queue heap array;

int N,M;
int heapsize=-1;
int visited[100];       //for marking visited;

void print_graph(struct graph* nodes[]) ;//for printing graph
int addedges(int vertex1,int vertex2,int wt);//for adding edges to priority queue
struct pheap deleteMin(); //for deleting minimum from priority queue
int minimum(int child1,int child2);
int printHeaparray();//just for checking queue data
int prims(struct graph* graph[],struct graph* cgraph[]) ;//prims algorithm
int complete_graph(struct graph* cgraph[],struct graph* graph_dot[],struct graph *cgraph2[]) ;//creating dot file




void makelist(int i, int vertex, int weight,int colour, struct graph* nodes[])//making adjancy llist
{
    int temp3=0;
    struct graph* new_node = (struct graph*)malloc(sizeof(struct graph));	
    struct graph* last = nodes[i];   
    new_node->vertex1 = i;
    new_node->vertex2=vertex;
    new_node->weight = weight;
    new_node->colour=colour;
    new_node->next = NULL;
    if (nodes[i] == NULL) {
        nodes[i] = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}

void read_graph(struct graph* graph1[],struct graph* graph_dot[],char * file)//reading graph
{
    FILE* fp;

    int i, j, v1, v2, wt; // converted file name;
    fp = fopen(file, "r"); //opening matrix file for read only
    if (fp == 0) {
        printf("Error in opening the file %s.\n", file);
        return;
    }

    fscanf(fp, "%d", &N); 
    fscanf(fp, "%d", &M);
    for (i = 0; i < N; i++) {
        graph1[i] = NULL;
        graph_dot[i]=NULL;
        
    }

    for (i = 0; i < M; i++) {
fscanf(fp, "%d %d %d", &v1, &v2, &wt);
        makelist(v1, v2, wt,1, graph1);
        makelist(v2, v1, wt,2, graph1);
       makelist(v1, v2, wt,1, graph_dot);
    }
   
}

int main()
{
	 int i, j, k;
	 char fname[20];
    struct graph* graph[100];
    struct graph* graph_dot[100];
    struct graph* cgraph[100];
    struct graph* cgraph2[100];
     
    for(i=0;i<N;i++)
    {
    	visited[i]=0;
    }
   printf("\n enter the input file name ");
   scanf("%s",fname);       
    read_graph(graph,graph_dot,fname); //reading graph;
   // print_graph(graph);
  //  print_graph(graph_dot);
    printf("\n printing spanning tree edges");
    prims(graph,cgraph);
  //  printHeaparray();
    complete_graph(cgraph,graph_dot,cgraph2);
  //  print_graph(cgraph);
   print_graph(cgraph2);

}

void print_graph(struct graph* nodes[]) {
    int i;
    struct graph* temp = NULL;
    FILE* p;
    char file[100];
   printf("\n give output dot file name");
    scanf("%s", file);
    p = fopen(file, "w"); //opening matrix file for read only
    if (p == 0) {
        printf("Error in opening the file %s.\n", file);
        return;
    }
    fprintf(p, "graph one {\n");
    for (i = 0; i < N; i++) {
        
        temp = nodes[i];
        if (temp != NULL) {
            while (temp != NULL) {
                //printf("{%d-%d->%d}, ", i, temp->vertex, temp->weight);
                if(temp->colour==1)
                fprintf(p, "%d -- %d [label=%d];", i, temp->vertex2, temp->weight);
            	else
            	fprintf(p, "%d -- %d [label=%d] [color=red];", i, temp->vertex2, temp->weight);	
                temp = temp->next;
            }
        }
    }
    fprintf(p, "}\n");
}

//add vertices to priority queue;

int addedges(int vertex1,int vertex2,int wt)
{
	struct pheap temp; 			
heapsize=heapsize+1;
	if(heapsize==0)
	{
heap[0].weight=wt;
heap[0].vertex1=vertex1;
heap[0].vertex2=vertex2;
        return 0;
	}
	else
	{
		heap[heapsize].weight=wt;
		
		heap[heapsize].vertex1=vertex1;
		heap[heapsize].vertex2=vertex2;

		int redflag=0,k,h=heapsize;

		while(1)
		{
			k=((h+1)/2)-1;
			if(heap[h].weight<heap[k].weight)
			{
				temp=heap[h];
				heap[h]=heap[k];
				heap[k]=temp;
				h=k;
			}
			else
			{
				
                                 return 0;
			}
			if(h==0)
			{
			
                                return 0;
			}
		}

	}
}


struct pheap deleteMin()
{
int redflag=0,child1=1,child2=2,child;
struct pheap min,temp;

	
min=heap[0];
heap[0]=heap[heapsize];
heapsize=heapsize-1;
int h=0;

                 while(1)
		{
                     child1=2*h+1;
		     child2=2*h+2;
                     if(child2<=heapsize)
                      {
                     child=minimum(child1,child2);
                       }
                   else if(child1<=heapsize)
                           {
			child=child1;
                            }
                         else
                        {
                          
                           return min;
                        }
                  
			if(heap[h].weight>heap[child].weight)
			{
				temp=heap[h];
				heap[h]=heap[child];
				heap[child]=temp;
				h=child;
			}
			else
			{
			                                 return min;
			}
			
		}



return min;
}

int minimum(int child1,int child2)
{
	if((heap[child1].weight)<(heap[child2].weight))
	{
	return child1;
	}
	else
	return child2;
}

int prims(struct graph* graph[],struct graph* cgraph[])
{

struct graph  *temp=NULL,*k=NULL;
struct pheap node;
int i;
temp=graph[0];
visited[0]=1;
k=graph[0];
        for (i = 0; i < N; i++) {
        cgraph[i] = NULL;     
    }	

for(i=0;i<N-1;i++)
{	

while(temp!=NULL)
{if(visited[temp->vertex2]==0)
	{
addedges(temp->vertex1,temp->vertex2,temp->weight);
//printf("\nv1-%d,v2-%d,wt-%d",temp->vertex1,temp->vertex2,temp->weight);
}

temp=temp->next;
}

node=deleteMin();
if(visited[node.vertex2]==1)
{  
	while(visited[node.vertex2]==1)
	{
	node=deleteMin();
	}
	temp=graph[node.vertex2];
	k=graph[node.vertex2];
	visited[node.vertex2]=1;
	//printf("v1-%d,v2-%d,wt-%d",node.vertex1,node.vertex2,node.weight);
	if(node.vertex1<node.vertex2){
	makelist(node.vertex1,node.vertex2,node.weight,2,cgraph);//tree edge;
printf("\n (%d,%d) -> %d ",node.vertex1,node.vertex2,node.weight);}
    else{
	makelist(node.vertex2,node.vertex1,node.weight,2,cgraph);//tree edge;
printf("\n (%d,%d) -> %d ",node.vertex1,node.vertex2,node.weight);}
}
else
{
	temp=graph[node.vertex2];
	visited[node.vertex2]=1;
	k=graph[node.vertex2];
	//printf("v1-%d,v2-%d,wt-%d",node.vertex1,node.vertex2,node.weight);
	if(node.vertex1<node.vertex2){
	makelist(node.vertex1,node.vertex2,node.weight,2,cgraph);//tree edge;
printf("\n (%d,%d) -> %d ",node.vertex1,node.vertex2,node.weight);}
    else{
	makelist(node.vertex2,node.vertex1,node.weight,2,cgraph);//tree edge;
printf("\n (%d,%d) -> %d ",node.vertex1,node.vertex2,node.weight);}


}
}
}

int printHeaparray()
{
	int i;
	printf("\n printHeaparray=%d", heapsize);
	for(i=0;i<=heapsize;i++)
	{
		printf("\n(%d - %d) -> %d",heap[i].vertex1,heap[i].vertex2,heap[i].weight);
	}
}

int complete_graph(struct graph* cgraph[],struct graph* graph_dot[],struct graph* cgraph2[]) 
{
	struct graph *temp1=NULL,*temp2=NULL;
int i;
for(i=0;i<N;i++)
{
	cgraph2[i]=NULL;
}
  for (i = 0; i < N; i++) {
        
        temp1 = graph_dot[i];
        temp2 =cgraph[i];
        while (temp1 != NULL) {
            
            	if(temp2!=NULL &&((temp1->vertex1==temp2->vertex1) && (temp1->vertex2==temp2->vertex2)))

            	{
            		makelist(temp1->vertex1,temp1->vertex2,temp1->weight,2,cgraph2);	

            		temp2=temp2->next;
            	}
        
                
            	else
            	makelist(temp1->vertex1,temp1->vertex2,temp1->weight,1,cgraph2);	
                temp1=temp1->next;

       
        }
    }
 
}






