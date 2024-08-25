// write function for excution the executable commands

#include "../../reading/read_tokenize.h"
#include <stdio.h>
#include "exec.h"
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <stdlib.h>
#include <string.h>


void executable_cmd(list *head) {
    
    pid_t pros = fork();
    
    if (pros == 0) {
        
        list *temp = head;
        int nbr_words = get_nbr_words(head);
        char *args[nbr_words + 1];
        int i = 0;
        while (temp != NULL) {
            
            args[i] = (char *) malloc(sizeof(char));
            strcpy(args[i], temp->word);
            i++;
            temp = temp->next;
            
        }
        args[i] = NULL;
        execvp(head->word, args);
        
    } else if (pros > 0) wait(NULL);
    else perror("fork");

    
}




