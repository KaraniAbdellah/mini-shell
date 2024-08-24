#include <stdio.h>
#include "is_exit.h"
#include "../reading/read_tokenize.h"
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>


// handling the special character



// Check If The File Exit Or No
int is_file_exit(char *fileName) {
    
    struct stat fileStat;
    
    if (stat(fileName, &fileStat) == 0) {
        printf("The File Exit"); return 1;
    } else {
        printf("Does Not Exit"); return 0;
    }
    
}



// Check If This Is A Buit In Command
int is_buit_in_command(char *cmd) {
    
    char *cmds[5] = {"cd", "exit", "help", "echo", NULL};
    
    int i = 0;
    char *p = cmds[i];
    while (p != NULL) {
        
        if (strcmp(p, cmd) == 0) {
            // printf("%s: Built In Command\n", cmd);
            return 1;
        }
        
        i++;
        p = cmds[i];
        
    }
    
    return 0;
    
}




// Check If This Is A Executable In Command
int is_executable_in_command(char *cmd) {
    
    char *dirs[4] = {"/bin/", "/usr/bin/", "/sbin/", NULL};
    
    int i = 0;
    char *p = dirs[i];
    while (p != NULL) {
        
        char buffer[256];
        for (int i = 0; i < 256; i++) buffer[i] = '\0';
        strcat(buffer, dirs[i]);
        strcat(buffer, cmd);
        
        if (access(buffer, X_OK) == 0) {
            // printf("\n%s: is Executable Commad\n", cmd);
            return 1;
        }
        
        i++;
        p = dirs[i];
        
    }
    
    return 0;
    
}





int process_cmds(list *head) {
    
    // Check The Type Of Command
    char *cmd = head->word;
    if (is_executable_in_command(cmd)) {
        return 1;
    }
    else if(is_buit_in_command(cmd)) {
        return 2;
    }
    else {
        return 0;
    }
    
}














































































