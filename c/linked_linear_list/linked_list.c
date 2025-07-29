#include "linked_list.h"
#include <stdlib.h>

//recursively method to search an item in a list l
list *search_list(list *l, int item){
  if(l == NULL)
    return NULL;
  if(l->node == item)
    return l;
  else 
    return search_list(l->next, item);
}

//search list done iteratively
/*list *search_list(list *l, int item){
  while(l->node != item){
   l = l->next;
  }
  return l;
}*/

void insert_list(list **l, int item){
  list *p;

  p = malloc(sizeof(list));
  p->node = item;
  p->next = *l;
  *l = p;
}

list *predecessor_list(list *l, int item){
  if((l == NULL) || (l->next == NULL))
    return NULL;
  if((l->next)->node == item)
    return l;
  else 
    return predecessor_list(l->next, item);
}

void delete_from_list(list **l, int item){
  list *p;
  list *pred;
  
  p = search_list(*l, item);
  if(p != NULL){
    pred = predecessor_list(*l, item);
    if(pred == NULL)
        *l = p->next;
    else
      pred->next = p->next;
    free(p);
  }
}
