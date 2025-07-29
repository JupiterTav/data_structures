#include "linked_list.h"
#include <stdio.h>

int main(){
  list *a;
  
  //TEST *insert_list* FUNCTION
  printf("*TESTING INSERT_LIST FUNCTION*\n");
  insert_list(&a, 7);
  printf("The head of list is %d.\n", a->node);
  printf("Inserting another element: 3\n");
  insert_list(&a, 3);
  printf("Now the head is %d.\n", a->node);

 //TEST *search_list* FUNCTION
  printf("\n*TESTING SEARCH LIST FUNCTION*\n");
  int searching = search_list(a,7)->node;
  printf("Item: %d was founded", searching);

  //TEST *delete_from_list* FUNCTION
  printf("\n*TESTING DELETE FROM LIST FUNCTION*\n");
  delete_from_list(&a, 7);
  printf("\nnew list: ");
  do{
    printf("%d ", a->node);
  }while(a->next != NULL);

  return 0;
}
