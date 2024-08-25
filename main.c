#include "reading/read_tokenize.h"
#include "processing/is_exit.h"
#include <stdio.h>
#include "execution/execution_cmd/exec.h"
#include "execution/built_in_cmd/built.h"
#include "handling/handle.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>



int main() {
    
    
    
    


    
    
    // Reading Inputs && Store In List
    
    // printf("In Reading : ");
    // print_list(head);
    
    
    
    // Processing Input && Check The Avabilty Of The Commands
    // Executable Command Return 1 For Built In Command We Return 2 For Command Not Found We Return 0
    
    
    
    // printf("In Processing : \n");
    
    
    // printf("Show Handling The Result : ");
    // showTheResult(head);
    

    while (1) {
    
        pid_t pros = fork();
        
        if (pros == 0) {
        
            list *head = read_input();
            
            showTheResult(head);
            exit(0);
            
        } else if (pros > 0) wait(NULL);
        else perror("fork");
    
    }
    
    
    

    
    
    
    
    
    
    
    
    
    
    return 0;
}







