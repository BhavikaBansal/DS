#include<stdio.h>
#include<stdlib.h>
//#include<iostream>
//susing namespace std;
//linked list
 typedef struct node
{
    int data;
    struct node *next;
}node;
void insertAtEnd(int num, struct node **head)
{
   // node *temp=new node;
   struct node *temp= (struct Node*) malloc(sizeof(node));
    temp->data=num;
    if(*head==NULL)
    {
        temp->next=NULL;
        *head=temp;
    }
    else{
        struct node *ptr=*head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
        temp->next=NULL;
    }

//cout<<num<<endl;

}
void display(struct node *head)
{
   // cout<<"hi";
    struct node *ptr;
    ptr=head;
    //cout<<ptr->data;
    //cout<<ptr->next;
    while(ptr!=NULL)
    {
        //cout<<"haww";
       // cout<<ptr->data;
       printf(" %d",ptr->data);
        ptr=ptr->next;
    }
}
int main()
{

    int num;
    struct node *head= NULL;
   // cin>>num;
    scanf("%d",&num);
    while(num!=-1)
    {
        insertAtEnd(num,&head);
        //cin>>num;
        scanf("%d",&num);
    }
    display(head);
    return 0;
}
