
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
    
    if (head == NULL && head == NULL) {
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
        
    } else if (strcmp("setenv", cmd) == 0) {
        
        set_env(head);
        
    } else if (strcmp("unsetenv", cmd) == 0) {
        
        unset_env(head);
        
    }
    
}



void exit_cmd() {
    if (kill(getpid(), SIGINT) == -1) {
        exit(0);
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
    
    if (command_length != 0) {
        
        char *command = malloc(sizeof(char) * (command_length + 1));
        command[0] = '\0';
        temp = head->next;
        while (temp != NULL) {
            
            strcat(command, temp->word);
            if (temp->next != NULL) strcat(command, " ");
            temp = temp->next;
            
        }
        
        return command;
        
    } else return NULL;
    
    
}


int cd_cmd(list *head) {
    
    char *path = get_after_command(head);
     if (path == NULL || strlen(path) == 0) {
        char cwd[256];
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            int n = nbr_slash(cwd);
            int size = (n * 2) + n + 1;
            char *new_dir = (char *) malloc(sizeof(char) * size);
            for (int i = 0; i < size; i++) {
                new_dir[i] = '.';
                if (i % 3 == 0) new_dir[i]  = '/';
            }
            new_dir[size] = '\0';
            path = new_dir;
        } else {
            perror("getcwd");
        }
     }
     
    path[strcspn(path, "\n")] = 0;
    if (chdir(path) != 0) {
        
        perror("cd");
        return 1;
        
    }
    
    free(path);
    
    return 0;
    
}



void help_cmd(list *head) {
    
    char *command = get_after_command(head);
    char buffer[256];
    if (command == NULL) {
        snprintf(buffer, sizeof(buffer), "bash -c 'help'");
    } else 
        snprintf(buffer, sizeof(buffer), "bash -c 'help %s'", command);
    
    if (system(buffer) == -1) {
        perror("help");
    }
    
    free(command);
    
}



void set_env(list *head) {
    
    char *path = get_after_command(head);
    
    char *first_arg = strtok(path, " ");
    char *second_arg = strtok(NULL, " ");
    
    if (setenv(first_arg, second_arg, 1) != 0) {
        
        perror("setenv");
        
    }
    
}


void unset_env(list *head) {
    
    char *path = get_after_command(head);
    
    char *first_arg = strtok(path, " ");
    
    unsetenv(first_arg);
    
}



int nbr_slash(char *cwd) {
    
    int count = 0;
    int lenght = strlen(cwd);
    for (int i = 0; i < lenght; i++) {
        
        if (cwd[i] == '/') count++;
        
    }
    return count;
}














