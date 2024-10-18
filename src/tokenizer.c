#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

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
  char *token = token_start(str); //First word

  while (token != '\0') { // Loop until end of initial input
    count++;
    token = token_start(token_terminator(token)); // .Move token ptr to start of next token
  }
  return count;
}

// Returns pointer to a new string of original length
char *copy_str(char *inStr, short len) {
  
  char *newStr =malloc((len + 1) * sizeof(char)); // +1 for null terminator

  // if (newStr == NULL) {
  //  return NULL;  // memory fail
  // }

  for (int i = 0; i < len; i++) {
    newStr[i] = inStr[i];  // copying the string
  }
  
  newStr[len] = '\0';  // null terminator

  return newStr;
}
char **tokenize(char *str) {
  int tokenCount = count_tokens(str);
  char **tokens = (char **)malloc((tokenCount + 1) * sizeof(char *)); // memory allocation for tokens + null terminator
  
  //if (tokens == NULL) {
  //    return NULL;
  //}
  
  int i = 0;
  char *token = token_start(str); //Find first token

  // Loop until end of string
  while (token != NULL) {

    char *term = token_terminator(token); //Find end of token
    int len = term - token; //Length of token
    tokens[i] = copy_str(token, len);  // Copy each token

    i++;  // Move to next token
    token = token_start(term);  // Find next token
  }
  
  tokens[i] = NULL;
  return tokens;
}

// Prints all tokens
void print_tokens(char **tokens) {
  for (int i = 0; tokens[i] != NULL; i++) {
    printf("Token[%d]: %s\n", i, tokens[i]);
  }
}

// Frees all tokens
void free_tokens(char **tokens) {

  for (int i = 0; tokens[i] != NULL; i++) {
    free(tokens[i]);
  }
  free(tokens);
}
