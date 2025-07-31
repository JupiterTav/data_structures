#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct list{
  int node;
  struct list *next;
}list;

list *search_list(list *l, int item);

void insert_list(list **l, int item);
void insert_list_end(list **l, int item);
void insert_list_pos(list **l, int item, int pos);

void delete_from_list(list **l, int item);
void delete_from_list_by_position(list **l, int pos);

list *predecessor_list(list *l, int item);

void show_list(list *l);

#endif
