#include "../execution/execution_cmd/exec.h"
#include "../execution/built_in_cmd/built.h"
#include "../processing/is_exit.h"
#include "handle.h"
#include <stdio.h>



// this file also for generate error


// Start With First Command


void showTheResult(list *head) {
    
    int check = process_cmds(head->word);
    if (check == 1) {
    
        printf("%s: Executable Command\n", head->word);
        executable_cmd(head);
        
    } else if (check == 2) {
    
        printf("%s: Buit In Command\n", head->word);
        built_in_cmd(head);
        
    } else printf("%s: Command Not Found\n", head->word);
    
    
}











