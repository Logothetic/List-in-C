#include "Node.h"

void edit(struct list* mylst){

    int i,c;
    int op;
    int tmp;
    char* buff;
    struct node* pos;
    struct node* pre;

    printf("Give the id of the student that you want to edit : ");
    buff=getid();

    if(searchId(*mylst,buff,&pos,&pre)==1){
        printf("[1] Name\n");
        printf("[2] Id\n");
        printf("[3] Sem\n\n");
        printf("choose option : ");
        scanf("%d",&op);
        if(op==3){
            system("clear");
            printf("Give the new semester: ");
            scanf("%d",&tmp);
            pos->sem=tmp;
        }else if(op==2){
            system("clear");
            printf("Give the new id: ");
            buff=getid();
            pos->id=buff;
        }else if(op==1){
            system("clear");
            printf("Give the new name: ");
            buff=getname();
            pos->name=buff;
        }
    }else
        printf("No student with that id was found!\n");

}


void insert(struct list* mylst){

    struct node* add;
    struct node* pre;
    struct node* pos;

    add=newNode();
    if(mylst->head==NULL){
        mylst->head=add;
        add->next=NULL;
        add->prev=NULL;
        return;
    }

    if(searchId(*mylst,add->id,&pos,&pre)==1){
        printf("This id already exists!\n");
        return;
    }else{
        if(pre==NULL){
            add->next = mylst->head;
            mylst->head = add;
            add->next->prev = add;
        }
        else{
            add->next = pre->next;
            pre->next = add;
            add->prev = pre;
        }
    }
    free(pos);
}


void remove(struct list* lst,char id[]){

    struct node* pos;
    struct node* pre;
    if(searchId(*lst,id,&pos,&pre)==0){
        printf("The id you gave was not found!\n");
        return;
    }
    if(pre==NULL && pos->next!=NULL){
        lst->head=pos->next;
        pos->next->prev=NULL;
        free(pos);
    }else if(pre==NULL && pos->next==NULL){
        lst->head=NULL;
        free(pos);
    }else if(pos->next==NULL && pre!=NULL){
        pre->next=NULL;
        free(pos);
    }else{
        pre->next=pos->next;
        pos->next->prev=pre;
        free(pos);
    }
    printf("The student with id:%s was removed succesfully!",id);
}


int searchId(struct list lst, char item[], struct node **position, struct node **pre){

    struct node* tmp;
    int flag;

    tmp = lst.head;
    *pre = NULL;
    *position = NULL;
    flag = 0;

    while(tmp!=NULL && flag==0){
        if(strcmp(tmp->id,item)==0){
            flag = 1;
            *position = tmp;
        }else if(strcmp(item, tmp->id)<0)
            tmp=NULL;
        else{
            *pre=tmp;
            tmp=tmp->next;
        }
    }

    return flag;
}

int searchName(struct list lst, char item[], struct node **position, struct node **pre){

    struct node* tmp;
    int flag;

    tmp = lst.head;
    *pre = NULL;
    *position = NULL;
    flag = 0;

    while(tmp!=NULL && flag==0){
        if(strcmp(tmp->name,item)==0){
            flag = 1;
            *position = tmp;
        }else if(strcmp(item, tmp->name)<0)
            tmp=NULL;
        else{
            *pre=tmp;
            tmp=tmp->next;
        }
    }

    return flag;
}


struct node* newNode(){

    int i=0;
    int s;
    char c;
    char* buff;
    struct node* tmp;

    tmp=(struct node*)malloc(sizeof(struct node));
    if(tmp==NULL){
        printf("Not enough space!\n");
        exit(1);
    }

    tmp->id=(char*)malloc(sizeof(char)*12);
    if(tmp->id==NULL){
        printf("Not enough space!\n");
        exit(1);
    }

    tmp->name=(char*)malloc(sizeof(char)*51);
    if(tmp->name==NULL){
        printf("Not enough space!\n");
        exit(1);
    }

    printf("Give name : ");
    buff=getname();
    strcpy(tmp->name,buff);

    printf("Give id : ");
    while((c = getchar()) != '\n' && i < 11 ){
        tmp->id[i] = c;
        i++;
    }
    tmp->id[i]='\0';

    printf("Give semester : ");
    do{
        scanf("%d",&s);
    }while(s<1);
    tmp->sem=s;
    tmp->next = NULL;
    tmp->prev = NULL;

    return tmp;
}

void Clear(){  while(getchar()!='\n'); }


char* getname(){

    char* name_buff;

    name_buff=(char*)malloc(sizeof(char)*51);
//     printf("Give name : ");
    Clear();
    fgets(name_buff,50,stdin);

    return name_buff;
}

char* getid(){

    int i,c;
    char* id_buff;

    id_buff=(char*)malloc(sizeof(char)*12);
//     printf("Give id : ");
    Clear();
    i=0;
    while((c = getchar()) != '\n' && i < 11 ){
        id_buff[i] = c;
        i++;
    }
    id_buff[i]='\0';

    return id_buff;
}
