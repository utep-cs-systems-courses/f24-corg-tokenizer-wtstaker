#include <stdio.h>

int main(){
  char input[100];

 

  printf("$ ");
  fflush(stdout);

  if (fgets(input, sizeof(input), stdin) != NULL) {
    // Process the input here
    printf("You entered: %s", input);

  } else {
    printf("Error reading input.\n");
  }
  return(0);
}
