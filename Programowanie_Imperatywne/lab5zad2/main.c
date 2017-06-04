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
struct lstnode* newnode(int val, struct lstnode* prev, struct lstnode* next)
{
    struct lstnode* node = malloc(sizeof(struct lstnode));
    node->val=val;
    node->next=next;
    node->prev=prev;
    return node;
}

void push_front(struct twowaylist *list, int val);


void push_back(struct twowaylist *list, int val);

void print(struct twowaylist *list);
void clear(struct twowaylist *list);
void instantiate(struct twowaylist** lst)
{
    *lst = malloc(sizeof(struct twowaylist));
    (*lst)->guardianleft = newnode(0,NULL,NULL);
    (*lst)->guardianright = newnode(0,(*lst)->guardianleft,NULL);
    (*lst)->guardianleft->next=(*lst)->guardianright;
}
int main() {
   struct twowaylist* list;
    instantiate(&list);
    for(int i=0;i<10;i++)
    {
        push_front(list,i);
    }
    clear(list);
    for(int i=20;i<30;i++)
    {
        push_back(list,i);
    }
   print(list);
    return 0;
}

void print(struct twowaylist *list) {
    struct lstnode* next = list->guardianleft;
    while(next->next!=list->guardianright)
    {
        next=next->next;
        printf("%d, ",next->val);
    }
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