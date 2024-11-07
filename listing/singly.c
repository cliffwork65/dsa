#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
int data;
struct node *link;
}*start=NULL;

void create()
{
char ch='y';
while(ch=='y' || ch=='Y'){

  struct node *temp,*p;

  temp=(struct node *)malloc(sizeof(struct node));

  printf("\nEnter the data : ");
  scanf("%d",&temp->data);
  temp->link=NULL;

  if(start==NULL)
  {
  start=temp;
  p=temp;
  }
  else
  {
  p->link=temp;
  p=temp;
  }
  printf("\nDo you want to create another node ?(Press y): ");
  scanf("\n%c",&ch);  
 }
}

void count_node()
{
struct node *temp;
int count=0;
temp=start;
 while(temp!=NULL)
   {
   count=count + 1;
   temp=temp->link;
   }
 printf("\nNo. of nodes in the list = %d\n", count);
}

void insert_begin()
{
  struct node *temp,*p;

  temp=(struct node *)malloc(sizeof(struct node));

  printf("\nEnter the data For First Position : ");
  scanf("%d",&temp->data);
  temp->link=NULL;

  if(start==NULL)
  {
  start=temp;
  p=temp;
  }
  else
  {
  temp->link=start;
  start=temp;
  p=temp;
  }
}


void insert_last()
{
  struct node *temp,*p;

  temp=(struct node *)malloc(sizeof(struct node));

  printf("\nEnter the data For Last Position : ");
  scanf("%d",&temp->data);
  temp->link=NULL;

  if(start==NULL)
  {
  start=temp;
  p=temp;
  }
  else
  {
  p=start;
  while(p->link!=NULL)
     {
        p = p->link;
     }
        p->link = temp;
  }
}

void insert_middle()
{
  struct node *temp,*p;
  int pos,i;
  int count=0;
   p=start;
   while(p!=NULL)
   {
   count=count + 1;
   p=p->link;
   }
 printf("\nEnter the position : ");
 scanf("%d",&pos);
 if(pos<=count+1)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter the data For this Position : ");
        scanf("%d",&temp->data);
        temp->link=NULL;
         if(start==NULL)
     {
         start=temp;
         p=temp;
     }
    else
     {
         p=start;
            for(i=1;i< pos-1;i++)
            {
                p = p->link;
            }
                temp->link = p->link ;
                p->link =temp;
     }
       printf("\nAfter add data in this Position :");
       display();
    }
 else
    {
        printf("\nPosition is not found in the list");
    }  
}

void delete_first()
{
   
    struct node *temp;
    if(start == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        temp = start;
        start = temp->link;
        printf("\nData deleted = %d\n", temp->data);
        free(temp);
        printf("\nSUCCESSFULLY DELETED ANY NODE FROM LIST\n");
    }
}

void delete_last()
{
    struct node *temp,*t;

    if(start == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        temp = start;
        while(temp->link != NULL)
         {
             t=temp;
             temp=temp->link;
         }
        printf("\nData deleted = %d\n", temp->data);
        free(temp);
        t->link=NULL;
        printf("\nSUCCESSFULLY DELETED Last NODE FROM LIST\n");
    }
}

void delete_middle()
{
    int pos,i;
    struct node *prev,*curr;
    printf("\nEnter the position : ");
    scanf("%d",&pos);
    if(start == NULL)
    {
        printf("List is already empty.");
    }
   else
   {
        prev=NULL;
        curr= start;
        for(i=1;i<= pos-1;i++)
            {
                prev=curr;
                curr = curr->link;
            }
        free(curr);  
        prev->link=curr->link;
        printf("\nSUCCESSFULLY DELETED Last NODE FROM LIST\n");
    }
}
void search_element()
{
    int ele,flag=0,count=0;
    printf("\nEnter the element to be search : ");
    scanf("%d",&ele);
    struct node *temp;
   
    if(start == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        temp = start;
        while(temp->link != NULL)
         {
             count=count + 1;
             if(temp->data == ele)
                {
                 flag=1;
                 break;
                }
             temp=temp->link;
         }
         if(flag==1){
            printf("Element %d is found in %d position", temp->data,count);
         }
         else{
             printf("Element is not found");
         }
       
    }
}



void display()
{
struct node *p;
   printf("The Linked List : ");
    p=start;
     while(p!=NULL)
       {
           printf("%d--->",p->data);
           p=p->link;
       }
       printf("NULL\n");

}
int main()
{
    int ch;
   
    while(1){
        printf("Press 1 : For create a list\n");
        printf("Press 2 : For display a list\n");
        printf("Press 3 : For insert beginning a list\n");
        printf("Press 4 : For insert last a list\n");
        printf("Press 5 : For count total node from a list\n");
        printf("Press 6 : For delete beginning a list\n");
        printf("Press 7 : For delete last a list\n");
        printf("Press 8 : For delete last a list\n");
        printf("Press 9 : For insert middle a list\n");
        printf("Press 10 : For delete middle a list\n");
        printf("Press 11 : End Program\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : create();
                     break;
            case 2 : display();
                     break;
            case 3 : insert_begin();
                     break;
            case 4 : insert_last();
                     break;
            case 5 : count_node();
                     break;  
            case 6 : delete_first();
                     break;
            case 7 : delete_last();
                     break;
            case 8 : search_element();
                     break;  
            case 9 : insert_middle();
                     break;
            case 10 : delete_middle();
                     break;          
            case 11 : exit(0);
            default :printf("Wrong choice");
        }
    }
}