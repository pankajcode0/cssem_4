/* i will use this as linklist library for other codes

it is a doubly link-list with both side root so it can be used as stack/queue/or circular queue

operations permited
adding nodes at top.
deleting nodes from top as well as from bottom.
printing top and printing  bottom , by poping or deleting.

printing all data without deleting anything from top or reverse both.
getsize- return size of the list

.


isempty- check whether its empty or not.
*/

//  
// name of the structure - linklist





struct linklist
{
int data;
struct linklist *next;
struct linklist *prev;
};

int isempty(struct linklist **head);
void pushfirst(struct linklist **head,struct linklist **tail,int newdata);
void addtail(struct linklist **head,struct linklist **tail);
void pushlast(struct linklist **tail,struct linklist **head,int newdata);
int size(struct linklist **head);
int searchpos(struct linklist **head, int data);
void pushmid(struct linklist **head, int newdata, int pos);
void print(struct linklist **head);
int poptop(struct linklist **head);
int poplast(struct linklist **tail,struct linklist **head);
int popmid(struct linklist **head,int pos);
void printrev(struct linklist **tail);


void addtail(struct linklist **head,struct linklist **tail)
{
struct linklist *temp=NULL,*temp2=NULL;
temp=*head;

do
{

temp=(temp)->next;

}while((temp->next)!=NULL);

*tail=temp;

}


int isempty(struct linklist **head)
{
	if(*head==NULL)
	{
	return 0;
	}
	else
	{
        return 1;
	}
}

void pushfirst(struct linklist **head,struct linklist **tail,int newdata)
{
	struct linklist *temp1=NULL,*temp2=NULL;
	struct linklist *newnode=NULL;
        newnode = (struct linklist*) malloc(sizeof(struct linklist));
	newnode->data=newdata;
	newnode->next=NULL;
	newnode->prev=NULL;
        temp1=*head;
	temp2=*head;

	if(*head==NULL)
	{
	*head=newnode;
         *tail=newnode;
	}

	else
	{
	
	newnode->next=*head;
        temp1->prev=newnode;
	*head=newnode;
	}

}

void pushlast(struct linklist **tail,struct linklist **head,int newdata)
{
  struct linklist *temp1=NULL,*temp2=NULL;
	struct linklist *newnode=NULL;
        newnode = (struct linklist*) malloc(sizeof(struct linklist));
	newnode->data=newdata;
	newnode->next=NULL;
	newnode->prev=NULL;
        temp1=*tail;
	temp2=*tail;

	if(*tail==NULL)
	{
	*tail=newnode;
	*head=newnode;
       
	}

	else
	{
	 temp1->next=newnode;
	newnode->prev=temp1;
       
	*tail=newnode;
	}   


}

int size(struct linklist **head)
{
struct linklist *temp=NULL;
temp=*head;
int count=0;
while((temp->next)!=NULL)
{
temp=temp->next;
count++;
}
if(temp!=NULL)
{
count++;
}
return count;
}

int searchpos(struct linklist **head, int data)
{
	struct linklist *temp=NULL;
	temp=*head;
	int n=size(head);
	int i=0;
	while(i<n)
	{
	i++;
	if(data==temp->data)
	{
	return i;
	}
	temp=temp->next;
	}
return -1;
}
void pushmid(struct linklist **head, int newdata, int pos)
{

struct linklist *temp1=NULL,*temp2=NULL,*newnode=NULL,*temp3=NULL;
int i,j,n=1;
 newnode = (struct linklist*) malloc(sizeof(struct linklist));
	newnode->data=newdata;
	newnode->next=NULL;
	newnode->prev=NULL;
temp1=*head;

while(n!=pos-1)
{
n++;
temp1=temp1->next;

}
temp2=temp1;
temp1=temp1->next;
temp2->next=newnode;
newnode->prev=temp1->prev;
newnode->next=temp1;
temp1->prev=newnode;

}

void print(struct linklist **head)
{
struct linklist *temp1=NULL;
temp1=*head;
while((temp1->next)!=NULL)
{
printf("\n %d ",temp1->data);
temp1=temp1->next;
}
printf("\n %d ",temp1->data);
}

int poptop(struct linklist **head)
{
int s=isempty(head);
if(s==0)
{
return -1;
}
int siz=size(head);
struct linklist *temp=NULL;
temp=*head;
int k=temp->data;
if(siz>1)
{
*head=(*head)->next;
(*head)->prev=NULL;
temp->next=NULL;

}
else
{
*head=NULL;
}
return k;
}

int poplast(struct linklist **tail, struct linklist **head)
{


struct linklist *temp=NULL,*temp1=NULL;
temp=*tail;
temp1=*tail;
int k=temp->data;
int siz=size(head);
if(siz==0)
{
	return -1;
}
if(siz==1)
{
*tail=NULL;
*head=NULL;
}
else
{
temp1=temp1->prev;
temp1->next=NULL;
*tail=(*tail)->prev;
(*tail)->next=NULL;
}


return k;
}

int popmid(struct linklist **head,int pos)
{
struct linklist *temp1=NULL,*temp2=NULL,*temp3=NULL;
temp1=*head;
int n=1,k;
while(n!=pos)
{
n++;
temp1=temp1->next;
}
temp2=temp1->prev;
temp3=temp1->next;

temp2->next=temp3;
temp3->prev=temp2;
temp1->next=NULL;
temp1->prev=NULL;
k=temp1->data;
free(temp1);
return k;
}
void printrev(struct linklist **tail)
{
struct linklist *temp1=NULL;
temp1=*tail;
while(((temp1)->prev)!=NULL)
{

printf("\n %d",(temp1)->data);
temp1=(temp1)->prev;
}
printf("\n  %d",(temp1)->data);

}






