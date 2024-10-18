#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define MAX_INPUT_SIZE 1024

int find_newline(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            return i;
        }
        i++;
    }
    return i;  
}

// Display menu options to the user
void display_menu() {
    printf("\nMenu:\n");
    printf("t: Input a string to tokenize\n");
    printf("h: View history\n");
    printf("i: Lookup by history ID\n");
    printf("q: Quit\n");
    printf("Select an option: ");
}

// user interface
int main() {
    char input[MAX_INPUT_SIZE];
    List *history = init_history();
    char **tokens;
    char choice;

    printf("Simple Tokenizer with History.\n");

    while (1) {
        display_menu();
        // Get user input for the menu option
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Error reading input.\n");
            continue;
        }

        // Use the first character as the menu option
        choice = input[0];
        switch (choice) {
            case 't':
                // tokenize
                printf("Enter a string to tokenize: ");
                if (fgets(input, MAX_INPUT_SIZE, stdin) != NULL) {
                    int newline_pos = find_newline(input);
                    input[newline_pos] = '\0'; 

                    tokens = tokenize(input);
                    print_tokens(tokens);
                    add_history(history, input);
                    free_tokens(tokens);
                } else {
                    printf("Error reading input.\n");
                }
                break;

            case 'h':
                // View history
                printf("History:\n");
                print_history(history);
                break;

            case 'i':
                // Lookup by history ID
                printf("Enter history ID to recall: ");
                if (fgets(input, MAX_INPUT_SIZE, stdin) != NULL) {
                    int newline_pos = find_newline(input);
                    input[newline_pos] = '\0'; 

                    // Convert str to int
                    int history_id = strtol(input, NULL, 10);
                    char *history_entry = get_history(history, history_id);

                    if (history_entry != NULL) {
                        printf("history: %s\n", history_entry);
                        tokens = tokenize(history_entry);
                        print_tokens(tokens);
                        free_tokens(tokens);
                    } else {
                        printf("No history entry found for ID %d.\n", history_id);
                    }
                } else {
                    printf("Error reading input.\n");
                }
                break;
            case 'q':
                // Quit the program
                printf("Exiting\n");
                free_history(history);  // Free history before exiting
                return 0;
            default:
                printf("Invalid option. Please select a valid menu option.\n");
                break;
        }
    }
    return 0;
}
