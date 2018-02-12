/*
name - pankaj kumar
roll - 111601014

lab task week1 dfs finding tree edges back edges forward edges and cross edges

*/



#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>
#include"newlinklistlib.h"
#define inf 1000000000


struct arraylist
{
int data;
struct arraylist *next;
};
int N,moon=0;
int time=0;
struct arraylist *head_ref[100];
struct linklist *head=NULL,*tail=NULL;
int priv[100];
int visited[100];
int timed[100];
int timef[100];
//void printlist();
int printdot();
int scanfile();
int checkvisited();
int dfs();
int dfs_visit(int u);
int printpriv();
int checkedge(int data ,int k);
int printtime();

//void addarray(int i,int value)

void addarray(int i, int new_data)  // function for reading adjancy list
{
    /* 1. allocate arraylist */
    struct arraylist* new_arraylist = (struct arraylist*) malloc(sizeof(struct arraylist));

    struct arraylist *last = head_ref[i];  /* used in step 5*/

    /* 2. put in the data  */
    new_arraylist->data  = new_data;

    /* 3. This new arraylist is going to be the last arraylist, so make next of
          it as NULL*/
    new_arraylist->next = NULL;

    /* 4. If the Linked List is empty, then make the new arraylist as head */
    if (head_ref[i] == NULL)
    {
       head_ref[i] = new_arraylist;
       return;
    }

    /* 5. Else traverse till the last arraylist */
    while (last->next != NULL)
        last = last->next;

    /* 6. Change the next of last arraylist */
    last->next = new_arraylist;
    return;
}

int main()       // main function
{ memset(visited, 0, sizeof visited);
  memset(priv, -1, sizeof priv);
  memset(timef, 0, sizeof timef);
  memset(timed, 0, sizeof timed);

	scanfile();
  dfs();
 // printpriv();
  printdot();
  printtime();
  printf("\n printing topology");
  //print(&head);
  if(moon==0)
  {
  print(&head);
}
else
{
  printf("not a dag");
}
  return 0;
}

int scanfile()    // scanning input file
{
int i,k=0,data,index;
char fname[30];

printf("\n enter input file name");
scanf("%s",fname);

  FILE *fp;

  int j,m,n,temp;

                                       // converted file name;
     fp = fopen(fname, "r");              //opening matrix file for read only
   if (fp == 0)
   {
     printf("Error in opening the file %s.\n", fname);
     return(1);
   }


     fscanf(fp, "%d", &N);    // scanning size of matrix
     for(i=0;i<N;i++)
     {
      head_ref[i]=NULL;
     }

  for(i = 0; i < N; i++)
  {
          // storing the matix in form of string
    fscanf(fp, "%d", &temp);
    while (temp!=-1)
    {
      addarray(i, temp);
      fscanf(fp, "%d", &temp);
    }
  }

 //printlist();


}
int printdot()    // printing dot file
{
  char name[30];
  FILE *p;
  int i,j;
 struct arraylist *temp=NULL;
  printf("\n enter dot file name with .dot extension");
  scanf("%s",name);

   p = fopen(name, "w");                // writing on output file
   if (p == 0)
   {
     printf("Error in opening the file\n");
     return(1);
   }
  fprintf(p,"digraph one {\n");        // printing dot file header in file
  for(i=0;i<N;i++)
  {

temp=head_ref[i];

     if(temp!=NULL)

    {
      while(temp!=NULL)
      {
       // 1 tree edge,2 forward edge,3 backedge,4crossedge;
        int k=checkedge(i,temp->data);
        if(k==1)
        {
       fprintf(p,"%d -> %d [color=red];",i,temp->data);
       printf("\n%d -> %d [color=red] tree edge;",i,temp->data);
         }

         else if(k==2)
        {
       fprintf(p,"%d -> %d [color=blue][style=dotted];",i,temp->data);

        printf("\n%d -> %d [color=blue] forward edge;",i,temp->data);
         }

         else if(k==3)
        {
       fprintf(p,"%d -> %d [color=black][style=dotted];",i,temp->data);
        printf("\n%d -> %d [color=black] back edge;",i,temp->data);
         }

         else if(k==4)
        {
       fprintf(p,"%d -> %d [color=green][style=dotted] ;",i,temp->data);
        printf("\n%d -> %d [color=green] cross edge;",i,temp->data);
         }

       temp=temp->next;
      }
    }



  }
  fprintf(p," }");
  fclose(p);
}

int checkedge(int k ,int data) //checking edges back forward tree or cross edge
{int i;
  for(i=0;i<N;i++)
  {

    if(priv[data]==i&&i==k)
  {
    return 1;      //tree edge
  }
    }
  if(timed[k]<timed[data]&&timef[k]>timef[data])
  {
     return 2;     //forward edge
  }
  if(timed[k]>timed[data]&&timef[k]<timef[data])
  { moon=1;
     return 3;    //back edge
  }
    return 4;      //cross edge
}


/*

void printlist()      // for printing list
{
int i;
struct arraylist *temp=NULL;
for(i=0;i<10;i++)
{

	printf("\n");
temp=head_ref[i];

             	if(temp!=NULL)

		{
			while(temp!=NULL)
			{
			 printf("%d ",temp->data);
			 temp=temp->next;
			}
		}
              else
		{
			printf("\n empty");
		}
	}
}
*/
int dfs()          // dfs algorithm
{
int i,k;
time=0;
for(i=0;i<N;i++)
{


  if(visited[i]<1)
  {
    dfs_visit(i);
    visited[i]=1;
  }

}
}
int dfs_visit(int u)
{
  pushlast(&tail,&head,u);
  time=time+1;
  timed[u]=time;
  visited[u]=2;
  struct arraylist *temp=NULL;
  temp=head_ref[u];
  while(temp!=NULL)
  {
int k=temp->data;
if(visited[k]==0)
{
  dfs_visit(k);
  priv[k]=u;
  }
  temp=temp->next;
}
visited[u]=3;
time=time+1;
timef[u]=time;
}


int printpriv()   //printing privious node
{
  int i,j,k;
  for(i=0;i<N;i++)
  {
 // printf("\n %d -> %d",i,priv[i]);

  }
}
int printtime() //printing discover and final time
{
  int i,j,k;
  printf("\n  discover and final time of nodes");
  for(i=0;i<N;i++)
  {
  printf("\n node - %d --- d-%d -> f-%d",i,timed[i],timef[i]);

  }

}
