#include "reading/read_tokenize.h"
#include "processing/is_exit.h"
#include <stdio.h>
#include "execution/execution_cmd/exec.h"
#include "execution/built_in_cmd/built.h"
#include "handling/handle.h"


int main() {
    
    
    // Reading Inputs && Store In List
    list *head = read_input();
    printf("In Reading : ");
    print_list(head);
    
    
    
    // Processing Input && Check The Avabilty Of The Commands
    // Executable Command Return 1 For Built In Command We Return 2 For Command Not Found We Return 0
    
    
    
    printf("In Processing : ");
    process_cmds(head);
    
    
    
    showTheResult(head);
    
    
    
    
    
    return 0;
}
















































