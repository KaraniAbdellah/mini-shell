
#include "../../reading/read_tokenize.h"
#include <stdio.h>
#include "built.h"
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>



void built_in_cmd(list *head) {
    
    if (head == NULL || head == NULL) {
        fprintf(stderr, "No command provided.\n");
        return;
    }
    
    char *cmd = head->word;
    
    if (strcmp("cd", cmd) == 0) {
        
        cd_cmd(head);
        
    } else if (strcmp("exit", cmd) == 0) {
        
        exit_cmd();
        
    } else if (strcmp("help", cmd) == 0) {
        
        help_cmd(head);
        
    } else  fprintf(stderr, "%s: Unknown built-in command.\n", cmd);
    
}



void exit_cmd() {
    if (kill(getppid(), SIGINT) == -1) {
        perror("kill");
    }
}


char *get_after_command(list *head) {
    
    if (head == NULL) return NULL;
    
    size_t command_length = 0;
    list *temp = head->next;
    while (temp != NULL) {
        command_length += strlen(temp->word) + 1;
        temp = temp->next;
    }
    
    char *command = malloc(sizeof(char) * command_length);
    command[0] = '\0';
    temp = head->next;
    while (temp != NULL) {
        
        strcat(command, temp->word);
        if (temp->next != NULL) strcat(command, " ");
        temp = temp->next;
        
    }
    
    
    return command;
    
}


int cd_cmd(list *head) {
    
    char *command = get_after_command(head);
     
     if (command == NULL && strlen(command) == 0) {
     
        fprintf(stderr, "cd: No path specified.\n");
        free(command);
        return 1;
        
     }
     
    command[strcspn(command, "\n")] = 0;
    if (chdir(command) != 0) {
        
        perror("cd");
        return 1;
        
    }
    
    char cwd[256];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Your Current Directry Is %s\n", cwd);
    } else {
        perror("getcwd");
    }
    
    free(command);
    
    return 0;
    
}



void help_cmd(list *head) {
    
    char *command = get_after_command(head);
    char buffer[256];
    if (command == NULL && strlen(command) != 0) {
        snprintf(buffer, sizeof(buffer), "bash -c 'help' %s", command);
    } else {
        snprintf(buffer, sizeof(buffer), "bash -c 'help'");
    }
    
    printf("command = %s and %ld and buffer = %s\n\n", command, strlen(command), buffer);
    if (system(buffer) == -1) {
        perror("help");
    }
    
    free(command);
    
}






















