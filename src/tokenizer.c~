#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"


// Returns true if c is a space or \t
int space_char(char c) {
  return c == ' ' || c == '\t';
}


// Returns true if c is non whitespace char
int non_space_char(char c) {
  return c != ' ' && c != '\t' && c != '\0';

}


// Returns pointer to first char in the line
char *token_start(char *str) {
  while (*str != '\0' && space_char(*str)) {
    str++;
  }
  if (*str == '\0') {
    return NULL;  // No more tokens
  }
  return str;
}

