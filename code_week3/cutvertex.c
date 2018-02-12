/*
name - pankaj kumar 
roll - 111601014

cut vertices
// compile as cutvertices.c only keeping newlinklistlib.h in same folder

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


char matrix[100][100];
int mmatrix[100][100];
int n;
int d[100];
int visited[100];
int prev[100];
int trace[100];

int read(char * filename);

int dfsr(int node);


int write();
int cutnode(int node);
int cutv(int v);
int check(int l, int v);
int allcutvertex(int node);

int read(char * filename)                        //function declaration
{

	FILE *fp;
	char ch[10];            // char *name- name of converted file; char a[500][500] stores the matrix from matrixtext file
	int i,j,m;
	  
		                                 // converted file name;
		 fp = fopen(filename, "r");              //opening matrix file for read only
	 if (fp == 0)	   
	 {
		 printf("Error in opening the file %s.\n", filename); 
		 return(1);
	 }

		 fscanf(fp, "%s",ch);
		 fscanf(fp, "%s",ch);
		 fscanf(fp, "%d", &n);    // scanning size of matrix         
		 m=n;
	  
	
	
	for(i = 0; i < m; i++)
	{
		fscanf(fp, "%s", matrix[i]);      // storing the matix in form of string
		for(int j=0; j<n; j++)
		{
			mmatrix[i][j] = matrix[i][j] - '0'; 
		}
	}

	fclose(fp);
}
int main()
{
        int i,j,len=0,node;
	char name[30];
	printf("\n enter the file name: ");
	scanf("\n %s",name);
	
	memset(visited, 0, sizeof visited);	
	read(name);
        printf("\n enter a node for dfs to start");
        scanf(" %d",&node);
	dfsr(node);
	write();
	allcutvertex(node);
}

int dfsr(int node)
{
//printf("\n node- %d",node); //to se how nodes traversed
int i,count=0;
visited[node]=1;
for(i=0;i<n;i++)
{
if(visited[i]==0)
{
count++;
}
}
if(count==0)
{
return node;
}
for(i=0;i<n;i++)
{
if(mmatrix[node][i]==1&&visited[i]==0)
{
mmatrix[node][i]=5;
mmatrix[i][node]=5;
dfsr(i);
}
}
}

int write()                        //function declaration
{


	FILE *p;
	char names[100];
	int i,m,j;
	printf("\n input dot file name");
	scanf("%s",names);
	  
	 p = fopen(names, "w");	              // writing on output file
	 if (p == 0)                
	 {
		 printf("Error in opening the file\n");
		 return 1;
	 }
	fprintf(p,"graph one {\n");        // printing dot file header in file
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)

		{
		  if(mmatrix[i][j]==5||mmatrix[j][i]==5)
			{
		
				fprintf(p,"  %d--%d [color = red];",i,j);   // printing the graph chain in dot file
			}
			else if(mmatrix[i][j]>=1)
			{   
				fprintf(p,"  %d--%d ;",i,j);   // printing the graph chain in dot file
			}
		}
	}
	fprintf(p," }");
	fclose(p);
}

int cutnode(int node)
{
int i,j,count=0;


for(i=0;i<n;i++)
{
if(mmatrix[node][i]==5)
{
count++;
}
}
if(count>1)
{
return 0;// remove it 
}
else
return 1; // keep it
}
int cutv(int v)
{
	int i,j,count=0,k;
for(j=0;j<n;j++)
{
if(mmatrix[v][j]==5)
{
count++;
}
}
if(count>=2)
{
	for(i=0;i<n;i++)
	{
		if(mmatrix[v][i]==5)
		{
		k=check(i,v);
		if(k==1)
		{
		return 1; //backedge is present
		}
		else
		{
		return 0; // no backedge remove it
		}

	        }
	}
}
else
return 1;
}
int check(int l, int v)
{
int i;
for(i=0;i<n;i++)
{
	if(mmatrix[v][i]==5&&mmatrix[l][i]==1)
	{
	return 1; //there is backedge;
	}
//printf("\n %d matrix -- matrix v %d ",mmatrix[l][i],mmatrix[v][i]);

}
return 0; // no backedge;
}


int allcutvertex(int node)
{
int i,j,k;
struct linklist *head=NULL,*tail=NULL;

for(i=0;i<n;i++)
{
if(i==node)
{
	k=cutnode(node);
	if(k==0)
	{
	pushfirst(&head,&tail,node);
	}
}
else
{
        k= cutv(i);
        if(k==0)
	{
	pushfirst(&head,&tail,i);
	}
}
}
printf("\n cutvertices of the graph are");
print(&head);

/*

// k= cutv(0);
//printf("\n checking 0 - - %d",k);
printf("\n enter the cut vertices and see disconnected graph in new file");
scanf("\n %d",&k);
/*
while(isempty(&head)) // see graph by removing all disconnected components
{
k=poptop(&head);
for(i=0;i<n;i++)
{
mmatrix[k][i]=0;
mmatrix[i][k]=0;
}



write();
*/

}

































