#include <stdio.h>
#include <stdlib.h>
#include "history.h"


// Create linked list for history
List* init_history() {
  List *list = (List*) malloc(sizeof(List));
  if (list) {
    list->root = NULL;
  }
  return list;
}

void add_history(List *list, char *str) {
  Item *new_item = (Item*) malloc(sizeof(Item));
  newItem->str = str;
  newItem->next = NULL;
