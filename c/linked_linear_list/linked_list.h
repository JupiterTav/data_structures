#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct list{
  int node;
  struct list *next;
}list;

list *search_list(list *l, int item);

void insert_list(list **l, int item);

void delete_from_list(list **l, int item);

list *predecessor_list(list *l, int item);

#endif
