#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "List.h"
struct node {
    int sem;
    char* id;
    char* name;
    struct node* next;
    struct node* prev;
};

struct node* newNode();

int searchId(struct list ,char[],struct node**,struct node**);

int searchName(struct list ,char[],struct node**,struct node**);

void insert(struct list*);

void remove(struct list*,char[]);

void edit(struct list*);

char* getname();

char* getid();

void Clear();

#endif
