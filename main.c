#include "reading/read_tokenize.h"
#include "processing/is_exit.h"
#include <stdio.h>


int main() {
    
    
    // Reading Inputs && Store In List
    list *head = read_input();
    printf("In Reading : ");
    print_list(head);
    
    // Processing Input && Check The Avabilty Of The Commands
    printf("In Processing : ");
    is_exit(head);
    
    
    
    return 0;
}

























