#include "../execution/execution_cmd/exec.h"
#include "../execution/built_in_cmd/built.h"
#include "../processing/is_exit.h"
#include "handle.h"
#include <stdio.h>
#include <unistd.h>
#include <wait.h>




// this file also for generate error


// Start With First Command


void showTheResult(list *head) {
    
    int check = process_cmds(head->word);
    if (check == 1) {
        
        executable_cmd(head);
        
    } else if (check == 2) {
        
        built_in_cmd(head);
        
    } else printf("%s: Command Not Found\n", head->word);
}




void fn(list *head) {
    
    showTheResult(head);
    
    list *new_head = read_input();
    
    if (new_head != NULL) fn(new_head);
    else return;
    
}














