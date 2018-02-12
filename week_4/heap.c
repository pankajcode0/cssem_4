#include<stdio.h>


int newHeap();
int insertHeap(int data);
int deleteMin();
int heapsort();
int printHeap();
int printHeapchart();
int minheapify(int i);
int minimum(int child1,int child2);

int heapsize=-1;
int heap[200];
int main()
{
int n=0,data,min;
/*
insertHeap(4);
insertHeap(6);
insertHeap(3);
insertHeap(1);
printf("\n heapsize %d",heapsize);
printHeap();
min=deleteMin();
printf("\n min-%d",min);
printHeap();
min=deleteMin();
printf("\n min-%d",min);
min=deleteMin();
printf("\n min-%d",min);

*/
while(n!=6)
{
	printf("\n enter your choice");
	printf("\n 1 build a heap");
	printf("\n 2 insert an element");
	printf("\n 3 delete the minimum element");
	printf("\n 4 heap sort");
	printf("\n 5 print heap");
	printf("\n 6 end programme");
    printf("\n 7 print heaparray");

	scanf("%d",&n);

	switch(n)
	{
	case 1:newHeap();
		break;
	case 2: printf("\n give data input");
		scanf("%d",&data);
		insertHeap(data);	
		break;
	case 3:deleteMin();	
		break;
	case 4:heapsort();	
		break;
	case 5:printHeap();
	//print2D(0 ,heap ,heapsize);
		break;
	case 6:break;
	case 7:printHeaparray();
       
	default: printf("\n invalid choice");

	}
}//*/
}
int printHeaparray()
{
	int i;
	for(i=0;i<=heapsize;i++)
	{
		printf("\n%d",heap[i]);
	}
}
int newHeap()
{
int i,data,n;
printf("\n input the heap size");
scanf("%d",&n);
heapsize=n-1;

printf("\n input the heap element");
for(i=0;i<n;i++)
{
scanf("%d",&heap[i]);
}
for(i=n/2;i>=0;i--)
{
	minheapify(i);
}
}

int insertHeap(int data)
{
heapsize=heapsize+1;
	if(heapsize==0)
	{
	heap[0]=data;
        return 0;
	}
	else
	{
		heap[heapsize]=data;

		int redflag=0,k,h=heapsize,temp;

		while(redflag==0)
		{
			k=((h+1)/2)-1;
			if(heap[h]<heap[k])
			{
				temp=heap[h];
				heap[h]=heap[k];
				heap[k]=temp;
				h=k;
			}
			else
			{
				redflag==0;
                                 return 0;
			}
			if(h==0)
			{
				redflag==0;
                                return 0;
			}
		}

	}
}

int printHeap()
{
int i;
int n=(heapsize+1)/2;
printf("\n");
int h=getheight(heapsize+1);
for(i=2;i<=h;i++)
{
//printspace(h-i);
printdata(i);
printf("\n");
}

return 0;
}

void printspace(int k)
{int i;
	for(i=0;i<k;i++)
	{
		printf("* ");
	}
	//printf("*");
}

void printdata(int k)
{
	int i;
	int n=getpower(k);
	for(i=k+1;i<=n+k;i++)
	{
		printf("  %d",heap[i]);
	}
}
int getpower(int k)
{int i,n=1;
	for(i=0;i<k;i++)
	{
      n=n*2;
	}
	return n;
}

int deleteMin()
{
int min,redflag=0,child1=1,child2=2,child,temp;
min=heap[0];
heap[0]=heap[heapsize];
heapsize=heapsize-1;
int h=0;

                 while(redflag==0)
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
                          redflag=0;
                           return min;
                        }
                  
			if(heap[h]>heap[child])
			{
				temp=heap[h];
				heap[h]=heap[child];
				heap[child]=temp;
				h=child;
			}
			else
			{
				redflag==0;
                                 return min;
			}
			
		}



return min;
}


int heapsort()
{
int min;
printf("\n printing sortedlist");
while(heapsize>=0)
{
min=deleteMin();
printf("\n %d",min);
}
return 0;
}

int minimum(int child1,int child2)
{
	if(heap[child1]<heap[child2])
	{
	return child1;
	}
	else
	return child2;
}


int minheapify(int i)
{
	int l,r,min1,min2,temp,k1,k2,min;

int child1,child2,child;
	
	child1=2*i+1;
		     child2=2*i+2;
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
                  
			if(heap[i]>heap[child])
			{
				temp=heap[i];
				heap[i]=heap[child];
				heap[child]=temp;
				minheapify(child);
				printHeap();
			}
		printf("\n");
}

int getheight(int k)
{
	int i=1,j=1;
	while(i<=k)
	{
		i=i*2;
		j++;
	}

	return j;
}













