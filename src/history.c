#include "history.h"
#include <stdio.h>
#include <stdlib.h>

List *init_history()
{
  List *list = malloc(sizeof(List));
  list->root = NULL;
  return list;
}

short word_size(char *str)
{
  short size = 0;
  while (str[size] != '\0') {
    size++;
  }
  return size;
}

char *copy_all_word(char *str)
{
  short size = word_size(str);
  char *copy = malloc((size + 1) * sizeof(char));
  for (short i = 0; i < size; i++) {
    copy[i] = *str;
    str++;
  }
  copy[size] = '\0';
  return copy;
}

void add_history(List *list, char *str)
{
  int id = 1;
  Item *node = malloc(sizeof(Item));
  node->str = copy_all_word(str);
  node->next = NULL;
  if (list->root == NULL) {
    node->id = id;
    list->root = node;
  } else {
    Item *temp = list->root;
    while (temp->next != NULL) {
      id++;
      temp = temp->next;
    }
    id++;
    node->id = id;
    temp->next = node;
  }
}

void print_history(List *list)
{
  if (list->root == NULL) {
    printf("there is no history at this time\n");
  }else{
    Item *temp = list->root;
    while (temp != NULL){
      printf("id:%d %s", temp->id, temp->str);
      temp = temp->next;
    }
  }
}

char *get_history(List *list, int id)
{
  Item *temp = list->root;
  while (temp != NULL) {
    if (temp->id == id) {
      return temp->str;
    }
    temp = temp->next;
  }
  printf("could not find id\n");
  return '\0';
}
