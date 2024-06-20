#include "history.h"
#include <stdio.h>
#include <stdlib.h>

List *init_history()
{
  List *list = malloc(sizeof(List));
  list->root = NULL;
  return list;
}

void add_history(List *list, char *str)
{
  if(list->root == NULL) {
    Item *node = malloc(sizeof(Item));
    node->id = 1;
    node->str = str;
    node->next = NULL;
    list->root = node;
  }else{
    Item *temp = list->root;
    char size = 1;
    while (temp->next != NULL) {
      temp = temp->next;
      size++;
    }
    Item *node = malloc(sizeof(Item));
    node->id = size;
    node->str = str;
    node->next = NULL;
    temp->next = node;
  }
}

void print_history(List *list)
{
  if (list->root == NULL) {
    printf("there is no history at this time\n");
  }else{
    Item *temp = list->root;
    printf("id:%p", temp);
    while (temp != NULL){
      printf("id:%d %s", temp->id, *temp->str);
      temp = temp->next;
    }
    printf("id:%d %s", temp->id, *temp->str);
  }
}
