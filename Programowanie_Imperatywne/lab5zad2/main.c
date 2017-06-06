#include <stdio.h>
#include <malloc.h>

struct lstnode{
    struct lstnode*next;
    struct lstnode*prev;
    int val;
};
struct twowaylist{
    struct lstnode* guardianleft;
    struct lstnode* guardianright;
};


struct lstnode* newnode(int val, struct lstnode* prev, struct lstnode* next);
void push_front(struct twowaylist *list, int val);
void push_back(struct twowaylist *list, int val);
void instantiate(struct twowaylist** lst);
void print(struct twowaylist *list);
void clear(struct twowaylist **list);
int size(struct twowaylist *list);
int empty(struct twowaylist *list);
int front(struct twowaylist * list);
int back(struct twowaylist * list);
void pop_front(struct twowaylist * list);
void pop_back(struct twowaylist * list);
void lstremove(struct twowaylist ** list,int val);

int main() {

    struct twowaylist* list;
    instantiate(&list);

    printf("pusta, rozmiar %d: ", size(list));
    print(list);

    for(int i=0;i<10;i++)
    {
        push_front(list,i);
    }

    printf("\npo push front:\n");
    print(list);

    printf("pusta: ");
    clear(&list);
    print(list);

    for(int i=20;i<30;i++)
    {
        push_back(list,i);
    }

    printf("\npo push back:\n");

    print(list);
    printf("\npierwszy: %d",front(list));
    printf("\nostatni: %d",back(list));
    printf("\npopfront:\n");
    pop_front(list);
    print(list);
    printf("\npopback:\n");
    pop_back(list);
    print(list);
    printf("\nreseting list:\n");
    clear(&list);
    for(int j=0;j<10;j++)
    {
        for(int i=1;i<4;i++)
        {
            push_front(list,i);
        }
    }
    print(list);
    printf("\nremoving twos:\n");
    lstremove(&list,2);
    print(list);
    return 0;
}



void lstremove(struct twowaylist ** list,int val)
{
    struct twowaylist* list2;
    instantiate(&list2);
    while(!empty(*list))
    {
       int i= front(*list);
        pop_front(*list);
        if(i!=val)
        {
            push_back(list2,i);
        }
    }
    clear(list);
    (*list)=list2;
}
void pop_back(struct twowaylist * list)
{
    if(empty(list)) return;
    struct lstnode* toremove=list->guardianright->prev;
    list->guardianright->prev=toremove->prev;
    toremove->prev->next=list->guardianright;
    free(toremove);
}
void pop_front(struct twowaylist * list)
{
    if(empty(list)) return;
    struct lstnode* toremove=list->guardianleft->next;
    list->guardianleft->next=toremove->next;
    toremove->next->prev=list->guardianleft;
    free(toremove);
}
int front(struct twowaylist * list)
{
    if(empty(list)) return -1;
    else return list->guardianleft->next->val;
}
int back(struct twowaylist * list)
{
    if(empty(list)) return -1;
    else return list->guardianright->prev->val;
}
int empty(struct twowaylist *list)
{
    return size(list)==0;
}
int size(struct twowaylist *list)
{ int s=0;
    struct lstnode* next = list->guardianleft;
    while(next->next!=list->guardianright)
    {
        next=next->next;
       s++;
    }
    return s;
}
void print(struct twowaylist *list) {
    struct lstnode* next = list->guardianleft;
    while(next->next!=list->guardianright)
    {
        next=next->next;
        printf("%d, ",next->val);
    }
}
void clear(struct twowaylist** list)
{
    struct lstnode* next=(*list)->guardianleft->next;
    struct lstnode* todelete;
    while(next!=(*list)->guardianright)
    {
        todelete=next;
        next=next->next;
        free(todelete);
    }
    (*list)->guardianright->next=NULL;
    (*list)->guardianleft->prev=NULL;
    (*list)->guardianleft->next=(*list)->guardianright;
    (*list)->guardianright->prev=(*list)->guardianleft;
}
struct lstnode* newnode(int val, struct lstnode* prev, struct lstnode* next)
{
    struct lstnode* node = malloc(sizeof(struct lstnode));
    node->val=val;
    node->next=next;
    node->prev=prev;
    return node;
}

void instantiate(struct twowaylist** lst)
{
    *lst = malloc(sizeof(struct twowaylist));
    (*lst)->guardianleft = newnode(0,NULL,NULL);
    (*lst)->guardianright = newnode(0,(*lst)->guardianleft,NULL);
    (*lst)->guardianleft->next=(*lst)->guardianright;
}
void push_front(struct twowaylist *list, int val) {
struct lstnode* firstelement = list->guardianleft->next;
    list->guardianleft->next=newnode(val,list->guardianleft,firstelement);
    firstelement->prev=list->guardianleft->next;
}
void push_back(struct twowaylist *list, int val) {
    struct lstnode* last = list->guardianright->prev;
    list->guardianright->prev=newnode(val,last,list->guardianright);
    last->next=list->guardianright->prev;
}