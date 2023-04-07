#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include <stdio.h>

struct list{
  struct node* head;
};

void init(struct list*);

void printList(struct list);

#endif
