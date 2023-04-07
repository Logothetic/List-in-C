#include "Node.h"
#include "List.h"
#include <stdio.h>

void clear();
void menu(struct list*);
char* getName();
char* getId();

int main(int argc,char **argv){

    struct list MyList;

    menu(&MyList);

    return 0;
}

void clear(){ while(getchar()!='\n'); }

void menu(struct list* mylst){
    int op,ch,c,i;
    char* name_buff;
    char* id_buff;
    struct node* pos;
    struct node* pre;

    init(mylst);

    do{
        system("clear");
        printf("::::::::MENU::::::::\n\n");
        printf("[1] Add new student\n");
        printf("[2] Remove student\n");
        printf("[3] Edit student\n");
        printf("[4] Search by ID\n");
        printf("[5] Search by name\n");
        printf("[6] Print list\n");
        printf("[7] E X I T\n\n");
        printf("choose option : ");
        scanf("%d",&op);
        system("clear");
        switch(op){
            case 1: insert(mylst);break;

            case 2: id_buff=getId();
                    remove(mylst,id_buff);
                    free(id_buff);
                    break;
            case 3: edit(mylst);break;

            case 4: id_buff=getId();
                    if(searchId(*mylst,id_buff,&pos,&pre)==1){
                        printf("id=%s\nname=%ssem=%d\n\n",pos->id,pos->name,pos->sem);
                    }else{
                        printf("Not Found\n");
                    }
                    free(id_buff);
                    break;

            case 5: name_buff=getName();
                    if(searchName(*mylst,name_buff,&pos,&pre)==1){
                        printf("id=%s\nname=%ssem=%d\n\n",pos->id,pos->name,pos->sem);
                    }else{
                        printf("Not Found\n");
                    }
                    free(name_buff);
                    break;

            case 6: printList(*mylst);break;

            case 7: return;
        }
        clear();
//         ch=getchar();
    }while(1);

}

char* getName(){

    char* name_buff;

    name_buff=(char*)malloc(sizeof(char)*51);
    printf("Give name : ");
    clear();
    fgets(name_buff,50,stdin);

    return name_buff;
}

char* getId(){

    int i,c;
    char* id_buff;

    id_buff=(char*)malloc(sizeof(char)*12);
    printf("Give id : ");
    clear();
    i=0;
    while((c = getchar()) != '\n' && i < 11 ){
        id_buff[i] = c;
        i++;
    }
    id_buff[i]='\0';

    return id_buff;
}
