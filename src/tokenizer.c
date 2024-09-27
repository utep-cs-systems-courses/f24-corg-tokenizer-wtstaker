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
  if(*str=='\0') // Return zero pointer if no more tokens
    return 0;
  
  while (*str != '\0'){     // && space_char(*str)) {
    str++;
  }
  return str;
}

// Returns pointer to the terminator char ater the token
char *token_terminator(char *token) {
  while ( non_space_char(*token)) {
    token++;
  }
  return token;
}

// Returns the number of tokes (words) in the string inputted
int count_tokens(char *str) {
  int count = 0;
  char *token = token_start(str);

  while (token != NULL) {
    count++;
    token = token_start(token_terminator(token));
  }
  return count;
}
