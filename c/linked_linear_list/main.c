#include "linked_list.h"
#include <stdio.h>

void menu();
void show_list(list *l);

int main(){
  list *a = NULL;
  int op;
  do{
    menu();
    printf("Insert an option: ");
    scanf("%d", &op);
    int x;
    switch (op) {
      case 1:
        printf("Element to insert: ");
        scanf("%d", &x);
        insert_list(&a, x);
      break;
      case 2:
        printf("\nElement to search: ");
        scanf("%d", &x);
        list *searching = search_list(a, x);
        if(searching != NULL)
          printf("%d was found\n", searching->node);
        else
          printf("element not found\n");
        break;
      case 3:
        printf("\nElement to delete: ");
        scanf("%d", &x);
        delete_from_list(&a, x);
    }
    show_list(a);
  }while(op != 0);
  return 0;
}

void menu(){
  int op; 
  printf("\n1 - insert an element\n");
  printf("2 - search an element\n");
  printf("3 - delete an element\n");
  printf("0 - quit\n");
}

