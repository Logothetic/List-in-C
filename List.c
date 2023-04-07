#include "List.h"

void init(struct list* l){
    l->head=NULL;
}

void printList(struct list l){

    struct node* tmp;
    int a,ch;

    printf("Which semester do you want to print (0 for all) : ");
    scanf("%d",&a);
    tmp=l.head;
    if(a==0){
        while(tmp!=NULL){
            printf("id=%s\nname=%ssem=%d\n\n",tmp->id,tmp->name,tmp->sem);
            tmp=tmp->next;
        }
    }else
        while(tmp!=NULL){
            if(tmp->sem==a)
                printf("id=%s\nname=%ssem=%d\n\n",tmp->id,tmp->name,tmp->sem);
                tmp=tmp->next;
        }
     ch=getchar();
}
