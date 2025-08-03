#include "linked_list.h"
#include <stdio.h>
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
  list *p = (list *) malloc(sizeof(list));

  p->node = item;
  p->next = *l;
  *l = p;
}
void insert_list_end(list **l, int item){
  list *p = (list *) malloc(sizeof(list));
  list *p2 = (list *) malloc(sizeof(list));

  if(p != NULL && p2 != NULL){
    p->node = item;
    p->next = NULL;
    
    if(*l == NULL)
      *l = p;
    else {
      p2 = *l;
      while(p2->next != NULL){
        p2 = p2->next;
      }
      p2->next = p;
    }
  }
}

void insert_list_pos(list **l, int item, int pos){
  list *p = (list *)malloc(sizeof(list));
  list *p_aux;
  if(p != NULL){
    if((*l == NULL) && (pos != 1) || pos < 1)
      free(p);
    else if( pos == 1){
      p->node = item;
      p->next = *l;
      *l = p;
    }
    else {
      p_aux = *l;
      while(p_aux->next != NULL && pos > 2){
        p_aux = p_aux->next;
        pos--;
      }
      if( pos > 2)
        free(p);
      else{
        p->node    = item;
        p->next    = p_aux->next;
        p_aux->next = p;
      }
    }
  }
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
  list *p = (list *) malloc(sizeof(list));
  list *pred;
  
  p = search_list(*l, item);
  if(p != NULL){
    pred = predecessor_list(*l, item);
    if(pred == NULL){
      list *temp = *l;
      *l = temp->next;
    }
    else
      pred->next = p->next;
    free(p);
  }
}

void delete_from_list_by_position(list **l, int pos){
  list *p = *l;
  list *pred = NULL;
  
  while(p != NULL && pos > 1){
    pos--;
    pred = p;
    p = p->next;
  }
  if(p != NULL){
    if(p == *l){
      list *temp = *l;
      *l = temp->next;
    }
    else 
      pred->next = p->next;
    free(p);
  }
}

void delete_list(list **l){
  list *p;
  while(*l != NULL){
    p = *l;
    *l = p->next;
    free(p);
  }
  free(*l);
  printf("list destroyed");
}

void show_list(list *l){
  printf("list: ");
  while(l != NULL){
    printf("%d ", l->node);
    l = l->next;
  }
}
