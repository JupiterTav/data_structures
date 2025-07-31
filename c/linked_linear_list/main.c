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
    int p;
    switch (op) {
      case 1:
        printf("Element to insert: ");
        scanf("%d", &x);
        insert_list(&a, x);
      break;
      case 2:
        printf("Element to insert: ");
        scanf("%d", &x);
        insert_list_end(&a, x);
      break;
      case 3:
        printf("Element and position to insert: ");;
        scanf("%d %d", &x, &p);
        insert_list_pos(&a, x, p);
      break;
      case 4:
        printf("\nElement to search: ");
        scanf("%d", &x);
        list *searching = search_list(a, x);
        if(searching != NULL)
          printf("%d was found\n", searching->node);
        else
          printf("element not found\n");
        break;
      case 5:
        printf("\nElement to delete: ");
        scanf("%d", &x);
        delete_from_list(&a, x);
        break;
      case 6:
        printf("\nElement position to delete: ");
        scanf("%d", &p);
        delete_from_list_by_position(&a, p);
    }
    show_list(a);
  }while(op != 0);
  return 0;
}

void menu(){
  int op; 
  printf("\n1 - insert an element at head\n");
  printf("2 - insert an element at tail\n");
  printf("3 - insert an element at p position\n");
  printf("4 - search an element\n");
  printf("5 - delete an element\n");
  printf("6 - delete an element by position\n");
  printf("0 - quit\n");
}

