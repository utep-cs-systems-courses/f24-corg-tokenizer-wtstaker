#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

// Initialize the linked list
List* init_history() {
  List *list = (List*)malloc(sizeof(List));  //allocate memory for the list
  list->root = NULL;
  return list;
}

//Add a history item to the list
void add_history(List *list, char *str) {
  int pos = 1;
  Item *tmp = list->root;

  // Traverse to the end of the list to find the position and insert a new item
  if (tmp != NULL) {
    while (tmp->next != NULL) {
      tmp = tmp->next;
      pos++;
    }
    tmp->next = malloc(sizeof(Item));  // Allocate memory for a new item at the end
    tmp = tmp->next;
  } else {
    // If the list is empty, allocate memory for the first item
    tmp = malloc(sizeof(Item));
    list->root = tmp;
  }
  tmp->id = pos;
  // Use the copy_str function to store a copy of the passed string
  int len = 0;
  while (str[len] != '\0') {
    len++;  //  length of the string
  }
  tmp->str = copy_str(str, len);  // Use the existing copy_str function from tokenizer.c
  tmp->next = NULL;
}

// Retrieve a history item by its ID
char *get_history(List *list, int id) {
  Item *tmp = list->root;

  // Traverse list to find matching ID node
  while (tmp != NULL) {
    if (tmp->id == id) {
      return tmp->str;  // return the matching id string
    }
    tmp = tmp->next;
  }
  return NULL;  //If no ID exists
}

// Print the entire history
void print_history(List *list) {
  if (list->root == NULL) {
    printf("History is empty, please enter some sentences.\n");
    return;
  }

  // Traverse list and print item's ID and string
  Item *tmp = list->root;
  while (tmp != NULL) {
    printf("%d: %s\n", tmp->id, tmp->str);
    tmp = tmp->next;  // move to the next item
  }
}

// Free the history list and the strings it references
void free_history(List *list) {
  Item *tmp;
  Item *head = list->root;

  // Traverse the list
  while (head != NULL) {
    tmp = head;
    head = head->next;
    free(tmp);  // free the current item
  }
  free(list);  // free the list
}
