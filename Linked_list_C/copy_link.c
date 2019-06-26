#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node * next;
}node;
node * create()
{
    node* temp = (node *) malloc(sizeof(node));

    //temp->data = d;
    temp ->next = NULL;
    return temp;
}
void insert(struct node **h, int d){
    struct node *temp = create();
    temp->data = d;
    if(*h == NULL)
    {
       // *h = create();
        *h = temp;
    }
    else{
        struct node* ptr = *h;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = temp;

    }
}

void print(struct node *h){
    while(h != NULL){
        printf("%d ",h->data);
        h = h->next;
    }
    printf("\n");
}
node * clone(node * h){
    if(h == NULL)  return;
    struct node *head2 = create();
    head2->data = h->data;


    head2->next = clone(h ->next);
    return head2;

}
void reverse( struct node** h){
    struct node* curr = *h;
    struct node *pre = NULL;
    struct nnode*next = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
    }


}
void Reverse(node** h){
    node *curr = *h;
    node *pre = NULL;
    node* next = NULL ;
    while(curr != NULL){
        next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
    }
    (*h) = pre;
}
/*node * clone(node **h){
    if(*h == NULL)  return;
    struct node *head2 = create();
    head2->data = (*h)->data;
    printf("%d \n" ,*h);
    head2->next = clone((*h) ->next);
    return head2;
2
}*/
int Compare(node* a, node* b ){
    while(a != NULL && b != NULL){
        if(a->data != b->data){
            return 0;
        }
        a = a->next;
        b = b->next;
    }

    return 1;
}
int main()
{
int n, i, d, r;
 scanf("%d",&n);
 struct node *h = NULL;
for( i = 0; i < n; i++){
    scanf("%d",&d);
    insert (&h, d);
}
print(h);
struct node * h2 = clone(h);
print(h2);
Reverse(&h);
print(h);
r = Compare(h, h2);

printf("%d ",r);
return 0;
}
