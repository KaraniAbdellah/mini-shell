#include <stdio.h>
#include "read_tokenize.h"
#include <string.h>
#include <stdlib.h>






list *read_input() {
    
    list *head = NULL;
    char input[MAX_INPUT];
    printf("MY_SHELL$ ");
    scanf("%[^\n]", input);
    
    tokenize_input(input, &head);
    
    return head;
    
}



void insert_at_list(list **head, char *word) {
    
    list *new_node = (list *) malloc(sizeof(list));
    new_node->next = new_node->prev = NULL;
    strcpy(new_node->word, word);
    
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    
    list *temp = *head;
    while (temp->next != NULL) temp = temp->next;
    
    new_node->prev = temp;
    temp->next = new_node;
    
}



void tokenize_input(char *input, list **head) {
    
    char *token = strtok(input, " ");
    while (token != NULL) {
        insert_at_list(head, token);
        token = strtok(NULL, " ");
    }
    
}



void print_list(list *head) {
    
    list *temp = head;
    
    while(temp != NULL) {
        printf("%s --> ", temp->word);
        temp = temp->next;
    }
    
    printf("\n");
    
}




























