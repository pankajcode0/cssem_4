/*
name- pankaj kumar
roll - 111601014
lab-5 dijkstra algorithm;
*/

#include <stdio.h>
#include <stdlib.h>

struct graph {                      //for making adjancy list;
    int vertex; //next node;
    int weight; //weight
    struct graph* next; //pointer
};

struct pqueue                 //for priority queue;
{
	int vertex;
	int weight;
}; 
struct pqueue heap[100];      //priority queue heap array;


void read_graph(struct graph* graph1[],struct graph* graph_dot[]);// for reading graph
void print_graph(struct graph* nodes[]); //for printing dot file

int newHeap();// building priority que heap;

int minimum(int child1,int child2);
int printHeaparray();
int addkey(int i ,int wt);//its update key;
int dijkstra(struct graph* nodes[]);
int delkey(int i); // delete key;
int printdist();

int N, M, root;
int visited[100];
//int heap[100];
int heapsize=-1;
int distance[100];
int priv[100],backtrace[100];//priv array to keep track of indexing in heap;//backtrace to trace shortest path;
int max=10000;

void makelist(int i, int vertex, int weight, struct graph* nodes[])//making adjancy llist
// function for reading adjancy list
{
    /* 1. allocate graph */
    struct graph* new_node = (struct graph*)malloc(sizeof(struct graph));

    struct graph* last = nodes[i];

    new_node->vertex = vertex;
    new_node->weight = weight;
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

int main()
{
    int i, j, k;
    struct graph* graph1[100];
    struct graph* graph_dot[100]; 
    
    read_graph(graph1,graph_dot); //reading graph;
   // print_graph(graph_dot);
       for(i=0;i<N;i++)
      {
      	distance[i]=max;
      }
      distance[root]=0;
    newHeap();                    //building heap with all distace max and source 0;
 //print_graph(graph1);
//print_graph(graph1);

//printHeaparray();
//delkey(0);
//printHeaparray();
   dijkstra(graph1);            //applying dijkstra;
   printf("printing shortest distance of each vertex from source %d\n",root);

    printdist();

    
    //printHeaparray();
    printf("\n print backtrace");
    backtrace[root]=-1;
    for(i=0;i<N;i++)
    {
    	printf("\nnode-> %d------priv->%d",i,backtrace[i]);
    }
    print_graph(graph_dot); 
   // delkey(root);
    //printHeaparray();
}

void read_graph(struct graph* graph1[],struct graph* graph_dot[])
{
    char file[30];
    printf("\n enter input file name");
    scanf("%s", file);
    //struct graph *nodes[100];

    FILE* fp;

    int i, j, v1, v2, wt; // converted file name;
    fp = fopen(file, "r"); //opening matrix file for read only
    if (fp == 0) {
        printf("Error in opening the file %s.\n", file);
        return;
    }

    fscanf(fp, "%d", &N); // scanning size of matrix
    fscanf(fp, "%d", &M);
    for (i = 0; i < N; i++) {
        graph1[i] = NULL;
        graph_dot[i]=NULL;
    }

    for (i = 0; i < M; i++) {
        // storing the matix in form of string
        //print_graph(graph1);
fscanf(fp, "%d %d %d", &v1, &v2, &wt);
        makelist(v1, v2, wt, graph1);
        makelist(v1,v2,wt,graph_dot);
        makelist(v2, v1, wt, graph1);
    }
    fscanf(fp, "%d", &root);
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
        printf("\n");
        temp = nodes[i];
        if (temp != NULL) {
            while (temp != NULL) {
                //printf("{%d-%d->%d}, ", i, temp->vertex, temp->weight);
                fprintf(p, "%d -- %d [label=%d];", i, temp->vertex, temp->weight);
                temp = temp->next;
            }
        }
    }
    fprintf(p, "}\n");
}

int printdist()
{int i;
	for(i=0;i<N;i++)
	{
		printf("\nnode-> %d --- distance->%d",i,distance[i]);
	}
}

int newHeap()
{
int data,j,i;

heapsize=N-1;
for(i=0;i<N;i++)
{
                heap[i].vertex=i;
                priv[i]=i;
                heap[i].weight=max;
                            
            }

            heap[root].weight=0;
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

int printHeaparray()
{
	int i;
//	printf("int print printHeaparray=%d\n", heapsize);
	for(i=0;i<=heapsize;i++)
	{
		printf("\n%d %d",heap[i].vertex,heap[i].weight);
	}
}



int addkey(int i,int wt)
{

int k=priv[i];



	heap[k].weight=wt;




//if wt is more than child in heap


		int redflag=0,child1,child2,child,temp1,temp2,temp,flag1=0;


                 while(redflag==0)
		{
                     child1=2*k+1;
		     child2=2*k+2;
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
                          return 0;
                           
                        }
                  
			if(heap[k].weight>heap[child].weight)
			{
				temp1=heap[k].weight;
				temp2=heap[k].vertex;
				temp=priv[k];
				priv[k]=child;
				priv[child]=temp;
				heap[k].weight=heap[child].weight;
				heap[k].vertex=heap[child].vertex;
				heap[child].weight=temp1;
				heap[child].vertex=temp2;
				k=child;
				flag1=1;
			}
			else
			{
				return 0;
                                 
			}
			
		}


		//if wt is less than parent in heap;
        if(flag1==0)
        {
		 while(redflag==0)
        
		{
                     child=k/2-1;
		     
                     if(child>=0)
                      {
                     
                       }
                
                         else
                        {
                          return 0;
                           
                        }
                  
			if(heap[k].weight<heap[child].weight)
			{
				temp1=heap[k].weight;
				temp2=heap[k].vertex;
				temp=priv[k];
				priv[k]=child;
				priv[child]=temp;
				heap[k].weight=heap[child].weight;
				heap[k].vertex=heap[child].vertex;
				heap[child].weight=temp1;
				heap[child].vertex=temp2;
				k=child;
				flag1=1;
			}
			else
			{
				return 0;
                                 
			}
			
		}
	}



}

int delkey(int i)
{
int vdel,wtdel,redflag=0,child1=1,child2=2,child,temp,k,temp1,temp2;
k=priv[i];
vdel=heap[k].vertex;
wtdel=heap[k].weight;
heap[k].vertex=heap[heapsize].vertex;
heap[k].weight=heap[heapsize].weight;
heapsize=heapsize-1;
int h=k;


                 while(redflag==0)
		{
                     child1=2*k+1;
		     child2=2*k+2;
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
                          return 0;
                           
                        }
                  
			if(heap[k].weight>heap[child].weight)
			{
				temp1=heap[k].weight;
				temp2=heap[k].vertex;
				temp=priv[k];
				priv[k]=child;
				priv[child]=temp;
				heap[k].weight=heap[child].weight;
				heap[k].vertex=heap[child].vertex;
				heap[child].weight=temp1;
				heap[child].vertex=temp2;
				k=child;
				
			}
			else
			{
				return 0;
                                 
			}
}

return 0;
}

int dijkstra(struct graph* nodes[])
{ 

struct graph* temp=NULL;
int k=root,i,s;
//printf("\n in dijkstra %d",heapsize);
temp=nodes[root];
/*
delkey(root);

 for (i = 0; i < N; i++) {
       // printf("\n %d",temp->vertex);
     
        if (temp != NULL) {
            while (temp != NULL) 
addkey(temp->vertex,temp->weight+distance[k]);
priv[temp->vertex]=k;
temp=temp->next;
printf("\n jj");

}
temp=nodes[heap[0].vertex];
k=heap[0].vertex;
distance[heap[0].vertex]=heap[0].weight;
printf("\n %d im kingSS",distance[heap[0].vertex]);

delkey(k);
*/
int m=root;
 //m= priv[root];
for (i = 0; i < N; i++) {
       // printf("\n %d root ",m);

        temp = nodes[m];
        k=heap[0].weight;
          s=heap[m].vertex;
       //   printf("\n s- %d",s);
       // printf("\n *%d* node \n",m);
     
       // printHeaparray();
       // printf("\n");
       
        if (temp != NULL) {
            while (temp != NULL) {
               // printf("{%d-%d->%d}, ", s, temp->vertex, temp->weight);
                //printf("\n distance -%d > temp->weight %d +k %d",distance[temp->vertex],temp->weight,k);
                if((distance[temp->vertex])>(temp->weight+k)||(distance[temp->vertex]==max&&distance[m]!=max))
                {
                addkey(temp->vertex,temp->weight+k);
                 distance[temp->vertex]=temp->weight+k;
               
              backtrace[temp->vertex]=m;
            }
            else if(k==max)
            {
            //	printf("\n temp->vertex %d, temp->weight %d -",temp->vertex,temp->weight);
            	  addkey(temp->vertex,temp->weight);
                 distance[temp->vertex]=temp->weight;
             

            }
             

                
               
                temp = temp->next;
            }
              delkey(heap[0].vertex);
              m=heap[0].vertex;


        }
        //distance[k]=heap[priv[k]].weight;
       
     
    }


//printf("N-%d -temp->vertex %d",N,temp->vertex);
return 0;


}


